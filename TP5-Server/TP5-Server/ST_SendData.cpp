#include <stdio.h>
#include "ST_SendData.hpp"
#include "ST_ReceiveDataAck.hpp"
#include "ST_ReceiveLastDataAck.hpp"

using namespace std;

genericState* ST_SendData :: on_SendData(genericEvent* ev)
{
	executedAction = "DATA Sent";
    //cout << "Previous state: Waiting to send data" << endl << "Event received: send data. Data was sent" << endl << "New state: Waiting to receive data ACK" << endl << endl;
    return ((genericState*) new ST_ReceiveDataAck());
};
genericState* ST_SendData :: on_SendLastData(genericEvent* ev)
{
	executedAction = "LAST DATA Sent";
    //cout << "Previous state: Waiting to send data" << endl << "Event received: send last data. Last data was sent" << endl << "New state: Waiting to receive last data ACK" << endl << endl;
    return ((genericState*) new ST_ReceiveLastDataAck());
};


