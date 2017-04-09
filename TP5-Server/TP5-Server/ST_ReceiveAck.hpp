#ifndef ST_R_ACK_HPP
#define ST_R_ACK_HPP

#include "GenericState.hpp"

class ST_ReceiveAck:public genericState
{
public:
	genericState* on_s_data_ack(genericEvent* ev);
	genericState* on_timeout(genericEvent* ev);

};


#endif // !ST_R_ACK_HPP
