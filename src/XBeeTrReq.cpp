#include <XBeeTrReq.hpp>
#include <XBeeDebug.hpp>

#include <iostream>

XBeeTrReq::XBeeTrReq(){
	_frameId = XBEE_DEFAULT_FRAME_ID;
	_destAddr = XBEE_BROADCAST_ADDR;
	_destMY = XBEE_DEFAULT_MY;
	_broadcastR = XBEE_DEFAULT_BCST_RADIUS;
	_options = XBEE_OPTS_ACK_ENABLED|XBEE_OPTS_NET_ADD_DISCOVERY_EN;
	_rfData = new vector<uint8_t>();
}

vector<uint8_t> XBeeTrReq::getRfData(){

	return *_rfData;
}

unsigned short XBeeTrReq::length(){

	return (13+ _rfData->size());
}

vector<uint8_t> XBeeTrReq::toBytes(){

	vector<uint8_t> res;
	res.push_back(_frameId);
	int8_t i;
	//TODO: 64-bit Destination Addresse pourrait être une class avec la méthode "toBytes"
	for(i=7;i>=0;i--)
		res.push_back((_destAddr & ((uint64_t)0xFF << i*8)) >> i*8);
	for(i=1;i>=0;i--)
		res.push_back((_destMY & (0xFF << i*8)) >> i*8);
	res.push_back(_broadcastR);
	res.push_back(_options);
	res.insert(res.end(),_rfData->begin(),_rfData->end());

	return res;
}

bool XBeeTrReq::setFrameId(uint8_t frameId){

	_frameId = frameId;
	return true;
}

bool XBeeTrReq::setDestAddr(uint64_t destAddr){

	_destAddr = destAddr;
	return true;
}

bool XBeeTrReq::setDestMY(uint16_t destMY){

	_destMY = destMY;
	return true;
}

bool XBeeTrReq::setBroadcastR(uint8_t broadcastR){

	if(broadcastR <= 10){
		_broadcastR = broadcastR;
		return true;
	}
	else
		return false;
}

bool XBeeTrReq::setOptions(uint8_t options){

	if(options <= 3){
		_options = options;
		return true;
	}
	else
		return false;
}

bool XBeeTrReq::setRfData(const vector<uint8_t>& rfData){

	if(rfData.size() <= XBEE_MAX_LENGTH_RF_DATA){
		if(_rfData){
			_rfData->clear();
		}
		else{
			_rfData = new vector<uint8_t>();
		}
		(*_rfData) = rfData;

		return true;
	}
	else
		return false;
}

bool XBeeTrReq::loadFrame(const vector<uint8_t>& frame){

    _frameId = frame[4];
	_destAddr = 0;
    unsigned short i;
	for(i=0;i<8;i++)
		_destAddr += ((uint64_t)frame[i+5] << (7-i)*8);
	_destMY = 0;
	for(i=0;i<2;i++)
		_destMY += (frame[i+13] << (1-i)*8);
    _broadcastR = frame[15];
	_options = frame[16];
	_rfData->insert(_rfData->begin(),frame.begin()+18,frame.end()-1);
    
	return true;
}

void XBeeTrReq::debug(){

	XBeeDebug::debugHex("Frame ID : ", _frameId,1);
    XBeeDebug::debugAddr("Destination Address : ", _destAddr);
    XBeeDebug::debugMy("Destination MY : ", _destMY);
    XBeeDebug::debugDec("Broadcast Radius (base 10) : ",_broadcastR,1);
    XBeeDebug::debugMap(XBeeDebug::XBeeTrReqOpts,_options,true);
    XBeeDebug::debugHex("RF Data : ", _rfData);
	cout << endl;
}
