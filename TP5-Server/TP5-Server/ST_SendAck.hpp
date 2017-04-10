#ifndef ST_S_ACK_HPP
#define ST_S_ACK_HPP

#include "GenericState.hpp"

class ST_SendAck:public genericState
{
public:
	genericState* on_SendAck(genericEvent* ev);
};

#endif // !ST_S_ACK_HPP
