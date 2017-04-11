#include <stdio.h>
#include "ST_ReceiveLastDataAck.hpp"
#include "ST_Idle.hpp"

using namespace std;

ST_ReceiveLastDataAck::ST_ReceiveLastDataAck()
{
	currentState = "Waiting for Last Data Ack.";
}

genericState* ST_ReceiveLastDataAck :: on_ReceiveAck(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_Idle();
	ret->executedAction = "N/A";
    return ret;
};

genericState* ST_ReceiveLastDataAck :: on_timeout(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_ReceiveLastDataAck();
	ret->executedAction = "N/A";
    return ret;
};

genericState* ST_ReceiveLastDataAck::on_ReceiveError(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_Idle();
	ret->executedAction = "Error Received, Server Restarted";
	return ret;
}
