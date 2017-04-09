#ifndef EV_R_TIMEOUT_HPP
#define EV_R_TIMEOUT_HPP

#include "genericEvent.hpp"

class EV_Timeout:public genericEvent
{
public:
	EV_Timeout() { ev = R_TIMEOUT; }

};

#endif // !EV_R_TIMEOUT_HPP
