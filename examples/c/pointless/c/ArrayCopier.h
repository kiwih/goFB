// This file has been automatically generated by go-iec61499 and should not be edited by hand
// Converter written by Hammond Pearce and available at github.com/kiwih/go-iec61499

// This file represents the interface of Function Block ArrayCopier
#ifndef ARRAYCOPIER_H_
#define ARRAYCOPIER_H_

#include "fbtypes.h"

//This is a BFB, so we need an enum type for the state machine
enum ArrayCopier_states { STATE_start, STATE_set, STATE_Loop };


union ArrayCopierInputEvents {
	struct {
		UDINT in : 1;
		UDINT set_default_in : 1;
	} event;
	UDINT events[1];
};


union ArrayCopierOutputEvents {
	struct {
		UDINT out : 1;
		UDINT set_default_out : 1;
	} event;
	UDINT events[1];
};


struct ArrayCopier {
    //input events
	union ArrayCopierInputEvents inputEvents;

    //output events
	union ArrayCopierOutputEvents outputEvents;

    //input vars
	INT in_var[4];
    INT default_var[4];
    
    //output vars
	INT out_var[4];
    
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//state and trigger (BFBs only)
	enum ArrayCopier_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	
};

//all FBs get an init function
void ArrayCopier_init(struct ArrayCopier *me);

//all FBs get a run function
void ArrayCopier_run(struct ArrayCopier *me);


//basic FBs have a number of algorithm functions

void ArrayCopier_moveArray(struct ArrayCopier *me);

void ArrayCopier_setArray(struct ArrayCopier *me);


#endif