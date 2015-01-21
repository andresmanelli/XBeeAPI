#ifndef _XBEE_FRAME_
#define _XBEE_FRAME_

#include <XBeeUtil.hpp>
#include <XBeeFrameData.hpp>
#include <XBeeIdSpecificData.hpp>

#include <stdlib.h>
#include <ostream>
#include <sstream>
#include <iomanip>

using namespace std;

class XBeeFrame{
	
	public:
		XBeeFrame(uint8_t API_ID);
		~XBeeFrame(){
			delete _frameData;
			delete _frame;
		};
		XBeeIdSpecificData* getCmdData();
		bool makeFrame();
		vector<uint8_t> getFrame();
                uint8_t getApiId();
		uint8_t checksum();
		bool check2sum(const vector<uint8_t>& frame);
		bool loadFrame(const vector<uint8_t>& frame);
		void debugFrame();
		//Used for easy of access, returns 0 if the child class doesn't
		//have this field.
		uint8_t getFrameID();

	private:
		uint16_t _length;
		XBeeFrameData* _frameData;
		uint8_t _checksum;
		vector<uint8_t>* _frame;
};

ostream& operator<<(ostream&, XBeeFrame&);
stringstream& operator<<(stringstream&, XBeeFrame&);

#endif
