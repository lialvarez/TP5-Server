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

#define ESC 27

Server::Server()
{
	receivedEvent = "Esperando EVENTO";
	lastEvent = "N/A";
	executedAction = "N/A";
	winTest = initscr();
}

genericEvent* Server::eventGenerator()
{
    char c;                 //variable que contiene a la tecla presionada
    nodelay(winTest, true); //establece el modo no bloqueante de lectura de teclado
    noecho();               //permite presionar teclas sin generar cambios en la pantalla

	do
	{
		c = getch();        //devuelve ERR cuando no se apreta ninguna tecla
		c = tolower(c);
        switch (c)
        {
        case ESC:
            receivedEvent = "Close Server";
            return ((genericEvent*) new (EV_CloseServer));
            break;
        case 'w':
			receivedEvent = "WRQ";
			return ((genericEvent *) new (EV_ReceiveWRQ));
			break;
		case 'r':
			receivedEvent = "RRQ";
			return ((genericEvent *) new (EV_ReceiveRRQ));;
			break;
		case 'e':
			receivedEvent = "Send Data";
			return ((genericEvent *) new (EV_SendData));;
			break;
		case 'y':
			receivedEvent = "Send Last Data";
			return ((genericEvent *) new (EV_SendLastData));
			break;
		case 'q':
			receivedEvent = "Send Ack.";
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
		default:    //si se apreto alguna tecla no mapeada, indicar que debe seguir leyendo el teclado
			c = ERR;
			break;
		}
	} while (c == ERR); //dejar de leer el teclado ua vez que se aprete una tecla valida
}

//SETTERS
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

//GETTERS
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

//GRAFICA LA PANTALLA INICIAL CORRESPONDIENTE A LA SIMULACION DEL SERVER//
void Server::startScreen()
{
	curs_set(0);
	char *Events[30] = { "W = WRQ","R = RRQ","E = Send Data","Y = Send Last Data","Q = Send Ack.","Z = Send Error", "A = Ack","D = Data","S = Last Data","T = Timeout", "X = Error", "ESC = Close Server" };
	char *fsmStates[30] = { "FSM Status:", "Evento Recibido: ","Ultimo Evento Recibido: ","Accion Ejecutada: " };
	{
		start_color();
		init_pair(1, COLOR_WHITE, COLOR_BLACK);
		init_pair(2, COLOR_BLUE, COLOR_WHITE);
		init_pair(3, COLOR_GREEN, COLOR_BLACK);
		init_pair(4, COLOR_GREEN, COLOR_BLACK);
		init_pair(5, COLOR_GREEN, COLOR_WHITE);
		immedok(winTest, TRUE);
	}

	//Se imprime la pantalla inicial que mostrara el estado de la FSM y las teclas correspondientes a los eventos//
	color_set(2, NULL);
	move(1, LEFTMARGIN1);
	printw("Instituto Tecnologico de Buenos Aires");
	color_set(1, NULL);
	move(2, LEFTMARGIN1);
	printw("Grupo 4 : Lisando Alvarez, Maria Luz Stewart Harris y Nicolas Mestanza");
	move(4, LEFTMARGIN1); 
	color_set(3, NULL);
	printw("Server.exe");
	move(5, LEFTMARGIN1);
	printw("Programa de simulacion de servidor TFTP implementado con FSM");
	move(7, LEFTMARGIN1); 
	color_set(1, NULL);
	printw("Cuando el usuario presiona las teclas de eventos entiende que se genero un nuevo evento");
	move(8, LEFTMARGIN1);
	printw("y responde ante ese evento realizando una accion y cambiando el estado.");
	move(11, LEFTMARGIN1); 
	color_set(2, NULL);
	printw("Eventos:");
	move(11, LEFTMARGIN2);
	printw("%s", "FSM Info:");
	color_set(1, NULL);

	for (int i = 0; i < 12; i++)
	{
		move(i + (FIRSTLINE + INTERSPACING), LEFTMARGIN1);
		printw("%s", Events[i]);
	}

	for (int i = 0; i < winTest->_maxx; i++)
	{
		move(FIRSTLINE - 1, i);
		printw("%c", '*');
	}

	for (int i = FIRSTLINE; i < winTest->_maxy; i++)
	{
		move(i, LEFTMARGIN2 - INTERSPACING);
		printw("%c", '*');
	}

	for (int i = 0; i < 4; i++)
	{
		move(FIRSTLINE + 4 + i*INTERSPACING, LEFTMARGIN2);
		printw("%s", fsmStates[i]);
	}
	return;
}
