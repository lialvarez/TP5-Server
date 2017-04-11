#include "ST_Idle.hpp"
#include "ST_SendWRQAck.hpp"
#include "ST_SendData.hpp"

using namespace std;

ST_Idle::ST_Idle()
{
	currentState = "Idle";
}

genericState* ST_Idle::on_ReceiveWRQ(genericEvent *ev)
{
	genericState *ret = (genericState*) new ST_SendWRQAck();
	ret->executedAction = "N/A";
	return ret;
};

genericState* ST_Idle::on_ReceiveRRQ(genericEvent *ev)
{
	genericState *ret = (genericState*) new ST_SendData();
	ret->executedAction = "N/A";
	return ret;
};

genericState* ST_Idle::on_ReceiveError(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_Idle();
	ret->executedAction = "Error Received, Server Restarted";
	return ret;
}

genericState* ST_Idle::on_CloseServer(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_Idle();
	ret->executedAction = "Server Closed";
	ret->setLastEvent(CLOSE_SERVER);
	return ret;
}
