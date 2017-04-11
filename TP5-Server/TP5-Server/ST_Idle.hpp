#ifndef ST_IDLE_HPP
#define ST_IDLE_HPP

#include <iostream>
#include "genericEvent.hpp"
#include "genericState.hpp"

class ST_Idle:public genericState
{
public:

	ST_Idle();

	genericState* on_ReceiveWRQ(genericEvent *ev);
	genericState* on_ReceiveRRQ(genericEvent *ev);
	genericState* on_ReceiveError(genericEvent *ev);
	genericState* on_CloseServer(genericEvent* ev);
};


#endif // !ST_IDLE_HPP

