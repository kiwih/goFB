// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block TickGen
#ifndef TICKGEN_H_
#define TICKGEN_H_

#include "fbtypes.h"



//This is a BFB, so we need an enum type for the state machine
enum TickGen_states { STATE_TickGen_Start, STATE_TickGen_setup, STATE_TickGen_emit };


//this block had no input events


union TickGenOutputEvents {
	struct {
		UDINT Tick;
	} event;
	
};


typedef struct {
    //input events
	

    //output events
	union TickGenOutputEvents outputEvents;

    //input vars
	LREAL SetDeltaTime;
    
    //output vars
	LREAL DeltaTime;
    
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum TickGen_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	

	
} TickGen_t;

//all FBs get a preinit function
int TickGen_preinit(TickGen_t  *me);

//all FBs get an init function
int TickGen_init(TickGen_t  *me);

//all FBs get a run function
void TickGen_run(TickGen_t  *me);



#endif