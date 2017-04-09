#ifndef ST_S_DATA_ACK_HPP
#define ST_S_DATA_ACK_HPP

#include "genericState.hpp"

class ST_SendDataAck : public genericState
{
public:
	genericState* on_SendAck(genericEvent* ev);
};
#endif // !ST_S_DATA_ACK_HPP
