#ifndef _XBEE_TR_REQ_
#define _XBEE_TR_REQ_

#include <XBeeIdSpecificData.hpp>

#include <stdint.h>
#include <vector>

using namespace std;

class XBeeTrReq : public XBeeIdSpecificData{
	public:
		XBeeTrReq();
		virtual ~XBeeTrReq(){
			delete _rfData;
		};
		unsigned short length();
		vector<uint8_t> toBytes();
		uint8_t getFrameID(){
			return _frameId;
		}

		vector<uint8_t> getRfData();
		bool setFrameId(uint8_t frameId);
		bool setDestAddr(uint64_t destAddr);
		bool setDestMY(uint16_t destMY);
		bool setBroadcastR(uint8_t broadcastR);
		bool setOptions(uint8_t options);
		bool setRfData(const vector<uint8_t>& rfData);
		bool loadFrame(const vector<uint8_t>& frame);
		void debug();
                
                uint64_t getDestAddr(void){return _destAddr;}

	private:
		uint8_t _frameId;
		uint64_t _destAddr;
		uint16_t _destMY;
		uint8_t _broadcastR;
		uint8_t _options;
		vector<uint8_t>* _rfData;
};

#endif
