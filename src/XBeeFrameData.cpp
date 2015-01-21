#include <XBeeFrameData.hpp>
//TODO: BORRAR DESPUES CUANDO ANDE BIEN
#include <iostream>
#include <iomanip>

XBeeFrameData::XBeeFrameData(uint8_t API_ID){
	
	_apiID = API_ID;
	
	switch(API_ID){
		case XBEE_TR_REQ_FRAME:
			_cmdData = new XBeeTrReq();
			break;
		case XBEE_AT_CMD_FRAME:
			_cmdData = new XBeeAtCmd();
			break;
		case XBEE_AT_CMD_RESP_FRAME:
			_cmdData = new XBeeAtCmdResp();
			break;
		case XBEE_REM_AT_CMD_FRAME:
			_cmdData = new XBeeRemAtCmd();
			break;
		case XBEE_REM_AT_CMD_RESP_FRAME:
			_cmdData = new XBeeRemAtCmdResp();
			break;
		case XBEE_ND_ID_INDICATOR:
			_cmdData = new XBeeNdIdIndicator();
			break;
		case XBEE_RECEIVE_PACKET:
			_cmdData = new XBeeReceivePacket();
			break;
		case XBEE_TR_STATUS_FRAME:
			_cmdData = new XBeeTrSta();
			break;
		case XBEE_MODEM_STATUS_FRAME:
			_cmdData = new XBeeModemSta();
			break;
		default:
			_cmdData = NULL;
			cout << "IL MANQUE LA DEFINITION DE CETTE TRAME!! API ID : " << API_ID+0 << endl;
			break;
	}
}

XBeeIdSpecificData* XBeeFrameData::getCmdData(){
	
		return _cmdData;
}

unsigned short XBeeFrameData::length(){

	//cout << "FRAME DATA LENGTH(): length = " << _cmdData->length() << endl;
	return _cmdData->length()+1;
}

uint8_t XBeeFrameData::getFrameID(){

	return _cmdData->getFrameID();
}

vector<uint8_t> XBeeFrameData::toBytes(){

	vector<uint8_t> res;
	res.push_back(_apiID);
	vector<uint8_t> tmpData = _cmdData->toBytes();
	res.insert(res.end(),tmpData.begin(),tmpData.end());

	return res;
}

bool XBeeFrameData::loadFrame(const vector<uint8_t>& frame){

	if (_cmdData==NULL)
		return false;
	_apiID = frame[3];
	if  (XBeeDebug::searchMap(XBeeDebug::XBeeApiIds,_apiID))
		return _cmdData->loadFrame(frame);
	return false;
}

void XBeeFrameData::debug(){

    XBeeDebug::debugMap(XBeeDebug::XBeeApiIds,_apiID,false);
	_cmdData->debug();
}

uint8_t XBeeFrameData::getApiId(){
    
    return _apiID;
}
