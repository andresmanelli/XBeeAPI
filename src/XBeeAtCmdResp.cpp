#include <XBeeAtCmdResp.hpp>

#include <iostream>

#include "XBeeDebug.hpp"

XBeeAtCmdResp::XBeeAtCmdResp(){
	_status = XBEE_AT_RESP_STATUS_ERR;
}

vector<uint8_t> XBeeAtCmdResp::toBytes(){

	vector<uint8_t> res;
	res.push_back(_frameId);
	int8_t i;
	for(i=1;i>=0;i--)
		res.push_back((_atCmd & (0xFF << i*8)) >> i*8);
	res.push_back(_status);
	res.insert(res.end(),_paramValue->begin(),_paramValue->end());

	return res;
}

bool XBeeAtCmdResp::setStatus(uint8_t status){

	if(status > 0x01)
		return false;
	else{
		_status = status;
		return true;
	}
}

bool XBeeAtCmdResp::loadFrame(const vector<uint8_t>& frame){

    _frameId = frame[4];
    _atCmd = 0;
	unsigned short i;
    for(i=0;i<2;i++)
		_atCmd += (frame[i+5] << (1-i)*8);
    _status = frame[7];
	if(_paramValue->size() != 0)
        _paramValue->clear();
    _paramValue->insert(_paramValue->begin(),frame.begin()+8,frame.end()-1);
	if (!evaluateFrame())
		return false;
	return true;
}

bool XBeeAtCmdResp::evaluateFrame(void){
	switch (_atCmd){
		case XBEE_AT_CMD_ND:{
			unsigned short i;
			
			_sourceMY = 0;
			for(i=0;i<2;i++)
				_sourceMY += (_paramValue->at(i) << (1-i)*8);
				
			_sourceAddr = 0;
			for(i=0;i<8;i++){
				_sourceAddr += ((uint64_t)_paramValue->at(i+2) << (7-i)*8);
			}
			
			i = 0;
			while (_paramValue->at(i+10)!=0)
				i++;
				
			unsigned short length = i;
			_nom = "";
			for(i=0;i<length;i++)
				_nom+=_paramValue->at(i+10);
			length+=11;
			
			_parentMY = 0;
			for(i=0;i<2;i++)
				_parentMY += (_paramValue->at(i+length) << (1-i)*8);
				
			_deviceType = _paramValue->at(length+2);
			
			_statusR = _paramValue->at(length+3);
			
			_profileId = 0;
			for(i=0;i<2;i++)
				_profileId += (_paramValue->at(i+length+4) << (1-i)*8);
			
			_manufacturerId = 0;
			for(i=0;i<2;i++)
				_manufacturerId += (_paramValue->at(i+length+6) << (1-i)*8);			
		}
	}
	return true;
}

void XBeeAtCmdResp::debug(){

	XBeeDebug::debugHex("Frame ID : ",_frameId,1);
    XBeeDebug::debugMap(XBeeDebug::XBeeAtCmd,_atCmd,false);
    XBeeDebug::debugMap(XBeeDebug::XBeeAtCmdRespStatus,_status,false);
    XBeeDebug::debugHex("Value : ",_paramValue);
    if (_atCmd == XBEE_AT_CMD_ND){
		XBeeDebug::debugMy("Source My : ",_sourceMY);
		XBeeDebug::debugAddr("Source Addr : ",_sourceAddr);
		XBeeDebug::debugStr("Name : ",_nom);
		XBeeDebug::debugMy("Parent My : ",_parentMY);
		XBeeDebug::debugMap(XBeeDebug::XBeeDevType,_deviceType & 0x00FF,false);
		XBeeDebug::debugMap(XBeeDebug::XBeeAtCmdRespStatus,_statusR  & 0x00FF,false);
		XBeeDebug::debugHex("Profile ID : ",(uint64_t)_profileId,2);
		XBeeDebug::debugHex("Manufacturer ID : ",(uint64_t)_manufacturerId,2);
	}
	cout << endl;
}
