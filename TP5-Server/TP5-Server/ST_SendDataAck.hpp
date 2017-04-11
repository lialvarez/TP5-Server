#ifndef ST_S_DATA_ACK_HPP
#define ST_S_DATA_ACK_HPP

#include "genericState.hpp"

class ST_SendDataAck : public genericState
{
public:

	ST_SendDataAck();

	genericState* on_SendAck(genericEvent* ev);
	genericState* on_SendError(genericEvent* ev);
};
#endif // !ST_S_DATA_ACK_HPP
