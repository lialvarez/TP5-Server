#include <stdio.h>
#include "ST_ReceiveData.hpp"
#include "ST_SendDataAck.hpp"
#include "ST_SendLastDataAck.hpp"

using namespace std;

genericState* ST_ReceiveData :: on_timeout(genericEvent* ev)
{
	return ((genericState*) new ST_ReceiveData());
};

genericState* ST_ReceiveData :: on_ReceiveData(genericEvent* ev)
{
    return ((genericState*) new ST_SendDataAck());
};

genericState* ST_ReceiveData :: on_ReceiveLastData(genericEvent* ev)
{
    return ((genericState*) new ST_SendLastDataAck());
};
