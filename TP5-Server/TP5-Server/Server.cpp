#include "Server.hpp"
#include "EV_ReceiveWRQ.hpp"
#include "EV_ReceiveRRQ.hpp"
#include "EV_SendData.hpp"
#include "EV_SendLastData.hpp"
#include "EV_SendAck.hpp"
#include "EV_SendAck.hpp"
#include "EV_ReceiveAck.hpp"
#include "EV_ReceiveData.hpp"
#include "EV_ReceiveLastData.hpp"
#include "EV_Timeout.hpp"
#include "EV_SendError.hpp"
#include "EV_ReceiveError.hpp"
#include "EV_CloseServer.hpp"

Server::Server()
{
	receivedEvent = "Esperando EVENTO";
	lastEvent = "N/A";
	executedAction = "N/A";
	WINDOW * winTest = initscr();
}

genericEvent* Server::eventGenerator()
{
	char c;
	nodelay(winTest, true);
	noecho();

	do
	{
		c = getch();
		c = tolower(c);
		if (c == 27)
		{
			receivedEvent = "Server Closed";
			return ((genericEvent *) new (EV_CloseServer));
		}
		switch (c)
		{
		case 'w':
			receivedEvent = "WRQ";
			return ((genericEvent *) new (EV_ReceiveWRQ));
			break;
		case 'r':
			receivedEvent = "RRQ";
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
			receivedEvent = "Ack.";
			return ((genericEvent *) new (EV_ReceiveAck));;
			break;
		case 'd':
			receivedEvent = "Data";
			return ((genericEvent *) new (EV_ReceiveData));;
			break;
		case 's':
			receivedEvent = "Last Data";
			return ((genericEvent *) new (EV_ReceiveLastData));;
			break;
		case 't':
			receivedEvent = "Timeout";
			return ((genericEvent *) new (EV_Timeout));;
			break;
		case 'z':
			receivedEvent = "Send Error";
			return ((genericEvent*) new (EV_SendError));
			break;
		case 'x':
			receivedEvent = "Error";
			return ((genericEvent*) new (EV_ReceiveError));
			break;
		default:
			c = ERR;
			break;
		}
	} while (c == ERR);
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

void Server::setCurrentState(string currentState)
{
	this->currentState = currentState;
}

string Server::getCurrentState()
{
	return currentState;
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

//GRAFICA LA PANTALLA INICIAL CORRESPONDIENTE A LA SIMULACION DEL CLIENTE//
void Server::startScreen()
{
	curs_set(0);
	char *Events[30] = { "W = WRQ","R = RRQ","E = Send Data","Y = Send Last Data","Q = Send Ack.","Z = Send Error", "A = Ack","D = Data","S = Last Data","T = Timeout", "X = Error", "ESC = Close Server" };
	char *fsmStates[30] = { "Evento Recibido: ","Ultimo Evento Recibido: ","Accion Ejecutada: " };

	{
		start_color();
		init_pair(1, COLOR_WHITE, COLOR_BLACK);
		init_pair(2, COLOR_BLUE, COLOR_WHITE);
		init_pair(3, COLOR_GREEN, COLOR_BLACK);
		init_pair(4, COLOR_GREEN, COLOR_BLACK);
		immedok(winTest, TRUE);
	}

	//Se imprime la pantalla inicial que mostrara el estado de la FSM y las teclas correspondientes a los eventos//
	color_set(2, NULL);
	printw("Instituto Tecnologico de Buenos Aires");
	color_set(1, NULL); move(1, 0);
	printw("Grupo 4 : Lisando Alvarez, Maria Luz Stewart Harris y Nicolas Mestanza");
	move(3, 0); color_set(3, NULL);
	printw("Server.exe");
	move(4, 0);
	printw("Programa de simulacion de servidor TFTP implementado con FSM");
	move(6, 0); color_set(1, NULL);
	printw("Cuando el usuario presiona las teclas de eventos entiende que se genero un nuevo evento");
	move(7, 0);
	printw("y responde ante ese evento realizando una accion y cambiando el estado.");
	move(10, 0); color_set(1, NULL);
	printw("Eventos:"); move(10, 45); printw("Status de la FSM:");
	color_set(1, NULL);

	for (int i = 6; i<(12 + 6); i++)
	{
		move(6 + i, 0);
		printw("%s", Events[i - 6]);
	}

	for (int i = 6; i<(9); i++)
	{
		move(i * 2, 45);
		printw("%s", fsmStates[i - 6]);
	}
	return;
}