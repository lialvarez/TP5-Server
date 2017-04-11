#include <stdlib.h>
#include "curses.h"
#include "Server.hpp"
#include "genericFSM.hpp"
#include "genericState.hpp"
#include "genericEvent.hpp"
#include "ST_Idle.hpp"
#include "ST_SendWRQAck.hpp"
#include "ST_SendData.hpp"
#include "ST_ReceiveDataAck.hpp"
#include "ST_SendLastDataAck.hpp"
#include <string>
#include <windows.h>

#define FIRSTLINE 10
#define INTERSPACING 2
#define LEFTMARGIN 70

using namespace std;

void refreshScreen(Server server);

void main()
{

	Server server;
	genericFSM FSM;
	genericEvent *ev = nullptr;

	server.startScreen();														//Seteo pantalla inicial//
	do 
	{
		server.setCurrentState(FSM.getCurrentState()->currentState);
		refreshScreen(server);

		ev = server.eventGenerator();
		FSM.Dispatch(ev);

		refreshScreen(server);
		Sleep(1000);

		server.setExecutedAction((FSM.getCurrentState())->executedAction);
		refreshScreen(server);
		Sleep(1000);

		server.setExecutedAction("N/A");
		server.setLastEvent(server.getReceivedevent());
		server.setReceivedEvent("Esperando EVENTO");
		Sleep(1000);

	} while ((FSM.getCurrentState())->getLastEvent() != CLOSE_SERVER);
	Sleep(2000);
}

void refreshScreen(Server server)
{
	int currentLine = FIRSTLINE;

	color_set(3, NULL);
	move(currentLine, LEFTMARGIN);
	clrtoeol();
	printw("%s", server.getCurrentState().c_str());

	currentLine += INTERSPACING;
	move(currentLine, LEFTMARGIN);
	clrtoeol();
	printw("%s", server.getReceivedevent().c_str());

	currentLine += INTERSPACING;
	move(currentLine, LEFTMARGIN);
	clrtoeol();
	printw("%s", server.getLastEvent().c_str());

	currentLine += INTERSPACING;
	move(currentLine, LEFTMARGIN);
	clrtoeol();
	printw("%s", server.getExecutedAction().c_str());

	refresh();
}

/* 
 Che pregunta. que pasa si yo soy servere en rrq y mande el last data ack? si vuelvo a idle al toque, nunca me voy a enterar
 si el servidor quizas no le llego mi ack y me reenvia su last data. Importa? porque yo tengo todos los datos que queria, pero
 el servidor no sabe eso. PARA REFLEXIONAR NOSIERTO?
 */

/* Che pregunta 2. timeout es un evento que se envia a mano? no hace falta poner un timer que controle, no? */
