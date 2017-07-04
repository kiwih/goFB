// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block Train1
#ifndef TRAIN1_H_
#define TRAIN1_H_

#include "fbtypes.h"
#include "util.h"


#include "cvode/cvode.h"
#include "nvector/nvector_serial.h"
#include "cvode/cvode_dense.h"
#include "sundials/sundials_dense.h"
#include "sundials/sundials_types.h"


//This is a BFB, so we need an enum type for the state machine
enum Train1_states { STATE_Train1_Start, STATE_Train1_State1E0, STATE_Train1_State1, STATE_Train1_State2E0, STATE_Train1_State2, STATE_Train1_State3E0, STATE_Train1_State3, STATE_Train1_State1E1 };


union Train1InputEvents {
	struct {
		UDINT update;
	} event;
	
};


union Train1OutputEvents {
	struct {
		UDINT update_t;
	} event;
	
};


typedef struct {
    //input events
	union Train1InputEvents inputEvents;

    //output events
	union Train1OutputEvents outputEvents;

    //input vars
	LREAL x;
    LREAL DeltaTime;
    
    //output vars
	LREAL y;
    
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum Train1_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	//this block uses cvode
	void *cvode_mem;
	N_Vector ode_solution;
	realtype T0;
	realtype Tnext;
	realtype Tcurr;
	int solveInProgress;
	

	
} Train1_t;

//all FBs get a preinit function
int Train1_preinit(Train1_t  *me);

//all FBs get an init function
int Train1_init(Train1_t  *me);

//all FBs get a run function
void Train1_run(Train1_t  *me);



#endif