#include <stdio.h>
#include "ST_SendData.hpp"
#include "ST_ReceiveDataAck.hpp"
#include "ST_ReceiveLastDataAck.hpp"

using namespace std;

genericState* ST_SendData :: on_SendData(genericEvent* ev)
{
	executedAction = "DATA Sent";
    return ((genericState*) new ST_ReceiveDataAck());
};
genericState* ST_SendData :: on_SendLastData(genericEvent* ev)
{
	executedAction = "LAST DATA Sent";
    return ((genericState*) new ST_ReceiveLastDataAck());
};


