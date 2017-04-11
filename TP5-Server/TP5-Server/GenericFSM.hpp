#ifndef genericFSM_hpp
#define genericFSM_hpp

#include <stdio.h>
#include "genericEvent.hpp"
#include "genericState.hpp"


class genericFSM
{
public:

	genericFSM();

	void Dispatch(genericEvent* ev);
	genericState* getCurrentState();
protected:
	genericState* currentState;
};
#endif /* genericFSM_hpp */
