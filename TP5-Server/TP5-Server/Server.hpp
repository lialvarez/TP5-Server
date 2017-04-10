#ifndef SERVER_HPP
#define SERVER_HPP

#include "genericEvent.hpp"
#include <string>
#include <curses.h>

using namespace std;

class Server
{
public:
	Server();

	genericEvent *eventGenerator();
	void setReceivedEvent(string receivedEvent);
	void setLastEvent(string lastEvent);
	void setExecutedAction(string executedAction);
	void startScreen(void);

	string getReceivedevent();
	string getLastEvent();
	string getExecutedAction();

protected:

	string receivedEvent;
	string lastEvent;
	string executedAction;
	WINDOW * winTest;

};

#endif // !SERVER_HPP


