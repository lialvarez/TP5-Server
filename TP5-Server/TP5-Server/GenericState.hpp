#ifndef GENERIC_STATE_H
#define GENERIC_STATE_H

#include <iostream>
#include <string>
#include "genericEvent.hpp"

using namespace std;

class genericState
{
public:

    // Estas funciones responden a los eventos recibidos en el estado actual. Por default, se toma que los eventos recibidos son eventos inesperados, lo que sse indica devolviendo nullptr. Al ser virtuales, las clases de los estados especificos que heredan a genericState pueden redefinir que respuesta tomar ante los eventos que no son inesperados para ese estado en especifico.
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
	virtual genericState* on_SendError(genericEvent* ev) { return nullptr; }
	virtual genericState* on_ReceiveError(genericEvent* ev) { return nullptr; }
	virtual genericState* on_Reset(genericEvent* ev) { return nullptr; }
	virtual genericState* on_CloseServer(genericEvent* ev) { return nullptr; }

	event_t getLastEvent() { return lastEvent; }
	void setLastEvent(event_t lastEvent) { this->lastEvent = lastEvent; }

	string executedAction;
	string currentState;

protected:

	event_t lastEvent;  //ultimo evento recibido

};

#endif // !GENERIC_STATE_H
