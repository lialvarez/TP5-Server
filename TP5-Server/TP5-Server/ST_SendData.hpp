#ifndef ST_S_DATA_HPP
#define ST_S_DATA_HPP

#include "genericState.hpp"

class ST_SendData : public genericState
{
public:
    genericState* on_SendData(genericEvent* ev);
	genericState* on_SendLastData(genericEvent* ev);
};


#endif // !ST_S_DATA_HPP

