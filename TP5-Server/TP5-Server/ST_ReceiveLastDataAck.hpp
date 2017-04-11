#ifndef ST_R_LAST_DATA_ACK_HPP
#define ST_R_LAST_DATA_ACK_HPP

#include "genericState.hpp"

class ST_ReceiveLastDataAck : public genericState
{
public:

	ST_ReceiveLastDataAck();

	genericState* on_ReceiveAck(genericEvent* ev);
	genericState* on_timeout(genericEvent* ev);
	genericState* on_ReceiveError(genericEvent* ev);
};


#endif // !ST_R_LAST_DATA_ACK_HPP
