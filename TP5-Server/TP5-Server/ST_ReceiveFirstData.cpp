#include <stdio.h>
#include "ST_ReceiveFirstData.hpp"
#include "ST_SendDataAck.hpp"

using namespace std;

genericState* ST_ReceiveFirstData :: on_timeout(genericEvent* ev)
{
    cout << "Previous state: Waiting to receive first data" << endl << "Event received: timeout. RRQ was resent" << endl << "New state: Waiting to receive first data" << endl << endl;
    return ((genericState*) new ST_ReceiveFirstData());
};
genericState* ST_ReceiveFirstData :: on_ReceiveData(genericEvent* ev)
{
    cout << "Previous state: Waiting to receive data ACK" << endl << "Event received: send data. Data was sent" << endl << "New state: Waiting to send data ACK" << endl << endl;
    return ((genericState*) new ST_SendDataAck());
};
