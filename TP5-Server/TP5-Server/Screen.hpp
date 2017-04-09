#include <curses.h>

WINDOW *terminalScreen = NULL;	//Terminal donde voy a trabajar
//int xWinPos, yWinPos;			//Variable de posicion del cursor
/* comentar esta ultima linea me saca errores de linker de duplicado de variables, calculo que estos nombres ya estan usados. no se si es que es necesario cambiarles el nombre a estas o directamente se puede usar las variables dentro de la libreria */
