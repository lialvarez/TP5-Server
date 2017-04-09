#ifndef ST_R_WRQ_ACK_HPP
#define ST_R_WRQ_ACK_HPP

#include "genericState.hpp"

class ST_ReceiveWRQAck : public genericState
{
public:
	genericState* on_ReceiveAck(genericEvent* ev);
	genericState* on_timeout(genericEvent* ev);
};

#endif // !ST_R_WRQ_ACK_HPP
