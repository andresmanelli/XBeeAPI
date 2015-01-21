#ifndef _XBEE_FRAME_DATA_
#define _XBEE_FRAME_DATA_

#include <XBeeIdSpecificData.hpp>
#include <XBeeTrReq.hpp>
#include <XBeeAtCmd.hpp>
#include <XBeeRemAtCmd.hpp>
#include <XBeeAtCmdResp.hpp>
#include <XBeeRemAtCmdResp.hpp>
#include <XBeeNdIdIndicator.hpp>
#include <XBeeDebug.hpp>
#include <XBeeReceivePacket.hpp>
#include <XBeeUtil.hpp>
#include <XBeeTrSta.hpp>
#include <XBeeModemSta.hpp>

#include <stdint.h>
#include <iostream>

using namespace std;

class XBeeFrameData{
	public:
		XBeeFrameData(uint8_t API_ID);
		~XBeeFrameData(){
			if (_cmdData){
				delete _cmdData;
			}
		};
		XBeeIdSpecificData* getCmdData();
		unsigned short length();
		vector<uint8_t> toBytes();
        uint8_t getApiId();
		bool loadFrame(const vector<uint8_t>& frame);
		void debug();
		//Used for easy of access, returns 0 if the child class doesn't
		//have this field.
		uint8_t getFrameID();

	private:
		uint8_t _apiID;
		XBeeIdSpecificData* _cmdData;
};

#endif
