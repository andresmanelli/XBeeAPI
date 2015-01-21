#ifndef _XBEE_ND_ID_INDICATOR_
#define _XBEE_ND_ID_INDICATOR_

#include <XBeeIdSpecificData.hpp>
#include <XBeeDebug.hpp>

#include <stdint.h>
#include <vector>
#include <string>

using namespace std;

class XBeeNdIdIndicator : public XBeeIdSpecificData{
	public:
		XBeeNdIdIndicator();
		virtual ~XBeeNdIdIndicator(){
			delete _niString;
		};
		unsigned short length();
		vector<uint8_t> toBytes();
		uint8_t getFrameID(){
			return 0;
		}

		bool setSenderAddr(uint64_t senderAddr);
		bool setSenderMY(uint16_t senderMY);
		bool setSourceAddr(uint64_t sourceAddr);
		bool setSourceMY(uint16_t sourceMY);
		bool setParentMY(uint16_t parentMY);
		bool setOptions(uint8_t options);
		bool setNIString(vector<uint8_t> ni);
		bool setDeviceType(uint8_t devType);
		bool setSourceEvent(uint8_t srcEvent);
		bool setAppProfileID(uint16_t id);
		bool setManufacturerID(uint16_t id);
		uint64_t getSenderAddr();
		uint16_t getSenderMY();
		bool loadFrame(const vector<uint8_t>& frame);
		void debug();

		string getNIString();

	private:
		uint64_t _senderAddr;
		uint16_t _senderMY;
		uint8_t _options;
		uint16_t _sourceMY;
		uint64_t _sourceAddr;
		vector<uint8_t>* _niString;
		uint16_t _parentMY;
		uint8_t _devType;
		uint8_t _srcEvent;
		uint16_t _appProfileID;
		uint16_t _manufacturerID;
};

#endif
