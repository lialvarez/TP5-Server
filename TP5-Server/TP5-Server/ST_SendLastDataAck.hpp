#ifndef ST_S_LAST_DATA_ACK_HPP
#define ST_S_LAST_DATA_ACK_HPP

#include "genericState.hpp"

class ST_SendLastDataAck : public genericState
{
public:
	genericState* on_SendAck(genericEvent* ev);
private:

};

#endif // !ST_S_LAST_DATA_ACK_HPP
