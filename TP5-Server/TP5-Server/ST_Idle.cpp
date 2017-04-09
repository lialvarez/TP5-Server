#include <stdio.h>
#include "ST_Idle.hpp"
#include "ST_ReceiveWRQAck.hpp"
#include "ST_ReceiveFirstData.hpp"

using namespace std;

genericState* ST_Idle::on_SendWRQ(genericEvent *ev)
{
	executedAction = "WRQ Sent";
    //cout << "Previous state: idle" << endl << "Event received: s_wrq, an WRQ was sent" << endl << "New state: ReceiveWRQAck" << endl << endl;
    return ((genericState*) new ST_ReceiveWRQAck());
};
genericState* ST_Idle::on_SendRRQ(genericEvent *ev)
{
	executedAction = "RRQ Sent";
    //cout << "Previous state: idle" << endl << "Event received: s_rrq, an RRQ was sent" << endl << "New state: ReceiveFirstData" << endl << endl;
    return ((genericState*) new ST_ReceiveFirstData());
};
