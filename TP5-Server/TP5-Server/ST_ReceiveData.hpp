#ifndef ST_R_DATA_HPP
#define ST_R_DATA_HPP

#include "genericState.hpp"

class ST_ReceiveData : public genericState
{
public:
	genericState* on_timeout(genericEvent* ev);
	genericState* on_ReceiveData(genericEvent* ev);
	genericState* on_ReceiveLastData(genericEvent* ev);
};

#endif // !ST_R_DATA_HPP
