#ifndef ST_S_LAST_DATA_ACK_HPP
#define ST_S_LAST_DATA_ACK_HPP

#include "genericState.hpp"

class ST_SendLastDataAck : public genericState
{
public:

	ST_SendLastDataAck();

	genericState* on_SendAck(genericEvent* ev);
	genericState* on_SendError(genericEvent* ev);

};

#endif // !ST_S_LAST_DATA_ACK_HPP
