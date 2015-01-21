#include <XBeeModemSta.hpp>
#include <XBeeDebug.hpp>

#include <iostream>

XBeeModemSta::XBeeModemSta(){
	_specificData=0;
}

unsigned short XBeeModemSta::length(){
	return 1;
}

vector<uint8_t> XBeeModemSta::toBytes(){
	vector<uint8_t> res;
	res.push_back(_specificData);
	return res;
}


bool XBeeModemSta::loadFrame(const vector<uint8_t>& frame){
	_specificData = frame[4];
	return true;
}

void XBeeModemSta::debug(){

    XBeeDebug::debugMap(XBeeDebug::XBeeModemStatus,_specificData,false);
	cout << endl;
}
