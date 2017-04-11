#include <stdio.h>
#include "ST_ReceiveFirstData.hpp"
#include "ST_SendDataAck.hpp"
#include "ST_Idle.hpp"

using namespace std;

ST_ReceiveFirstData::ST_ReceiveFirstData()
{
	currentState = "Waiting for First Data";
}

genericState* ST_ReceiveFirstData :: on_timeout(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_ReceiveFirstData();
	ret->executedAction = "N/A";
    return ret;
};
genericState* ST_ReceiveFirstData :: on_ReceiveData(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_SendDataAck();
	ret->executedAction = "N/A";
    return ret;
};

genericState* ST_ReceiveFirstData::on_ReceiveError(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_Idle();
	ret->executedAction = "Error Received, Server Restarted";
	return ret;
}
