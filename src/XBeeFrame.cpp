#include <XBeeFrame.hpp>

#include <iostream>

XBeeFrame::XBeeFrame(uint8_t API_ID){
	
	_length = XBEE_MIN_FRAME_LENGTH;
	_frameData = new XBeeFrameData(API_ID);
	_frame = new vector<uint8_t>();
	_checksum = 0xFF;
}

XBeeIdSpecificData* XBeeFrame::getCmdData(){

	return _frameData->getCmdData();
}

bool XBeeFrame::makeFrame(){

	if(_frame)
		_frame->clear();
	else
		_frame = new vector<uint8_t>;

	int i;
	_frame->push_back(XBEE_START_DELIMITER);
	_length = _frameData->length();// + XBEE_MIN_FRAME_LENGTH;
	//cout << "MAKE FRAME: length = " << _length << endl;
	for(i=1;i>=0;i--)
			_frame->push_back((_length & (0xFF << i*8)) >> i*8);
	vector<uint8_t> tmpData = _frameData->toBytes();
	_frame->insert(_frame->end(),tmpData.begin(),tmpData.end());
	_frame->push_back(checksum());

	//TODO: Verifier si toutes les variables prises en compte sont bien initialisées.
	return true;
}

vector<uint8_t> XBeeFrame::getFrame(){

	return *(_frame);
}

uint8_t XBeeFrame::getApiId(){
    
    return _frameData->getApiId();
}

uint8_t XBeeFrame::getFrameID(){

	return _frameData->getFrameID();
}

uint8_t XBeeFrame::checksum(){

	_checksum = 0xFF;
	unsigned int sum = 0;
	for(std::vector<uint8_t>::iterator j=(_frame->begin()+3);j!=_frame->end();++j)
	    sum += *j;
	_checksum = (uint8_t) (_checksum - sum);

	return _checksum;
}

std::ostream& operator<<(std::ostream& os, XBeeFrame& obj){

	unsigned int i;
	vector<uint8_t> tempFrame = obj.getFrame();
	for(i = 0; i < tempFrame.size(); i++){
		os << uppercase << std::hex << std::setw(2) << std::setfill('0') << tempFrame[i]+0;
	}
	return os;
}

std::stringstream& operator<<(std::stringstream& os, XBeeFrame& obj){

	unsigned int i;
	vector<uint8_t> tempFrame = obj.getFrame();
	for(i = 0; i < tempFrame.size(); i++){
		os << uppercase << std::hex << std::setw(2) << std::setfill('0') << tempFrame[i]+0;
	}
	return os;
}

bool XBeeFrame::loadFrame(const vector<uint8_t>& frame){

	//TODO: Verifier aussi le type de frame!
	if(frame[0] != XBEE_START_DELIMITER){
		cout << "Load Frame: Error in delimiter" << endl;
		return false;
	}
	else if((frame.size()-XBEE_MIN_FRAME_LENGTH) != (frame[1]*256+frame[2])){
		cout << "Load Frame: Error in Length" << endl;
		return false;
	}
	else if(!check2sum(frame)){
		cout << "Load Frame: Error in checksum" << endl;
		return false;
	}
	else{
		_length = frame[1]*256+frame[2];
		_checksum = frame[frame.size()-1];
		if(_frameData){
			delete _frameData;
		}
		_frameData = new XBeeFrameData(frame[3]);
		if(!_frameData->loadFrame(frame)){
			return false;
		}
		else{
			return true;
		}
	}
}

bool XBeeFrame::check2sum(const vector<uint8_t>& frame){

	uint8_t check2sum = 0xFF;
	vector<uint8_t> cpyFrame = frame;
	unsigned int sum = 0;
	for(std::vector<uint8_t>::iterator j=(cpyFrame.begin()+3);j!=(cpyFrame.end()-1);j++){
        sum += *j;   
        //cout << uppercase << std::hex << std::setw(2) << std::setfill('0') << sum+0 << endl;
    }
	check2sum = (uint8_t) (check2sum - sum);
    
	if(check2sum == frame[frame.size()-1])
		return true;
	else{
        cout << std::right << std::setw(XBEE_SETW_TXT) << std::setfill(' ') << "Checksum should be: "   \
				<< uppercase << std::hex << std::setw(2) << std::setfill('0') << check2sum+0 << endl;
        cout << std::right << std::setw(XBEE_SETW_TXT) << std::setfill(' ') << "But is: "               \
                << uppercase << std::hex << std::setw(2) << std::setfill('0') << frame[frame.size()-1]+0 << endl;
        return false;
    }
}

void XBeeFrame::debugFrame(){

	XBeeDebug::debugDec("Frame Length (octets) : ", _length,2);
	_frameData->debug();
}
