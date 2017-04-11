#include <stdio.h>
#include "ST_ReceiveDataAck.hpp"
#include "ST_SendData.hpp"
#include "ST_Idle.hpp"

using namespace std;

ST_ReceiveDataAck::ST_ReceiveDataAck()
{
	currentState = "Waiting for Data Ack.";
}

genericState* ST_ReceiveDataAck :: on_ReceiveAck(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_SendData();
	ret->executedAction = "N/A";
    return ret;
};

genericState* ST_ReceiveDataAck :: on_timeout(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_ReceiveDataAck();
	ret->executedAction = "N/A";
    return ret;
};

genericState* ST_ReceiveDataAck::on_ReceiveError(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_Idle();
	ret->executedAction = "Error Received, Server Restarted";
	return ret;
}