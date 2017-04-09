#ifndef GENERIC_EVENT_HPP
#define GENERIC_EVENT_HPP

typedef enum { NO_EV, EV_EXIT, S_WRQ, S_RRQ, S_DATA, R_DATA, S_ACK, R_ACK, S_LAST_DATA, R_LAST_DATA, R_TIMEOUT } event_t;

class genericEvent
{
public:
	genericEvent() { ev = NO_EV; }
	event_t getEventType() { return ev; }

protected:
	event_t ev;
};


#endif // !GENERIC_EVENT_HPP
