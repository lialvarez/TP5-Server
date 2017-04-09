#include <stdio.h>
#include "ST_SendLastDataAck.hpp"
#include "ST_ReceiveLastDataAck.hpp"

using namespace std;

genericState* ST_SendLastDataAck :: on_SendAck(genericEvent* ev)
{
	executedAction = "ACK Sent";
	//cout << "Previous state: Waiting to send last data ACK" << endl << "Event received: send last data ACK. Last data ACK was sent" << endl << "New state: Idle" << endl << endl;
    return ((genericState*) new ST_ReceiveLastDataAck());
};
