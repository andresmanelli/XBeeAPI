#include <XBeeFIFO.hpp>

XBeeFIFO::XBeeFIFO(){

	uint8_t i;
	for(i=0;i<255;i++)
		_dispIDs.push(255-i);
}

uint8_t XBeeFIFO::getNextID(){

	if(_dispIDs.size()>0){
		uint8_t id = _dispIDs.front();
		_dispIDs.pop();
		_usedIDs.push_back(id);
		return id;
	}
	return 0;
}

uint8_t XBeeFIFO::setFreeID(uint8_t id){

	vector<uint8_t>::iterator i;
	for(i = _usedIDs.begin(); i!=_usedIDs.end(); i++){
		if(*i==id){
			_usedIDs.erase(i);
			_dispIDs.push(id);
			return id;
		}
	}
	return 0;
}

action XBeeFIFO::matchFrame(XBeeFrame* frame, XBEE_PEND_FRAME* match){

	if (frame->getApiId()==XBEE_RECEIVE_PACKET){
		vector<XBEE_PEND_FRAME>::iterator i;
		for(i = _pendingFrames.begin(); i!=_pendingFrames.end();i++)
			if((i->ADDR == ((XBeeReceivePacket*)frame->getCmdData())->getSourceAddr()) && (i->API_ID == frame->getApiId())){
				action a= i->ACTION;
				*match=*i;
				_pendingFrames.erase(i);
				return a;
			}
		return NULL;
	}
	vector<XBEE_PEND_FRAME>::iterator i;
	for(i = _pendingFrames.begin(); i!=_pendingFrames.end();i++)
		if((i->ID_resp == frame->getFrameID()) && (i->API_ID == frame->getApiId())){
			action a= i->ACTION;
			*match=*i;
			_pendingFrames.erase(i);
			return a;
		}
	return NULL;
}

uint8_t XBeeFIFO::registerPendingFrame(uint8_t id, uint8_t id_resp, string capteur,uint64_t addr, uint8_t api_id, action a){

	_pendingFrames.push_back({id, id_resp, capteur, addr,api_id, a});
	return 0;
}
