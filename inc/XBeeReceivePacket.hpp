#ifndef _XBEE_RECEIVE_PACKET_
#define _XBEE_RECEIVE_PACKET_

#include <XBeeIdSpecificData.hpp>
#include <XBeeDebug.hpp>

#include <stdint.h>
#include <vector>
#include <string>

using namespace std;

class XBeeReceivePacket : public XBeeIdSpecificData {
	public:
		XBeeReceivePacket();
		virtual ~XBeeReceivePacket(){
			//delete ;
		};
		unsigned short length();
		vector<uint8_t> toBytes();
		bool loadFrame(const vector<uint8_t>& frame);
		void debug();
		uint64_t getSourceAddr();
		uint16_t getSourceMY();
		
		uint8_t getFrameID(){
			return 0;
		}

		vector<uint8_t> getRfData();

	private:
		uint64_t _sourceAddr;
		uint16_t _sourceMY;
		uint8_t _options;
		vector<uint8_t>* _rfData;
};

#endif
