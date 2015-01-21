#include <XBeeDebug.hpp>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>

using namespace std;

XBEE_DEBUG_PAIR XBeeDebug::_dataApiIds[] = {
        XBEE_DEBUG_PAIR(XBEE_MAP_TITLE_KEY, "Frame Type : "),
		XBEE_DEBUG_PAIR(XBEE_RECEIVE_PACKET, "ZigBee Receive Packet"),
		XBEE_DEBUG_PAIR(XBEE_TR_REQ_FRAME, "ZigBee Transmit Request"),
		XBEE_DEBUG_PAIR(XBEE_AT_CMD_FRAME, "AT Command"),
		XBEE_DEBUG_PAIR(XBEE_AT_CMD_RESP_FRAME, "AT Command Response"),
		XBEE_DEBUG_PAIR(XBEE_REM_AT_CMD_FRAME, "Remote AT Command Request"),
		XBEE_DEBUG_PAIR(XBEE_REM_AT_CMD_RESP_FRAME, "Remote AT Command Response"),
		XBEE_DEBUG_PAIR(XBEE_ND_ID_INDICATOR, "Node Identification Indicator"),
		XBEE_DEBUG_PAIR(XBEE_TR_STATUS_FRAME, "ZigBee Transmit Status"),
		XBEE_DEBUG_PAIR(XBEE_MODEM_STATUS_FRAME, "ZigBee Modem Status")
};

XBEE_DEBUG_MAP XBeeDebug::XBeeApiIds = XBEE_DEBUG_MAP(_dataApiIds, _dataApiIds + sizeof(_dataApiIds) / sizeof(*_dataApiIds));

XBEE_DEBUG_PAIR XBeeDebug::_dataNIIRecOpts[] = {
        XBEE_DEBUG_PAIR(XBEE_MAP_TITLE_KEY, "Receive Options : "),
		XBEE_DEBUG_PAIR(XBEE_RPACKET_BDCAST, "Broadcast Address"),
		XBEE_DEBUG_PAIR(XBEE_RPACKET_ACK, "Packet Acknowledged"),
		XBEE_DEBUG_PAIR(XBEE_PACKET_ACK, "Packet Acknowledged"),
		XBEE_DEBUG_PAIR(XBEE_PACKET_BDCAST, "Packet Was A Broadcast Package"),
		XBEE_DEBUG_PAIR(XBEE_PACKET_CRYPT_APS, "Package Encrypted With APS Encryption"),
		XBEE_DEBUG_PAIR(XBEE_P_SENT_END_DEV, "Packet Was Sent From An End Device")
};

XBEE_DEBUG_MAP XBeeDebug::XBeeNIIRecOpts = XBEE_DEBUG_MAP(_dataNIIRecOpts, _dataNIIRecOpts + sizeof(_dataNIIRecOpts) / sizeof(*_dataNIIRecOpts));

XBEE_DEBUG_PAIR XBeeDebug::_dataRRecOpts[] = {
        XBEE_DEBUG_PAIR(XBEE_MAP_TITLE_KEY, "Receive Options : "),
		XBEE_DEBUG_PAIR(XBEE_RPACKET_BDCAST, "Broadcast Address"),
		XBEE_DEBUG_PAIR(XBEE_RPACKET_ACK, "Packet Acknowledged")
};

XBEE_DEBUG_MAP XBeeDebug::XBeeRRecOpts = XBEE_DEBUG_MAP(_dataRRecOpts, _dataRRecOpts + sizeof(_dataRRecOpts) / sizeof(*_dataRRecOpts));

XBEE_DEBUG_PAIR XBeeDebug::_dataTrReqOpts[] = {
        XBEE_DEBUG_PAIR(XBEE_MAP_TITLE_KEY, "Options : "),
		XBEE_DEBUG_PAIR(XBEE_TR_REQ_DIS_ACK, "Disable ACK"),
        XBEE_DEBUG_PAIR(XBEE_TR_REQ_DIS_NET_ADD_DIS, "Disable Network Address Discovery")
};

XBEE_DEBUG_MAP XBeeDebug::XBeeTrReqOpts = XBEE_DEBUG_MAP(_dataTrReqOpts, _dataTrReqOpts + sizeof(_dataTrReqOpts) / sizeof(*_dataTrReqOpts));

XBEE_DEBUG_PAIR XBeeDebug::_dataDevType[] = {
        XBEE_DEBUG_PAIR(XBEE_MAP_TITLE_KEY, "Device Type : "),
		XBEE_DEBUG_PAIR(XBEE_COORD, "Coordinator"),
		XBEE_DEBUG_PAIR(XBEE_ROUTER, "Router"),
		XBEE_DEBUG_PAIR(XBEE_END_DEV, "End Device")
};

XBEE_DEBUG_MAP XBeeDebug::XBeeDevType = XBEE_DEBUG_MAP(_dataDevType, _dataDevType + sizeof(_dataDevType) / sizeof(*_dataDevType));

XBEE_DEBUG_PAIR XBeeDebug::_dataSrcEvt[] = {
        XBEE_DEBUG_PAIR(XBEE_MAP_TITLE_KEY, "Source Event : "),
		XBEE_DEBUG_PAIR(XBEE_PUSHBUTTON_EVT, "Frame Sent By Node Identification Push Button Event"),
		XBEE_DEBUG_PAIR(XBEE_JOINING_EVT, "Frame Sent After Joining Event Occurred"),
		XBEE_DEBUG_PAIR(XBEE_PWR_CYCLE_EVT, "Frame Sent After Power Cycle Event Occurred")
};

XBEE_DEBUG_MAP XBeeDebug::XBeeSrcEvt = XBEE_DEBUG_MAP(_dataSrcEvt, _dataSrcEvt + sizeof(_dataSrcEvt) / sizeof(*_dataSrcEvt));

XBEE_DEBUG_PAIR XBeeDebug::_dataAtCmd[] = {
        XBEE_DEBUG_PAIR(XBEE_MAP_TITLE_KEY, "AT Command : "),
    /*  Special Commands                                */
		XBEE_DEBUG_PAIR(XBEE_AT_CMD_WR, "Write"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_WB, "Write Binding Table"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_RE, "Restore Defaults"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_FR, "Software Reset"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_NR, "Network Reset"),
    /*  Addressing                                      */
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_DH, "Destination Address High"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_DL, "Destination Address Low"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_ZA, "ZigBee Application Layer"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_SE, "Source Event"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_DE, "Destination Endpoint"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_CI, "Cluster Identifier"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_BI, "Binding Table Index"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_MY, "16-bit Network Address"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_MP, "16-bit Parent Network Address"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_SH, "Serial Number High"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_SL, "Serial Number Low"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_NI, "Node Identifier"),
    /*  Networking & Security                           */
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_CH, "Operating Channel"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_ID, "PAN ID"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_BH, "Broadcast Hops"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_NT, "Node Discovery Timeout"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_ND, "Node Discover"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_DN, "Destination Node"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_JN, "Join Notification"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_SC, "Scan Channels"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_SD, "Scan Duration"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_NJ, "Node Join Time"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_AR, "Aggregate Routing Notification"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_AI, "Association Indication"),
    /*  RF Interfacing                                  */
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_PL, "Power Level"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_PM, "Power Mode"),
    /*  Serial Interfacing (I/O)                        */
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_AP, "API Enable"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_AO, "API Options"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_BD, "Interface Data Rate"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_RO, "Packetization Timeout"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_D7, "DIO7 Configuration"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_D6, "DIO6 Configuration"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_D5, "DIO5 Configuration"),
    /*  I/O Commands                                    */
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_P0, "PWM0 Configuration"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_P1, "DIO11 Configuration"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_P2, "DIO12 Configuration"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_RP, "RSSI PWM Timer"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_IS, "Force Sample"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_D0, "AD0/DIO0 Configuration"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_D1, "AD1/DIO1 Configuration"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_D2, "AD2/DIO2 Configuration"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_D3, "AD3/DIO3 Configuration"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_D4, "DIO4 Configuration"),
    /*  Diagnostics                                     */
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_VR, "Firmware Version"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_HV, "Hardware Version"),
    /*  AT Command Options                              */
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_CT, "Command Mode Timeout"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_CN, "Exit Command Mode"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_GT, "Guard Times"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_CC, "Command Sequence Character"),
    /*  Sleep Commands                                  */
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_SM, "Sleep Mode"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_SN, "Number of Sleep Periods"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_SP, "Sleep Period"),
        XBEE_DEBUG_PAIR(XBEE_AT_CMD_ST, "Time Before Sleep")
};

XBEE_DEBUG_MAP XBeeDebug::XBeeAtCmd = XBEE_DEBUG_MAP(_dataAtCmd, _dataAtCmd + sizeof(_dataAtCmd) / sizeof(*_dataAtCmd));

XBEE_DEBUG_PAIR XBeeDebug::_dataAtCmdRespStatus[] = {
        XBEE_DEBUG_PAIR(XBEE_MAP_TITLE_KEY, "Status : "),
		XBEE_DEBUG_PAIR(XBEE_AT_RESP_STATUS_OK, "Ok"),
		XBEE_DEBUG_PAIR(XBEE_AT_RESP_STATUS_ERR, "Error"),
		XBEE_DEBUG_PAIR(XBEE_AT_RESP_STATUS_INV_CMD, "Invalid Command"),
		XBEE_DEBUG_PAIR(XBEE_AT_RESP_STATUS_INV_PAR, "Invalid Parameter")
};

XBEE_DEBUG_MAP XBeeDebug::XBeeAtCmdRespStatus = XBEE_DEBUG_MAP(_dataAtCmdRespStatus, _dataAtCmdRespStatus + sizeof(_dataAtCmdRespStatus) / sizeof(*_dataAtCmdRespStatus));

XBEE_DEBUG_PAIR XBeeDebug::_dataRemAtCmdOpts[] = {
        XBEE_DEBUG_PAIR(XBEE_MAP_TITLE_KEY, "Remote Command Options : "),
		XBEE_DEBUG_PAIR(XBEE_DIS_RET_DIS_ROUTE_REP,"Disable retries and route repair"),
        XBEE_DEBUG_PAIR(XBEE_APPLY_CHANGES,"Apply changes"),
        XBEE_DEBUG_PAIR(XBEE_EN_APS_ENCRYPT,"Enable APS Encryption"),
        XBEE_DEBUG_PAIR(XBEE_EXT_TRANS_TIMEOUT,"Use the extended transmission timeout")
};

XBEE_DEBUG_MAP XBeeDebug::XBeeRemAtCmdOpts = XBEE_DEBUG_MAP(_dataRemAtCmdOpts, _dataRemAtCmdOpts + sizeof(_dataRemAtCmdOpts) / sizeof(*_dataRemAtCmdOpts));

XBEE_DEBUG_PAIR XBeeDebug::_dataRemAtCmdRespStatus[] = {
        XBEE_DEBUG_PAIR(XBEE_MAP_TITLE_KEY, "Status : "),
		XBEE_DEBUG_PAIR(XBEE_REM_AT_RESP_STATUS_OK, "Ok"),
		XBEE_DEBUG_PAIR(XBEE_REM_AT_RESP_STATUS_ERROR, "Error"),
        XBEE_DEBUG_PAIR(XBEE_REM_AT_RESP_STATUS_INV_CMD, "Invalid Command"),
        XBEE_DEBUG_PAIR(XBEE_REM_AT_RESP_STATUS_INV_PAR, "Invalid Parameter"),
        XBEE_DEBUG_PAIR(XBEE_REM_AT_RESP_STATUS_FAILED, "Remote Command Transmission Failed")
};

XBEE_DEBUG_MAP XBeeDebug::XBeeRemAtCmdRespStatus = XBEE_DEBUG_MAP(_dataRemAtCmdRespStatus, _dataRemAtCmdRespStatus + sizeof(_dataRemAtCmdRespStatus) / sizeof(*_dataRemAtCmdRespStatus));

XBEE_DEBUG_PAIR XBeeDebug::_dataTrDelStatus[] = {
        XBEE_DEBUG_PAIR(XBEE_MAP_TITLE_KEY, "Delivery Status : "),
		XBEE_DEBUG_PAIR(XBEE_DEL_STAT_SUCCESS,"Success"),
		XBEE_DEBUG_PAIR(XBEE_DEL_STAT_CCAFAIL,"CCA Failure"),
		XBEE_DEBUG_PAIR(XBEE_DEL_STAT_NETFAIL,"Network ACK Failure"),
		XBEE_DEBUG_PAIR(XBEE_DEL_STAT_NOTJOIN,"Not Joined to Network"),
		XBEE_DEBUG_PAIR(XBEE_DEL_STAT_SELFADR,"Self-addressed"),
		XBEE_DEBUG_PAIR(XBEE_DEL_STAT_ADRNOTF,"Address Not Found"),
		XBEE_DEBUG_PAIR(XBEE_DEL_STAT_ROUTNOTF,"Route Not Found")
};

XBEE_DEBUG_MAP XBeeDebug::XBeeTrDelStatus = XBEE_DEBUG_MAP(_dataTrDelStatus, _dataTrDelStatus + sizeof(_dataTrDelStatus) / sizeof(*_dataTrDelStatus));

XBEE_DEBUG_PAIR XBeeDebug::_dataTrDiscovStatus[] = {
        XBEE_DEBUG_PAIR(XBEE_MAP_TITLE_KEY, "Discovery Status : "),
		XBEE_DEBUG_PAIR(XBEE_DISC_STAT_NODISCO,"No Discovery Overhead"),
		XBEE_DEBUG_PAIR(XBEE_DISC_STAT_ADRDISCO,"Address Discovery"),
		XBEE_DEBUG_PAIR(XBEE_DISC_STAT_ROUDISCO	,"Route Discovery"),
		XBEE_DEBUG_PAIR(XBEE_DISC_STAT_BOTDISCO	,"Address and Route Discovery")
};

XBEE_DEBUG_MAP XBeeDebug::XBeeTrDiscovStatus = XBEE_DEBUG_MAP(_dataTrDiscovStatus, _dataTrDiscovStatus + sizeof(_dataTrDiscovStatus) / sizeof(*_dataTrDiscovStatus));

XBEE_DEBUG_PAIR XBeeDebug::_dataModemStatus[] = {
        XBEE_DEBUG_PAIR(XBEE_MAP_TITLE_KEY, "Modem Status : "),
		XBEE_DEBUG_PAIR(XBEE_HARDWARE_RESET, "Hardware Reset"),
		XBEE_DEBUG_PAIR(XBEE_WATCHDOG_RESET, "Watchdog Reset"),
		XBEE_DEBUG_PAIR(XBEE_JOINED, "XBee Joined"),
		XBEE_DEBUG_PAIR(XBEE_UNJOINED, "XBee Unjoined"),
		XBEE_DEBUG_PAIR(XBEE_SYNCHRO_LOST, "Synchronisation Lost"),
		XBEE_DEBUG_PAIR(XBEE_COORD_REALIGNMENT,	"Coordinator Realignment"),
		XBEE_DEBUG_PAIR(XBEE_COORD_STARTED, "Coordinator Started")
};

XBEE_DEBUG_MAP XBeeDebug::XBeeModemStatus = XBEE_DEBUG_MAP(_dataModemStatus, _dataModemStatus + sizeof(_dataModemStatus) / sizeof(*_dataModemStatus));

bool XBeeDebug::searchMap(XBEE_DEBUG_MAP& map, uint16_t data){
	XBEE_DEBUG_MAP::iterator i;
	for(i = map.begin(); i!=map.end(); i++){
		if((i->first)==data)
			return true;
	}
	return false;
}

void XBeeDebug::debugMap(XBEE_DEBUG_MAP& map, uint16_t data, bool combined){
    
    cout << std::right << std::setw(XBEE_SETW_TXT) << std::setfill(' ') << map[XBEE_MAP_TITLE_KEY];
    
    unsigned short cnt = 0;
    XBEE_DEBUG_MAP::iterator i;
    if(combined){
        for(i = map.begin(); i!=map.end(); i++){
            if((i->first)&data){
                if(cnt != 0){
                    cout << std::right << std::setw(XBEE_SETW_TXT) << std::setfill(' ') << "";
                }
                cout << i->second << endl;
                cnt++;
            }
        }
    }
    else{
        //TODO: CAMBIAR PORQUE SI ES SOLO UNO EL QUE ES VALIDO NO VALE LA PENA HACER EL BUCLE
        //      HACER DIRECTAMENTE cout << IOMANIP << map[data];
        for(i = map.begin(); i!=map.end(); i++){
            if((i->first)==data){
                if(cnt != 0){
                    cout << std::right << std::setw(XBEE_SETW_TXT) << std::setfill(' ') << "";
                }
                cout << i->second << endl;
                cnt++;
            }
        }
    }
    if(cnt==0)
        cout << endl;
}

void XBeeDebug::debugHex(const string& str, uint64_t data, uint8_t nBytes){

    if(str != "")
        cout << std::right << std::setw(XBEE_SETW_TXT) << std::setfill(' ') << str;
    
    cout << uppercase << std::hex << std::setw(2*nBytes) << std::setfill('0');
    switch(nBytes){
        case 1:
            cout << ((uint8_t)data)+0 << endl;
            break;
        case 2:
            cout << ((uint16_t)data)+0 << endl;
            break;
        case 4:
            cout << ((uint32_t)data)+0 << endl;
            break;
        case 8:
            cout << ((uint64_t)data)+0 << endl;
            break;
        default:
            cout << "In function \"debugHex\" : nBytes out of range" << endl;
            break;
    }
}

void XBeeDebug::debugHex(const string& str, vector<uint8_t>* data){

    if(data == NULL){
        cout << "In function \"debugHex\" : data pointer is NULL" << endl;
        return;
    }
    if(str != "")
        cout << std::right << std::setw(XBEE_SETW_TXT) << std::setfill(' ') << str;
    
    if(data->empty())
        cout << "(Empty)";
    else{
        for(std::vector<uint8_t>::iterator i=data->begin(); i!=data->end(); i++)
            cout << uppercase << std::hex << std::setw(2) << std::setfill('0') << (*i)+0;
    }
    cout << endl;
}

void XBeeDebug::debugDec(const string& str, uint64_t data, uint8_t nBytes){

    if(str != "")
        cout << std::right << std::setw(XBEE_SETW_TXT) << std::setfill(' ') << str;
    
    cout << std::dec;
    switch(nBytes){
        case 1:
            cout << ((uint8_t)data)+0 << endl;
            break;
        case 2:
            cout << ((uint16_t)data)+0 << endl;
            break;
        case 4:
            cout << ((uint32_t)data)+0 << endl;
            break;
        case 8:
            cout << ((uint64_t)data)+0 << endl;
            break;
        default:
            cout << "In function \"debugDec\": nBytes out of range" << endl;
            break;
    }
}

void XBeeDebug::debugAddr(const string& str, const uint64_t& data){

    cout << std::right << std::setw(XBEE_SETW_TXT) << std::setfill(' ') << str \
        << uppercase << std::hex << std::setw(16) << std::setfill('0') << data+0 << endl;
}

void XBeeDebug::debugMy(const string& str, const uint16_t& data){

    cout << std::right << std::setw(XBEE_SETW_TXT) << std::setfill(' ') << str \
        << uppercase << std::hex << std::setw(4) << std::setfill('0') << data+0 << endl;
}

void XBeeDebug::debugStr(const string& str, const string& data){
    
    cout << std::right << std::setw(XBEE_SETW_TXT) << std::setfill(' ') << str;
	cout << data << endl;
}

void XBeeDebug::debugTrace(uint8_t lvl, uint8_t frameId, const string& desc){
    
    cout << std::setw(lvl*XBEE_TRACE_SPACE) << std::setfill(' ') << "";
    cout << "\\";
    cout << std::setw(XBEE_TRACE_LINE) << std::setfill('_') << "";
    cout << desc << " (ID = " << frameId << ")" << endl;
}
