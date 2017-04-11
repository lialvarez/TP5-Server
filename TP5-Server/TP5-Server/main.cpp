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

using namespace std;

void refreshScreen(Server server);

void main()
{

	Server server;
	genericFSM FSM;
	genericEvent *ev = nullptr; //Variable que va a apuntar evento recibido

	server.startScreen();		//Seteo pantalla inicial
	do 
	{
		server.setCurrentState(FSM.getCurrentState()->currentState);    //actualizar el estado actual en el server
		refreshScreen(server);          //mostrar la info actual del server en la pantalla

		ev = server.eventGenerator();   //obtener el evento
		FSM.Dispatch(ev);               //realizar las acciones correspondientes, y de ser necesario, cambiar de estado actual

		refreshScreen(server);          //mostrar la info actual del server en pantalla
		Sleep(1000);                    //dejar un segundo d eintervalo para poder ver los cambios en la info del server

		server.setExecutedAction((FSM.getCurrentState())->executedAction);  //cargar la rutina de ccion correspondiente
		refreshScreen(server);          //mostrar la info actual del server en pantalla
		Sleep(2000);                    // dejar un segundo de intervalo para poder ver los cambios en la info del server

		server.setExecutedAction("N/A");
		server.setLastEvent(server.getReceivedevent());
		server.setReceivedEvent("Esperando EVENTO");

	} while ((FSM.getCurrentState())->getLastEvent() != CLOSE_SERVER);  //cuando se recibe el evento CLOSE_SERVER, salir
	Sleep(2000);
}

void refreshScreen(Server server)
{
	int currentLine = FIRSTLINE + 4;

	color_set(4, NULL);
	move(currentLine, LEFTMARGIN3);
	clrtoeol();
	printw("%s", server.getCurrentState().c_str());

	currentLine += INTERSPACING;
	move(currentLine, LEFTMARGIN3);
	clrtoeol();
	printw("%s", server.getReceivedevent().c_str());

	currentLine += INTERSPACING;
	move(currentLine, LEFTMARGIN3);
	clrtoeol();
	printw("%s", server.getLastEvent().c_str());

	currentLine += INTERSPACING;
	move(currentLine, LEFTMARGIN3);
	clrtoeol();
	printw("%s", server.getExecutedAction().c_str());

	refresh();
}
