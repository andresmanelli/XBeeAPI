#include <XBeeReceivePacket.hpp>

#include <iomanip>
#include <iostream>

XBeeReceivePacket::XBeeReceivePacket(){
	_sourceAddr = XBEE_DEFAULT_ADDR;
	_sourceMY = XBEE_DEFAULT_MY;
	_options = XBEE_RPACKET_ACK;
	_rfData = new vector<uint8_t>();
}

vector<uint8_t> XBeeReceivePacket::getRfData(){

	return *_rfData;
}

unsigned short XBeeReceivePacket::length(){

	return (11+ _rfData->size());
}

vector<uint8_t> XBeeReceivePacket::toBytes(){

	vector<uint8_t> res;
	int8_t i;
	//TODO: 64-bit Destination Addresse pourrait être une class avec la méthode "toBytes"
	for(i=7;i>=0;i--)
		res.push_back((_sourceAddr & ((uint64_t)0xFF << i*8)) >> i*8);
	for(i=1;i>=0;i--)
		res.push_back((_sourceMY & (0xFF << i*8)) >> i*8);
	res.push_back(_options);
	res.insert(res.end(),_rfData->begin(),_rfData->end());

	return res;
}

bool XBeeReceivePacket::loadFrame(const vector<uint8_t>& frame){

	_sourceAddr = 0;
	unsigned short i;
	for(i=0;i<8;i++){
		_sourceAddr += ((uint64_t)frame[i+4] << (7-i)*8);
	}
	_sourceMY = 0;
	for(i=0;i<2;i++)
		_sourceMY += (frame[i+12] << (1-i)*8);

	_options = frame[14];

	uint16_t length = (frame[1]*256+frame[2]) - 12;

	if(_rfData->size() != 0)
		_rfData->clear();
	for(i=0;i<length;i++){
		_rfData->push_back(frame[i+15]);
	}

	return true;
}

uint64_t XBeeReceivePacket::getSourceAddr(){

	return _sourceAddr;
}

uint16_t XBeeReceivePacket::getSourceMY(){

	return _sourceMY;
}

void XBeeReceivePacket::debug(){

	XBeeDebug::debugAddr("Source Address : ", _sourceAddr);
    XBeeDebug::debugMy("Source MY : ", _sourceMY);
	XBeeDebug::debugMap(XBeeDebug::XBeeRRecOpts,_options,false);
	XBeeDebug::debugHex("RF Data : ", _rfData);
	cout << endl;
}
