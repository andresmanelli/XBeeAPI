#ifndef _XBEE_ID_SPECIFIC_DATA_
#define _XBEE_ID_SPECIFIC_DATA_

#include <XBeeUtil.hpp>

#include <stdint.h>
#include <vector>

using namespace std;

class XBeeIdSpecificData{
	public:
		virtual ~XBeeIdSpecificData(){};
		virtual unsigned short length() = 0;
		virtual vector<uint8_t> toBytes() = 0;
		virtual bool loadFrame(const vector<uint8_t>& frame) = 0;
		virtual void debug() = 0;
		//Used for easy of access, returns 0 if the child class doesn't
		//have this field.
		virtual uint8_t getFrameID() = 0;
};

#endif
