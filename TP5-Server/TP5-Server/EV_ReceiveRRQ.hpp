#ifndef EV_R_RRQ_HPP
#define EV_R_RRQ_HPP

#include "genericEvent.hpp"

class EV_ReceiveRRQ :public genericEvent
{
public:
	EV_ReceiveRRQ() { ev = R_RRQ; }

private:

};

#endif // !EV_R_RRQ_HPP
