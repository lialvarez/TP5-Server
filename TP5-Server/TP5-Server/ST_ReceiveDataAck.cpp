#include <stdio.h>
#include "ST_ReceiveDataAck.hpp"
#include "ST_SendData.hpp"

using namespace std;

genericState* ST_ReceiveDataAck :: on_ReceiveAck(genericEvent* ev)
{
    return ((genericState*) new ST_SendData());
};
genericState* ST_ReceiveDataAck :: on_timeout(genericEvent* ev)
{
    return ((genericState*) new ST_ReceiveDataAck());
};
