#ifndef GENERIC_STATE_H
#define GENERIC_STATE_H

#include <iostream>
#include "genericEvent.hpp"
#include <string>

using namespace std;

class genericState
{
public:

	virtual genericState* on_SendWRQ(genericEvent* ev) { return nullptr; }
	virtual genericState* on_SendRRQ(genericEvent* ev) { return nullptr; }
	virtual genericState* on_ReceiveWRQ(genericEvent* ev) { return nullptr; }
	virtual genericState* on_ReceiveRRQ(genericEvent* ev) { return nullptr; }
	virtual genericState* on_ReceiveWRQAck(genericEvent* ev) { return nullptr; }
	virtual genericState* on_SendData(genericEvent* ev) { return nullptr; }
	virtual genericState* on_ReceiveData(genericEvent* ev) { return nullptr; }
	virtual genericState* on_SendAck(genericEvent* ev) { return nullptr; }
	virtual genericState* on_ReceiveAck(genericEvent* ev) { return nullptr; }
	virtual genericState* on_SendLastData(genericEvent* ev) { return nullptr; }
	virtual genericState* on_ReceiveLastData(genericEvent* ev) { return nullptr; }
	virtual genericState* on_timeout(genericEvent* ev) { return nullptr; }

	event_t lastEvent;
	string executedAction;

protected:

};

#endif // !GENERIC_STATE_H
