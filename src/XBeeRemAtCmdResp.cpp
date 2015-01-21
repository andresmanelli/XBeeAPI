#include <XBeeRemAtCmdResp.hpp>
#include <XBeeDebug.hpp>

#include <iomanip>
#include <iostream>
#include <vector>

XBeeRemAtCmdResp::XBeeRemAtCmdResp(){
    _frameId = XBEE_DEFAULT_FRAME_ID;
    _atCmd = XBEE_DEFAULT_AT_CMD;
	_cmdStatus = XBEE_REM_AT_RESP_STATUS_ERROR;
    _sourceAddr = XBEE_DEFAULT_ADDR;
    _sourceMY = XBEE_DEFAULT_MY;
    _cmdData = new vector<uint8_t>();
}

unsigned short XBeeRemAtCmdResp::length(){
    
    return (14+_cmdData->size());
}


vector<uint8_t> XBeeRemAtCmdResp::toBytes(){

	vector<uint8_t> res;
	res.push_back(_frameId);
	int8_t i;
	//TODO: 64-bit Destination Addresse pourrait être une class avec la méthode "toBytes"
	for(i=7;i>=0;i--)
		res.push_back((_sourceAddr & ((uint64_t)0xFF << i*8)) >> i*8);
	for(i=1;i>=0;i--)
		res.push_back((_sourceMY & (0xFF << i*8)) >> i*8);
	for(i=1;i>=0;i--)
		res.push_back((_atCmd & (0xFF << i*8)) >> i*8);
	res.push_back(_cmdStatus);
	res.insert(res.end(),_cmdData->begin(),_cmdData->end());

	return res;
}

bool XBeeRemAtCmdResp::loadFrame(const vector<uint8_t>& frame){

    _frameId = frame[4];
    unsigned short i;
    _sourceAddr = 0;
	for(i=0;i<8;i++)
		_sourceAddr += ((uint64_t)frame[i+5] << (7-i)*8);
	_sourceMY = 0;
	for(i=0;i<2;i++)
		_sourceMY += (frame[i+13] << (1-i)*8);
	_atCmd = 0;
	for(i=0;i<2;i++)
		_atCmd += (frame[i+15] << (1-i)*8);
    _cmdStatus  = frame[17];
	if(!_cmdData->empty())
        _cmdData->clear();
    _cmdData->insert(_cmdData->begin(),frame.begin()+18,frame.end()-1);

	return true;
}

void XBeeRemAtCmdResp::debug(){

	XBeeDebug::debugHex("Frame ID : ", _frameId,1);
    XBeeDebug::debugAddr("Source Address : ", _sourceAddr);
    XBeeDebug::debugMy("Source MY : ", _sourceMY);
    XBeeDebug::debugMap(XBeeDebug::XBeeAtCmd,_atCmd,false);
    XBeeDebug::debugMap(XBeeDebug::XBeeRemAtCmdRespStatus,_cmdStatus,false);
    XBeeDebug::debugHex("Command Data : ", _cmdData);
	cout << endl;
}
