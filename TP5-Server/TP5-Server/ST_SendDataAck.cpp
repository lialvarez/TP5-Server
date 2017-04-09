#include <stdio.h>
#include "ST_SendDataAck.hpp"
#include "ST_ReceiveData.hpp"


using namespace std;

genericState* ST_SendDataAck ::on_SendAck(genericEvent *ev)
{
	executedAction = "ACK Sent";
	//cout << "Previous state: Waiting to send data ACK" << endl << "Event received: send ACK. ACK was sent" << endl << "New state: Waiting to receive data" << endl << endl;
    return ((genericState*) new ST_ReceiveData());
};
