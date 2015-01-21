#ifndef _XBEE_DEBUG_
#define _XBEE_DEBUG_

#include <XBeeUtil.hpp>
#include <map>
#include <string>
#include <stdint.h>
#include <vector>

using namespace std;

/**********************************************************************/
/*						Map For Debugging 					  	 	  */
/**********************************************************************/
typedef std::map<uint16_t, std::string> XBEE_DEBUG_MAP;
typedef std::pair<uint16_t, std::string> XBEE_DEBUG_PAIR;

class XBeeDebug{

	public:
		XBeeDebug();
		~XBeeDebug(){};
		static XBEE_DEBUG_MAP XBeeApiIds;
		static XBEE_DEBUG_MAP XBeeNIIRecOpts;
        static XBEE_DEBUG_MAP XBeeRRecOpts;
        static XBEE_DEBUG_MAP XBeeTrReqOpts;
		static XBEE_DEBUG_MAP XBeeDevType;
		static XBEE_DEBUG_MAP XBeeSrcEvt;
        static XBEE_DEBUG_MAP XBeeAtCmd;
        static XBEE_DEBUG_MAP XBeeAtCmdRespStatus;
        static XBEE_DEBUG_MAP XBeeRemAtCmdOpts;
        static XBEE_DEBUG_MAP XBeeRemAtCmdRespStatus;
        static XBEE_DEBUG_MAP XBeeTrDelStatus;
        static XBEE_DEBUG_MAP XBeeTrDiscovStatus;
        static XBEE_DEBUG_MAP XBeeModemStatus;
        
        static bool searchMap(XBEE_DEBUG_MAP& map, uint16_t data);
        static void debugMap(XBEE_DEBUG_MAP& map, uint16_t data, bool combined);
        static void debugHex(const string& str, uint64_t data, uint8_t length);
        static void debugHex(const string& str, vector<uint8_t>* data);
        static void debugDec(const string& str, uint64_t data, uint8_t length);
        static void debugAddr(const string& str, const uint64_t& data);
        static void debugMy(const string& str, const uint16_t& data);
        static void debugStr(const string& str, const string& data);
        static void debugTrace(uint8_t lvl, uint8_t frameId, const string& desc);
	private:
		static XBEE_DEBUG_PAIR _dataApiIds[];
		static XBEE_DEBUG_PAIR _dataNIIRecOpts[];
        static XBEE_DEBUG_PAIR _dataRRecOpts[];
		static XBEE_DEBUG_PAIR _dataDevType[];
		static XBEE_DEBUG_PAIR _dataSrcEvt[];
        static XBEE_DEBUG_PAIR _dataAtCmd[];
        static XBEE_DEBUG_PAIR _dataAtCmdRespStatus[];
        static XBEE_DEBUG_PAIR _dataRemAtCmdOpts[];
        static XBEE_DEBUG_PAIR _dataTrReqOpts[];
        static XBEE_DEBUG_PAIR _dataRemAtCmdRespStatus[];
        static XBEE_DEBUG_PAIR _dataTrDelStatus[];
        static XBEE_DEBUG_PAIR _dataTrDiscovStatus[];
        static XBEE_DEBUG_PAIR _dataModemStatus[];
};

#endif
