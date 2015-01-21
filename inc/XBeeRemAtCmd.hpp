#ifndef _XBEE_REM_AT_CMD
#define _XBEE_REM_AT_CMD

#include <XBeeIdSpecificData.hpp>

#include <stdint.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class XBeeRemAtCmd : public XBeeIdSpecificData{
	public:
		XBeeRemAtCmd();
		virtual ~XBeeRemAtCmd(){
			delete _paramValue;
		};
		unsigned short length();
		vector<uint8_t> toBytes();
		uint8_t getFrameID(){
			return _frameId;
		}

		bool setFrameId(uint8_t frameId);
		bool setDestAddr(uint64_t destAddr);
		bool setDestMY(uint16_t destMY);
		bool setRemCmdOpts(uint8_t remCmdOpts);
		bool setAtCmd(uint16_t atCmd);
		bool setParamValue(const string& paramValue, bool set0);
		bool setParamValue(const vector<uint8_t>& paramValue);
		bool loadFrame(const vector<uint8_t>& frame);
		void debug();

    private:
    	uint64_t _destAddr;
		uint16_t _destMY;
        uint8_t _remCmdOpts;
        vector<uint8_t>* _paramValue;
		uint8_t _frameId;
		uint16_t _atCmd;
};

#endif
