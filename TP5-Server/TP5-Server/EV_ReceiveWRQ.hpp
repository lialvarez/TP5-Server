#ifndef EV_R_WRQ_HPP
#define EV_R_WRQ_HPP

#include "genericEvent.hpp"

class EV_ReceiveWRQ:public genericEvent
{
public:
	EV_ReceiveWRQ() { ev = R_WRQ; }

private:

};

#endif // !EV_R_WRQ_HPP
