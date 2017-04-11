#ifndef R_FIRST_DATA_HPP
#define R_FIRST_DATA_HPP

#include "genericState.hpp"

class ST_ReceiveFirstData : public genericState
{
public:

	ST_ReceiveFirstData();

	genericState* on_timeout(genericEvent* ev);
	genericState* on_ReceiveData(genericEvent* ev);
	genericState* on_ReceiveError(genericEvent* ev);

};

#endif // !R_FIRST_DATA_HPP
