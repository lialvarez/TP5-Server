#ifndef S_WRQ_ACK_HPP
#define S_WRQ_ACK_HPP

#include "GenericState.hpp"

class ST_SendWRQAck:public genericState
{
public:

	ST_SendWRQAck();

	genericState* on_SendAck(genericEvent* ev);
	genericState* on_SendError(genericEvent* ev);
	genericState* on_CloseServer(genericEvent* ev);

};


#endif // !S_WRQ_ACK_HPP
