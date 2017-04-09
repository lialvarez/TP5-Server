#include <stdio.h>
#include "ST_ReceiveDataAck.hpp"
#include "ST_SendData.hpp"

using namespace std;

genericState* ST_ReceiveDataAck :: on_ReceiveAck(genericEvent* ev)
{
    cout << "Previous state: Waiting to receive data ACK" << endl << "Event received: ACK" << endl << "New state: Waiting to send data" << endl << endl;
    return ((genericState*) new ST_SendData());
};
genericState* ST_ReceiveDataAck :: on_timeout(genericEvent* ev)
{
    cout << "Previous state: Waiting to receive data ACK" << endl << "Event received: timeout. Data was resent" << endl << "New state: Waiting to receive data ACK" << endl << endl;
    return ((genericState*) new ST_ReceiveDataAck());
};
