#include <stdio.h>
#include "ST_SendLastDataAck.hpp"
#include "ST_Idle.hpp"

using namespace std;

ST_SendLastDataAck::ST_SendLastDataAck()
{
	currentState = "Waiting to Send Last Data Ack.";
}

genericState* ST_SendLastDataAck :: on_SendAck(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_Idle();
	ret->executedAction = "Last Data Ack. Sent";
	return ret;
};

genericState* ST_SendLastDataAck::on_SendError(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_Idle();
	ret->executedAction = "Error Sent, Server Restarted";
	return ret;
}
