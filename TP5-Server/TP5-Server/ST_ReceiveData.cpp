#include <stdio.h>
#include "ST_ReceiveData.hpp"
#include "ST_SendDataAck.hpp"
#include "ST_SendLastDataAck.hpp"
#include "ST_Idle.hpp"

using namespace std;

ST_ReceiveData::ST_ReceiveData()
{
	currentState = "Waiting for Data";
}

genericState* ST_ReceiveData :: on_timeout(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_ReceiveData();
	ret->executedAction = "N/A";
	return ret;
};

genericState* ST_ReceiveData :: on_ReceiveData(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_SendDataAck();
	ret->executedAction = "N/A";
	return ret;
};

genericState* ST_ReceiveData :: on_ReceiveLastData(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_SendLastDataAck();
	ret->executedAction = "N/A";
	return ret;
};

genericState* ST_ReceiveData::on_ReceiveError(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_Idle();
	ret->executedAction = "Error Received, Server Restarted";
	return ret;
}
