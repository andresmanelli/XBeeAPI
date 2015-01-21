#include <XBeeRemAtCmd.hpp>
#include <iostream>

#include <XBeeDebug.hpp>

XBeeRemAtCmd::XBeeRemAtCmd(){
	_frameId = XBEE_DEFAULT_FRAME_ID;
	_destAddr = XBEE_BROADCAST_ADDR;
	_destMY = XBEE_DEFAULT_MY;
	_atCmd = XBEE_DEFAULT_AT_CMD;
	_remCmdOpts = XBEE_NO_OPTS;
	_paramValue = new vector<uint8_t>();
}

unsigned short XBeeRemAtCmd::length(){

	return (14+_paramValue->size());
}

vector<uint8_t> XBeeRemAtCmd::toBytes(){

	vector<uint8_t> res;
	res.push_back(_frameId);
	int8_t i;
	//TODO: 64-bit Destination Addresse pourrait être une class avec la méthode "toBytes"
	for(i=7;i>=0;i--)
		res.push_back((_destAddr & ((uint64_t)0xFF << i*8)) >> i*8);
	for(i=1;i>=0;i--)
		res.push_back((_destMY & (0xFF << i*8)) >> i*8);
	res.push_back(_remCmdOpts);
	for(i=1;i>=0;i--)
			res.push_back((_atCmd & (0xFF << i*8)) >> i*8);
	res.insert(res.end(),_paramValue->begin(),_paramValue->end());

	return res;
}

bool XBeeRemAtCmd::setFrameId(uint8_t frameId){

	_frameId = frameId;
	return true;
}

bool XBeeRemAtCmd::setDestAddr(uint64_t destAddr){

	_destAddr = destAddr;
	return true;
}

bool XBeeRemAtCmd::setDestMY(uint16_t destMY){

	_destMY = destMY;
	return true;
}

bool XBeeRemAtCmd::setAtCmd(uint16_t atCmd){

	_atCmd = atCmd;
	return true;
}

bool XBeeRemAtCmd::setRemCmdOpts(uint8_t options){

	if(options <= 99){
		_remCmdOpts = options;
		return true;
	}
	else
		return false;
}

bool XBeeRemAtCmd::setParamValue(const vector<uint8_t>& paramValue){

	//TODO: verifier si paramValue respect la taille définite dans la doc de zigbee
	//por ahi en vez de un define, hacer una estructura que ya tenga el rango valido junto con el comando?
	//if(paramValue.size() <= ){
	if(_paramValue){
		_paramValue->clear();
	}
	else{
		_paramValue = new vector<uint8_t>();
	}
	(*_paramValue) = paramValue;

	return true;
}

bool XBeeRemAtCmd::setParamValue(const string& paramValue, bool set0){

	//TODO: verifier si paramValue respect la taille définite dans la doc de zigbee
	//por ahi en vez de un define, hacer una estructura que ya tenga el rango valido junto con el comando?
	if(_paramValue){
		_paramValue->clear();
	}
	else{
		_paramValue = new vector<uint8_t>();
	}

	unsigned int i;
	for(i=0; i<paramValue.length(); i++)
		_paramValue->push_back(paramValue[i]);
	if(set0)
		_paramValue->push_back(0);

	return true;
}

bool XBeeRemAtCmd::loadFrame(const vector<uint8_t>& frame){

    _frameId = frame[4];
    unsigned short i;
    _destAddr = 0;
	for(i=0;i<8;i++)
		_destAddr += ((uint64_t)frame[i+5] << (7-i)*8);
	_destMY = 0;
	for(i=0;i<2;i++)
		_destMY += (frame[i+13] << (1-i)*8);
	_remCmdOpts = frame[15];
	_atCmd = 0;
	for(i=0;i<2;i++)
		_atCmd += (frame[i+16] << (1-i)*8);
	if(!_paramValue->empty())
        _paramValue->clear();
    _paramValue->insert(_paramValue->begin(),frame.begin()+18,frame.end()-1);

	return true;
}

void XBeeRemAtCmd::debug(){

	XBeeDebug::debugHex("Frame ID : ", _frameId,1);
    XBeeDebug::debugAddr("Destination Address : ", _destAddr);
    XBeeDebug::debugMy("Destination MY : ", _destMY);
    XBeeDebug::debugMap(XBeeDebug::XBeeRemAtCmdOpts,_remCmdOpts,true);
    XBeeDebug::debugMap(XBeeDebug::XBeeAtCmd,_atCmd,false);
    XBeeDebug::debugHex("Command Parameter : ", _paramValue);
	cout << endl;
}
