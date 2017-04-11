#ifndef EV_R_ERROR_HPP
#define EV_R_ERROR_HPP

#include "GenericEvent.hpp"

class EV_ReceiveError:public genericEvent
{
public:
	EV_ReceiveError() { ev = R_ERROR; }
};


#endif // !EV_R_ERROR_HPP
