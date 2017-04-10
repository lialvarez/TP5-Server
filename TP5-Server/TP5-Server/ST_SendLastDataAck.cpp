#include <stdio.h>
#include "ST_SendLastDataAck.hpp"
#include "ST_ReceiveLastDataAck.hpp"

using namespace std;

genericState* ST_SendLastDataAck :: on_SendAck(genericEvent* ev)
{
	executedAction = "ACK Sent";
    return ((genericState*) new ST_ReceiveLastDataAck());
};
