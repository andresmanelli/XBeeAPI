#include <XBeeNdIdIndicator.hpp>

#include <iostream>
#include <iomanip>

XBeeNdIdIndicator::XBeeNdIdIndicator(){

	_senderAddr = XBEE_DEFAULT_ADDR;
	_senderMY = XBEE_DEFAULT_MY;
	// Not a valid option here!
	_options = XBEE_NO_OPTS;
	_sourceMY = XBEE_DEFAULT_MY;
	_sourceAddr = XBEE_DEFAULT_ADDR;
	// To indicate it's not a final frame
	_niString = new vector<uint8_t>();
	_niString->push_back('N');
	_niString->push_back('U');
	_niString->push_back('L');
	_niString->push_back('L');
	_niString->push_back(0);

	_parentMY = XBEE_DEFAULT_MY;
	_devType = XBEE_END_DEV;
	_srcEvent = XBEE_PWR_CYCLE_EVT;
	_appProfileID = XBEE_DIGI_APP_ID;
	_manufacturerID = XBEE_DIGI_MANUF_ID;
}

unsigned short XBeeNdIdIndicator::length(){

	//cout << "NDID length(): length = " << _niString->size() << endl;
	return (29+_niString->size());
}

vector<uint8_t> XBeeNdIdIndicator::toBytes(){

	vector<uint8_t> res;
	int8_t i;
	//TODO: 64-bit Destination Addresse pourrait être une class avec la méthode "toBytes"
	for(i=7;i>=0;i--){
		res.push_back((_senderAddr & ((uint64_t)0xFF << i*8)) >> i*8);
	}
	for(i=1;i>=0;i--)
		res.push_back((_senderMY & (0xFF << i*8)) >> i*8);
	res.push_back(_options);
	for(i=1;i>=0;i--)
			res.push_back((_sourceMY & (0xFF << i*8)) >> i*8);
	for(i=7;i>=0;i--)
			res.push_back((_sourceAddr & ((uint64_t)0xFF << i*8)) >> i*8);
	res.insert(res.end(),_niString->begin(),_niString->end());
	for(i=1;i>=0;i--)
			res.push_back((_parentMY & (0xFF << i*8)) >> i*8);
	res.push_back(_devType);
	res.push_back(_srcEvent);
	for(i=1;i>=0;i--)
				res.push_back((_appProfileID & (0xFF << i*8)) >> i*8);
	for(i=1;i>=0;i--)
			res.push_back((_manufacturerID & (0xFF << i*8)) >> i*8);

	return res;
}

bool XBeeNdIdIndicator::setSenderAddr(uint64_t senderAddr){

	_senderAddr = senderAddr;
	return true;
}

bool XBeeNdIdIndicator::setSenderMY(uint16_t senderMY){

	_senderMY = senderMY;
	return true;
}

bool XBeeNdIdIndicator::setSourceAddr(uint64_t sourceAddr){

	_sourceAddr = sourceAddr;
	return true;
}

bool XBeeNdIdIndicator::setSourceMY(uint16_t sourceMY){

	_sourceMY = sourceMY;
	return true;
}

bool XBeeNdIdIndicator::setParentMY(uint16_t parentMY){

	_parentMY = parentMY;
	return true;
}

bool XBeeNdIdIndicator::setOptions(uint8_t options){

	if(options > 0x63)
		return false;

	_options = options;
	return true;
}

bool XBeeNdIdIndicator::setNIString(vector<uint8_t> ni){

	if(_niString)
		_niString = new vector<uint8_t>();
	else
		_niString->clear();

	(*_niString) = ni;
	return true;
}

bool XBeeNdIdIndicator::setDeviceType(uint8_t devType){

	if(devType > XBEE_END_DEV)
		return false;

	_devType = devType;
	return true;
}

bool XBeeNdIdIndicator::setSourceEvent(uint8_t srcEvent){

	if(srcEvent > XBEE_PWR_CYCLE_EVT)
		return false;

	_srcEvent = srcEvent;
	return true;
}

bool XBeeNdIdIndicator::setAppProfileID(uint16_t id){

	_appProfileID = id;
	return true;
}

bool XBeeNdIdIndicator::setManufacturerID(uint16_t id){

	_manufacturerID = id;
	return true;
}

uint64_t XBeeNdIdIndicator::getSenderAddr(){

	return _senderAddr;
}

uint16_t XBeeNdIdIndicator::getSenderMY(){

	return _senderMY;
}

string XBeeNdIdIndicator::getNIString(){

	string res;
	unsigned int i;
	for(i=0; i<_niString->size(); i++)
		res.push_back((*_niString)[i]);
	return res;
}

bool XBeeNdIdIndicator::loadFrame(const vector<uint8_t>& frame){

	_senderAddr = 0;
	unsigned short i;
	for(i=0;i<8;i++){
		//cout << "load Frame: sender addr " << uppercase << std::hex << std::setw(16) << std::setfill('0') << _senderAddr << endl;
		//cout << "load Frame: byte " << uppercase << std::hex << std::setw(16) << std::setfill('0') << ((uint64_t)frame[i+4] << (7-i)*8) << endl;
		_senderAddr += ((uint64_t)frame[i+4] << (7-i)*8);
	}
	//cout << "load Frame: sender addr " << uppercase << std::hex << std::setw(16) << std::setfill('0') << _senderAddr << endl;
	_senderMY = 0;
	for(i=0;i<2;i++)
		_senderMY += (frame[i+12] << (1-i)*8);
	_options = frame[14];
	_sourceMY = 0;
	for(i=0;i<2;i++)
		_sourceMY += (frame[i+15] << (1-i)*8);
	_sourceAddr = 0;
	for(i=0;i<8;i++)
		_sourceAddr += ((uint64_t)frame[i+17] << (7-i)*8);
	uint16_t niLength = (frame[1]*256+frame[2]) - 30;
	if(_niString->size() != 0)
		_niString->clear();
	//cout << "LOAD FRAME: Frame Size: " << (frame[1]*256+frame[2]) << endl;
	//cout << "            NI size: " << niLength << endl;
	for(i=0;i<niLength;i++){
		//cout << "Loading Ni: char = " << frame[i+25] << endl;
		_niString->push_back(frame[i+25]);
	}
	_parentMY = 0;
	for(i=0;i<2;i++)
		_parentMY += (frame[i+25+niLength] << (1-i)*8);
	_devType = frame[27+niLength];
	//cout << "LOAD FRAME _devType " << uppercase << std::hex << std::setw(2) << std::setfill('0') << frame[i+27] << endl;
	_srcEvent = frame[28+niLength];
	//cout << "LOAD FRAME _srcEvent " << uppercase << std::hex << std::setw(2) << std::setfill('0') << _srcEvent << endl;
	_appProfileID = 0;
	for(i=0;i<2;i++)
		_appProfileID += (frame[i+29+niLength] << (1-i)*8);
	_manufacturerID = 0;
	for(i=0;i<2;i++)
		_manufacturerID += (frame[i+31+niLength] << (1-i)*8);

	return true;
}

void XBeeNdIdIndicator::debug(){

    XBeeDebug::debugAddr("Sender Address : ", _senderAddr);
    XBeeDebug::debugMy("Sender MY : ", _senderMY);
    XBeeDebug::debugMap(XBeeDebug::XBeeNIIRecOpts,_options,true);
    XBeeDebug::debugMy("Source MY : ", _sourceMY);
    XBeeDebug::debugAddr("Source Address : ", _sourceAddr);
	XBeeDebug::debugStr("NI String : ",getNIString());
    XBeeDebug::debugMy("Parent MY : ", _parentMY);
    XBeeDebug::debugMap(XBeeDebug::XBeeDevType, _devType,false);   
    XBeeDebug::debugMap(XBeeDebug::XBeeSrcEvt, _srcEvent,false);
    XBeeDebug::debugHex("Application Profile ID : ",_appProfileID,2);	
    XBeeDebug::debugHex("Manufacturer ID : ",_manufacturerID,2);
	cout << endl;
}

