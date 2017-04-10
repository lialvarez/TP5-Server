#include "genericFSM.hpp"

void genericFSM::Dispatch(genericEvent *ev)
{
	genericState *newState;

	switch (ev->getEventType())
	{
	case R_WRQ:
		newState = currentState->on_ReceiveWRQ(ev);
		break;
	case R_RRQ:
		newState = currentState->on_ReceiveRRQ(ev);
		break;
	case S_ACK:
		newState->lastEvent = S_ACK;
		newState = currentState->on_SendAck(ev);
		break;
	case S_DATA:
		newState->lastEvent = S_DATA;
		newState = currentState->on_SendData(ev);
		break;
	case S_LAST_DATA:
		newState->lastEvent = S_LAST_DATA;
		newState = currentState->on_SendLastData(ev);
		break;
	case R_ACK:
		newState = currentState->on_ReceiveAck(ev);
		break;
	case R_DATA:
		newState = currentState->on_ReceiveData(ev);
		break;
	case R_LAST_DATA:
		newState = currentState->on_ReceiveLastData(ev);
		break;
	case R_TIMEOUT:
		newState = currentState->on_timeout(ev);
		break;
	default:
		break;
	}
	if (newState != nullptr)
	{
		delete currentState;
		currentState = newState;
	}
}

genericState* genericFSM::getCurrentState()
{
	return currentState;
}