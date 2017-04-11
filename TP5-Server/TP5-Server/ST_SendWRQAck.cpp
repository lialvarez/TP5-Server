#include "ST_SendWRQAck.hpp"
#include "ST_ReceiveData.hpp"
#include "ST_Idle.hpp"

ST_SendWRQAck::ST_SendWRQAck()
{
	currentState = "Waiting to Send WRQ Ack.";
}

genericState* ST_SendWRQAck::on_SendAck(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_ReceiveData();
	ret->executedAction = "WRQ Ack. Sent";
	return ret;
}

genericState* ST_SendWRQAck::on_SendError(genericEvent *ev)
{
	genericState *ret = (genericState*) new ST_Idle();
	ret->executedAction = "Error Sent, Server Restarted";
	return ret;
}

genericState* ST_SendWRQAck::on_CloseServer(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_Idle();
	ret->executedAction = "Server Closed";
	ret->setLastEvent(CLOSE_SERVER);
	return ret;
}