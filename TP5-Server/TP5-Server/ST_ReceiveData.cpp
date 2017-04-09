#include <stdio.h>
#include "ST_ReceiveData.hpp"
#include "ST_SendDataAck.hpp"
#include "ST_SendLastDataAck.hpp"

using namespace std;

genericState* ST_ReceiveData :: on_timeout(genericEvent* ev)
{
	cout << "Previous state: Waiting to receive data " << endl << "Event received: first timeout. ACK was resent " << endl << "New state: Waiting to receive data" << endl << endl;
	return ((genericState*) new ST_ReceiveData());
};

genericState* ST_ReceiveData :: on_ReceiveData(genericEvent* ev)
{
    cout << "Previous state: Waiting to receive data" << endl << "Event received: data was received" << endl << "New state: Waiting to send ACK" << endl << endl;
    return ((genericState*) new ST_SendDataAck());
};

genericState* ST_ReceiveData :: on_ReceiveLastData(genericEvent* ev)
{
    cout << "Previous state: Waiting to receive data" << endl << "Event received: last data was received" << endl << "New state: Waiting to send last ACK" << endl << endl;
    return ((genericState*) new ST_SendLastDataAck());
};
