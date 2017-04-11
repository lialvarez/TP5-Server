#ifndef SERVER_HPP
#define SERVER_HPP

#include "genericState.hpp"
#include <string>
#include <vector>
#include "curses.h"

#define FIRSTLINE 11    //primera linea del listado de eventos
#define INTERSPACING 2  //separacion utilizada en varias secciones de la pantalla
#define LEFTMARGIN1 1
#define LEFTMARGIN2 45
#define LEFTMARGIN3 70

using namespace std;

/* Clase Server:
 * Contiene la funcion eventGenerator() encargada de tomar los eventos de teclado
 * Contiene strings que guardan la informacion del evento recibido, el ultimo evento recibido, la accion
 * ejecutada, y el estado actual.
 */
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
