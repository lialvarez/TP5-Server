#include "Server.hpp"
#include "EV_ReceiveRRQ.hpp"
#include "EV_ReceiveWRQ.hpp"
#include "EV_ReceiveAck.hpp"
#include "EV_ReceiveData.hpp"
#include "EV_ReceiveLastData.hpp"
#include "EV_Timeout.hpp"
#include "EV_SendData.hpp"
#include "EV_SendLastData.hpp"
#include "EV_SendAck.hpp"



Server::Server()
{
	receivedEvent = "Esperando EVENTO";
	lastEvent = "N/A";
	executedAction = "N/A";
	winTest = initscr();
}

genericEvent* Server::eventGenerator()
{
	char c;
	nodelay(winTest, true);
	noecho();

	while ((c = getch()) != ERR)
	{
		c = tolower(c);
		switch (c)
		{
		case 'w':
			receivedEvent = "Receive WRQ";
			return ((genericEvent *) new (EV_ReceiveWRQ));
			break;
		case 'r':
			receivedEvent = "Receive RRQ";
			return ((genericEvent *) new (EV_ReceiveRRQ));;
			break;
		case 'e':
			receivedEvent = "Send DATA";
			return ((genericEvent *) new (EV_SendData));;
			break;
		case 'y':
			receivedEvent = "Send LAST DATA";
			return ((genericEvent *) new (EV_SendLastData));
			break;
		case 'q':
			receivedEvent = "Send ACK";
			return ((genericEvent *) new (EV_SendAck));;
			break;
		case 'a':
			receivedEvent = "ACK";
			return ((genericEvent *) new (EV_ReceiveAck));;
			break;
		case 'd':
			receivedEvent = "DATA";
			return ((genericEvent *) new (EV_ReceiveData));;
			break;
		case 's':
			receivedEvent = "LAST DATA";
			return ((genericEvent *) new (EV_ReceiveLastData));;
			break;
		case 't':
			receivedEvent = "TIMEOUT";
			return ((genericEvent *) new (EV_Timeout));;
			break;
		default:
			return nullptr;
			break;
		}
	}
	return nullptr;
}

void Server::setReceivedEvent(string receivedEvent)
{
	this->receivedEvent = receivedEvent;
}

void Server::setLastEvent(string lastEvent)
{
	this->lastEvent = lastEvent;
}

void Server::setExecutedAction(string executedAction)
{
	this->executedAction = executedAction;
}

string Server::getExecutedAction()
{
	return executedAction;
}

string Server::getLastEvent()
{
	return lastEvent;
}

string Server::getReceivedevent()
{
	return receivedEvent;
}

