#include <stdio.h>
#include "ST_ReceiveLastDataAck.hpp"
#include "ST_Idle.hpp"

using namespace std;

genericState* ST_ReceiveLastDataAck :: on_ReceiveAck(genericEvent* ev)
{
    cout << "Previous state: Waiting to receive last data ACK" << endl << "Event received: received ACK" << endl << "New state: Idle" << endl << endl;
    return ((genericState*) new ST_Idle());
};
genericState* ST_ReceiveLastDataAck :: on_timeout(genericEvent* ev)
{
    cout << "Previous state: Waiting to receive last data ACK" << endl << "Event received: timeout. Data was resent" << endl << "New state: Waiting to receive last data ACK" << endl << endl;
    return ((genericState*) new ST_ReceiveLastDataAck());
};
