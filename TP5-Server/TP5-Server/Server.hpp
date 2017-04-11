#ifndef SERVER_HPP
#define SERVER_HPP

#include "genericState.hpp"
#include <string>
#include <vector>
#include "curses.h"

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
