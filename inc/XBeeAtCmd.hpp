#ifndef _XBEE_AT_CMD_
#define _XBEE_AT_CMD_

#include <XBeeIdSpecificData.hpp>
#include <XBeeUtil.hpp>

#include <stdint.h>
#include <vector>
#include <string>

using namespace std;

class XBeeAtCmd : public XBeeIdSpecificData{
	public:
		XBeeAtCmd();
		~XBeeAtCmd(){
			delete _paramValue;
		};

		vector<uint8_t> getParamValue();
		unsigned short length();
		virtual vector<uint8_t> toBytes();
		bool setFrameId(uint8_t frameId);
		uint8_t getFrameID();
		bool setAtCmd(uint16_t atCmd);
		bool setParamValue(const vector<uint8_t>& paramValue);
		bool setParamValue(const string& paramValue, bool set0);
		bool loadFrame(const vector<uint8_t>& frame);
		void debug();

	protected:

		uint8_t _frameId;
		uint16_t _atCmd;
		vector<uint8_t>* _paramValue;
};

#endif
