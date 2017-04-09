#ifndef EV_R_DATA_HPP
#define EV_R_DATA_HPP

#include "genericEvent.hpp"

class EV_ReceiveData:public genericEvent
{
public:
	EV_ReceiveData() { ev = R_DATA; }

};



#endif // !EV_R_DATA_HPP

