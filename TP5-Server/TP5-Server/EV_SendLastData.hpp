#ifndef EV_S_LAST_DATA_HPP
#define EV_S_LAST_DATA_HPP

#include "genericEvent.hpp"

class EV_SendLastData:public genericEvent
{
public:
	EV_SendLastData() { ev = S_LAST_DATA; }

};

#endif // !EV_S_LAST_DATA_HPP
