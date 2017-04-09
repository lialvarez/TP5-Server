#ifndef EV_R_LAST_DATA_HPP
#define EV_R_LAST_DATA_HPP

#include "genericEvent.hpp"

class EV_ReceiveLastData:public genericEvent
{
public:
	EV_ReceiveLastData() { ev = R_LAST_DATA; }

};

#endif // !EV_R_LAST_DATA_HPP
