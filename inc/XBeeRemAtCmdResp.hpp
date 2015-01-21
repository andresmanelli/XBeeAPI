#ifndef _XBEE_REM_AT_CMD_RESP_
#define _XBEE_REM_AT_CMD_RESP_

#include <XBeeRemAtCmd.hpp>
#include <XBeeUtil.hpp>

#include <stdint.h>

using namespace std;

class XBeeRemAtCmdResp : public XBeeIdSpecificData {
	public:
		XBeeRemAtCmdResp();
		virtual ~XBeeRemAtCmdResp(){};

        unsigned short length();
        vector<uint8_t> toBytes();
		bool loadFrame(const vector<uint8_t>& frame);
		void debug();
		
		uint8_t getFrameID(){return _frameId;}
		uint64_t getSourceAddr(void) {return _sourceAddr;}
		uint16_t getSourceMy(void) {return _sourceMY;}
		uint8_t getCmdStatus (void) {return _cmdStatus;}
		uint16_t getAtCmd(void) {return _atCmd;}
		vector<uint8_t> getCmdData(void) {return *_cmdData;}

	private:
        uint8_t _frameId;
        uint64_t _sourceAddr;
        uint16_t _sourceMY;
        uint16_t _atCmd;
        uint8_t _cmdStatus;
        vector<uint8_t>* _cmdData;
};

#endif
