#include <XBeeAtCmd.hpp>

#include <iostream>
#include <stdlib.h>

#include <XBeeDebug.hpp>

XBeeAtCmd::XBeeAtCmd(){

	_frameId = XBEE_DEFAULT_FRAME_ID;
	_atCmd = XBEE_DEFAULT_AT_CMD;
	_paramValue = new vector<uint8_t>();
}

vector<uint8_t> XBeeAtCmd::getParamValue(){

	return *(_paramValue);
}

unsigned short XBeeAtCmd::length(){

	//TODO: VERIFIER, C'EST PAS BIEN
	//On soustrait parce que le champ "length" de ce type de frame
	//ne prend en compte que la trame AT
	return (3+_paramValue->size());//-XBEE_MIN_FRAME_LENGTH);
}

vector<uint8_t> XBeeAtCmd::toBytes(){

	vector<uint8_t> res;
	res.push_back(_frameId);
	int8_t i;
	for(i=1;i>=0;i--)
		res.push_back((_atCmd & (0xFF << i*8)) >> i*8);
	res.insert(res.end(),_paramValue->begin(),_paramValue->end());

	return res;
}

bool XBeeAtCmd::setFrameId(uint8_t frameId){

	_frameId = frameId;
	return true;
}

uint8_t XBeeAtCmd::getFrameID(){

	return _frameId;
}

bool XBeeAtCmd::setAtCmd(uint16_t atCmd){

	_atCmd = atCmd;
	return true;
}

bool XBeeAtCmd::setParamValue(const vector<uint8_t>& paramValue){

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

bool XBeeAtCmd::setParamValue(const string& paramValue, bool set0){

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

bool XBeeAtCmd::loadFrame(const vector<uint8_t>& frame){

    _frameId = frame[4];
    _atCmd = 0;
	unsigned short i;
    for(i=0;i<2;i++)
		_atCmd += (frame[i+5] << (1-i)*8);
    
	if(_paramValue->size() != 0)
        _paramValue->clear();
    _paramValue->insert(_paramValue->begin(),frame.begin()+7,frame.end()-1);
	
	return true;
}

void XBeeAtCmd::debug(){

	XBeeDebug::debugHex("Frame ID : ",_frameId,1);
    XBeeDebug::debugMap(XBeeDebug::XBeeAtCmd,_atCmd,false);
    XBeeDebug::debugHex("Parameter Value : ",_paramValue);
	cout << endl;
}
