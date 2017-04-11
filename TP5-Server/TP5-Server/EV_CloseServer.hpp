#ifndef EV_CLOSE_SERVER_HPP
#define EV_CLOSE_SERVER_HPP

#include "genericEvent.hpp"

class EV_CloseServer: public genericEvent
{
public:
	EV_CloseServer() { ev = CLOSE_SERVER; }

private:

};

#endif // !EV_CLOSE_SERVER_HPP
