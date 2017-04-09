#ifndef EV_S_ACK_HPP
#define EV_S_ACK_HPP

#include "genericEvent.hpp"

class EV_SendAck : public genericEvent
{
public:
	EV_SendAck() { ev = S_ACK; }

};

#endif // !EV_S_ACK_HPP
