#ifndef ST_S_DATA_HPP
#define ST_S_DATA_HPP

#include "genericState.hpp"

class ST_SendData : public genericState
{
public:

	ST_SendData();

    genericState* on_SendData(genericEvent* ev);
	genericState* on_SendLastData(genericEvent* ev);
	genericState* on_SendError(genericEvent* ev);
	genericState* on_CloseServer(genericEvent* ev);
};


#endif // !ST_S_DATA_HPP

