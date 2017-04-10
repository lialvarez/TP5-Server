#include <stdio.h>
#include "ST_ReceiveFirstData.hpp"
#include "ST_SendDataAck.hpp"

using namespace std;

genericState* ST_ReceiveFirstData :: on_timeout(genericEvent* ev)
{
    return ((genericState*) new ST_ReceiveFirstData());
};
genericState* ST_ReceiveFirstData :: on_ReceiveData(genericEvent* ev)
{
    return ((genericState*) new ST_SendDataAck());
};
