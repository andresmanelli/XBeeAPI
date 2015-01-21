#ifndef _XBEE_AT_CMD_RESP_
#define _XBEE_AT_CMD_RESP_

#include <XBeeAtCmd.hpp>
#include <XBeeUtil.hpp>

#include <stdint.h>

using namespace std;

class XBeeAtCmdResp : public XBeeAtCmd {
	public:
		XBeeAtCmdResp();
		virtual ~XBeeAtCmdResp(){};

		bool setStatus(uint8_t status);
		vector<uint8_t> toBytes();
		bool loadFrame(const vector<uint8_t>& frame);
		bool evaluateFrame(void);
		void debug();

		uint64_t getSourceAddr(void) {return _sourceAddr;}
		uint16_t getSourceMy(void) {return _sourceMY;}
		string getNom(void) {return _nom;}
		uint16_t getParentMy(void) {return _parentMY;}
		uint8_t getStatus (void) {return _status;}
		uint16_t getAtCmd(void) {return _atCmd;}

	private:
		uint8_t _status;
		uint64_t _sourceAddr;
		uint16_t _sourceMY;
		string _nom;
		uint16_t _parentMY;
		uint8_t _deviceType;
		uint8_t _statusR;
		uint16_t _profileId;
		uint16_t _manufacturerId;
};

#endif
