#ifndef EV_R_ACK_HPP
#define EV_R_ACK_HPP

#include "genericEvent.hpp"

class EV_ReceiveAck:public genericEvent
{
public:
	EV_ReceiveAck() { ev = R_ACK; }

private:

};

#endif // !EV_R_ACK_HPP
