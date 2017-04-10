#include "ST_SendAck.hpp"
#include "ST_ReceiveData.hpp"

genericState* ST_SendAck::on_SendAck(genericEvent* ev)
{
	executedAction = "ACK Sent";
	return ((genericState*) new ST_ReceiveData());
}
