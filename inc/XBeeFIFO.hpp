#ifndef _XBEE_FIFO_
#define _XBEE_FIFO_

#include <XBeeFrame.hpp>
#include <database.hpp>
#include <XBeeFrame.hpp>
#include <stdint.h>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

typedef void (*action)(BDD * base, XBeeFrame* xbeeFrame, int * pingcaptor, string capteur);

typedef struct _XBEE_PEND_FRAME{
	uint8_t ID;
	uint8_t ID_resp;
	string capteur;
	uint64_t ADDR;
	uint8_t API_ID;
	action ACTION;
}XBEE_PEND_FRAME;

class XBeeFIFO {

	public:
		XBeeFIFO();
		~XBeeFIFO(){}
		uint8_t getNextID();
		uint8_t setFreeID(uint8_t id);
		uint8_t registerPendingFrame(uint8_t id, uint8_t id_resp, string capteur, uint64_t addr, uint8_t api_id, action a);
		action matchFrame(XBeeFrame* frame, XBEE_PEND_FRAME* match);

	private:
		queue<uint8_t> _dispIDs;
		vector<uint8_t> _usedIDs;
		vector<XBEE_PEND_FRAME> _pendingFrames;
};

#endif
