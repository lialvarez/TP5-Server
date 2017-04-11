#include "genericFSM.hpp"
#include "ST_Idle.hpp"

genericFSM::genericFSM()
{
	currentState = (genericState *) new ST_Idle();
	printf("Ejecuta el constructor\n");
}

genericFSM::~genericFSM()
{
    delete currentState;
}

void genericFSM::Dispatch(genericEvent *ev)
{
	genericState *newState = nullptr;
    
    //lamar a la funcion del estado actual correspondiente al evento recibido
	switch (ev->getEventType())
	{
	case R_WRQ:
		newState = currentState->on_ReceiveWRQ(ev);
		break;
	case R_RRQ:
		newState = currentState->on_ReceiveRRQ(ev);
		break;
	case S_ACK:
		newState = currentState->on_SendAck(ev);
		break;
	case S_DATA:
		newState = currentState->on_SendData(ev);
		break;
	case S_LAST_DATA:
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
	case R_ERROR:
		newState = currentState->on_ReceiveError(ev);
		break;
	case S_ERROR:
		newState = currentState->on_SendError(ev);
		break;
	case CLOSE_SERVER:
		newState = currentState->on_CloseServer(ev);
		break;
	default:
		break;
	}
	if (newState != nullptr)    //si se apreto una tecla correspondiente a un evento
	{
		delete currentState;
		currentState = newState;
	}
}

genericState* genericFSM::getCurrentState()
{
	return currentState;
}
