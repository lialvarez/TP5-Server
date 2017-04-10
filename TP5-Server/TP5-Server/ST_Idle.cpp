#include <stdio.h>
#include "ST_Idle.hpp"
#include "ST_SendAck.hpp"
#include "ST_SendData.hpp"
#include "ST_ReceiveWRQAck.hpp"
#include "ST_ReceiveFirstData.hpp"

using namespace std;

genericState* ST_Idle::on_ReceiveWRQ(genericEvent *ev)
{
	return ((genericState*) new ST_SendAck());
};
genericState* ST_Idle::on_ReceiveRRQ(genericEvent *ev)
{
    return ((genericState*) new ST_SendData());
};

genericState* ST_Idle::on_SendWRQ(genericEvent *ev)
{
	executedAction = "WRQ Sent";
	return ((genericState*) new ST_ReceiveWRQAck());
};

genericState* ST_Idle::on_SendRRQ(genericEvent *ev)
{
	executedAction = "RRQ Sent";
	return ((genericState*) new ST_ReceiveFirstData());
};