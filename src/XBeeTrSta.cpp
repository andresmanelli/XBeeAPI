#include <XBeeTrSta.hpp>
#include <XBeeDebug.hpp>

#include <iostream>

XBeeTrSta::XBeeTrSta(){
	_frameId = XBEE_DEFAULT_FRAME_ID;
	_sourceMy = XBEE_DEFAULT_MY;
	_trRetryCount = 0;
	_delivStatus = 0;
	_discovStatus = 0;
}

unsigned short XBeeTrSta::length(){

	return 6;
}

vector<uint8_t> XBeeTrSta::toBytes(){

	vector<uint8_t> res;
	res.push_back(_frameId);
	int8_t i;
	//TODO: 64-bit Destination Addresse pourrait être une class avec la méthode "toBytes"
	for(i=1;i>=0;i--)
		res.push_back((_sourceMy & (0xFF << i*8)) >> i*8);
	res.push_back(_trRetryCount);
	res.push_back(_delivStatus);
	res.push_back(_discovStatus);

	return res;
}


bool XBeeTrSta::loadFrame(const vector<uint8_t>& frame){
	
	_frameId = frame[4];
	_sourceMy = 0;
	unsigned short i;
	_sourceMy = 0;
	for(i=0;i<2;i++)
		_sourceMy += (frame[i+5] << (1-i)*8);

	_trRetryCount = frame[7];
	_delivStatus = frame[8];
	_discovStatus = frame[9];

	return true;
}

uint8_t XBeeTrSta::getTrStatus() {

	return _delivStatus;
}

void XBeeTrSta::debug(){

	XBeeDebug::debugHex("Frame ID : ", _frameId,1);
    XBeeDebug::debugMy("Source MY : ", _sourceMy);
    XBeeDebug::debugDec("Transmit Retry Count : ",_trRetryCount,1);
    XBeeDebug::debugMap(XBeeDebug::XBeeTrDelStatus,_delivStatus,false);
    XBeeDebug::debugMap(XBeeDebug::XBeeTrDiscovStatus,_discovStatus,false);
	cout << endl;
}
