#ifndef SERVER_HPP
#define SERVER_HPP

#include "genericState.hpp"
#include <string>
#include <vector>
#include "curses.h"

#define FIRSTLINE 11
#define INTERSPACING 2
#define LEFTMARGIN1 1
#define LEFTMARGIN2 45
#define LEFTMARGIN3 70

using namespace std;


class Server
{
public:
	Server();

	genericEvent* eventGenerator();
	void setReceivedEvent(string receivedEvent);
	void setLastEvent(string lastEvent);
	void setExecutedAction(string executedAction);
	void setCurrentState(string currentState);
	void startScreen(void);

	string getCurrentState();
	string getReceivedevent();
	string getLastEvent();
	string getExecutedAction();


private:


	string receivedEvent;
	string lastEvent;
	string executedAction;
	string currentState;
	WINDOW * winTest;

};
#endif // !SERVER_HPP
