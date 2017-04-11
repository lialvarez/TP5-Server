#ifndef EV_S_ERROR_HPP
#define EV_S_ERROR_HPP

#include "genericEvent.hpp"

class EV_SendError:public genericEvent
{
public:
	EV_SendError() { ev = S_ERROR; }

private:

};
#endif // !EV_S_ERROR_HPP
