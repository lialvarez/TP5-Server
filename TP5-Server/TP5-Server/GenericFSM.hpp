#ifndef genericFSM_hpp
#define genericFSM_hpp

#include <stdio.h>
#include "genericEvent.hpp"
#include "genericState.hpp"
#include "Screen.hpp"

class genericFSM
{
public:
	void Dispatch(genericEvent* ev);
	genericState* getCurrentState();
protected:
	genericState* currentState;
};
#endif /* genericFSM_hpp */
