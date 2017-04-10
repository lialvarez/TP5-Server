#include <stdio.h>
#include "ST_ReceiveLastDataAck.hpp"
#include "ST_Idle.hpp"

using namespace std;

genericState* ST_ReceiveLastDataAck :: on_ReceiveAck(genericEvent* ev)
{
    return ((genericState*) new ST_Idle());
};
genericState* ST_ReceiveLastDataAck :: on_timeout(genericEvent* ev)
{
    return ((genericState*) new ST_ReceiveLastDataAck());
};
