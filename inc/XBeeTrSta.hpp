#ifndef _XBEE_TR_STA_
#define _XBEE_TR_STA_

#include <XBeeIdSpecificData.hpp>

#include <stdint.h>
#include <vector>

using namespace std;

class XBeeTrSta : public XBeeIdSpecificData{
	public:
		XBeeTrSta();
		virtual ~XBeeTrSta(){
			//delete ;
		};
		unsigned short length();
		vector<uint8_t> toBytes();
		uint8_t getFrameID(){
			return _frameId;
		}

		bool loadFrame(const vector<uint8_t>& frame);
		void debug();
		
		uint8_t getTrStatus();
		
		uint16_t getSourceMY(){return _sourceMy;}

	private:
		uint8_t _frameId;
		//If success, the my to which we have sent packages.
		//If failure, own my.
		uint16_t _sourceMy;  
		uint8_t _trRetryCount;
		uint8_t _delivStatus;
		uint8_t _discovStatus;
};

#endif
