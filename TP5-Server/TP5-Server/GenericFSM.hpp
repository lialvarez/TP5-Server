#ifndef genericFSM_hpp
#define genericFSM_hpp

#include <stdio.h>
#include "genericEvent.hpp"
#include "genericState.hpp"


class genericFSM
{
public:

	genericFSM();   //Crea un estado al que apunta currentState
    ~genericFSM();  //Destruye el estado al que punta currentState

	void Dispatch(genericEvent* ev);    //llama a la funcion del estado al que apunta current state que responde al evento recibido
	genericState* getCurrentState();
protected:
	genericState* currentState;
};
#endif /* genericFSM_hpp */
