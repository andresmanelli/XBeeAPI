#ifndef _XBEE_MODEM_STA_
#define _XBEE_MODEM_STA_

#include <XBeeIdSpecificData.hpp>

#include <stdint.h>
#include <vector>

using namespace std;

class XBeeModemSta : public XBeeIdSpecificData{
	public:
		XBeeModemSta();
		virtual ~XBeeModemSta(){
			//delete ;
		};
		unsigned short length();
		vector<uint8_t> toBytes();

		bool loadFrame(const vector<uint8_t>& frame);
		void debug();
		
		uint8_t getStatus(){
			return _specificData;
		}
		
		uint8_t getFrameID() {return 0;}

	private:
		uint8_t _specificData;
};

#endif
