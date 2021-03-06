// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block SawmillControl
#ifndef SAWMILLCONTROL_H_
#define SAWMILLCONTROL_H_

#include "fbtypes.h"

//This is a BFB, so we need an enum type for the state machine
enum SawmillControl_states { STATE_SawmillControl_Start, STATE_SawmillControl_startup, STATE_SawmillControl_check_weight, STATE_SawmillControl_check_laser, STATE_SawmillControl_run, STATE_SawmillControl_await_weight, STATE_SawmillControl_await_laser, STATE_SawmillControl_await_command, STATE_SawmillControl_bad_speed, STATE_SawmillControl_control_stop, STATE_SawmillControl_stall_detected };


union SawmillControlInputEvents {
	struct {
		UDINT ControlChange;
		UDINT WeightChange;
		UDINT LaserChange;
		UDINT BadSpeedChange;
		UDINT StallDetectedChange;
	} event;
	
};


union SawmillControlOutputEvents {
	struct {
		UDINT CommandChange;
		UDINT MessageChange;
	} event;
	
};


typedef struct {
    //input events
	union SawmillControlInputEvents inputEvents;

    //output events
	union SawmillControlOutputEvents outputEvents;

    //input vars
	BOOL ControlRun;
    BOOL ScaleOverweight;
    BOOL LaserBroken;
    BOOL BadSpeed;
    BOOL StallDetected;
    
    //output vars
	BOOL SawRun;
    INT Message;
    
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum SawmillControl_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	
} SawmillControl_t;

//all FBs get a preinit function
int SawmillControl_preinit(SawmillControl_t  *me);

//all FBs get an init function
int SawmillControl_init(SawmillControl_t  *me);

//all FBs get a run function
void SawmillControl_run(SawmillControl_t  *me);

//basic FBs have a number of algorithm functions

void SawmillControl_MessageHaltWeight(SawmillControl_t  *me);

void SawmillControl_MessageHaltLaser(SawmillControl_t  *me);

void SawmillControl_MessageRun(SawmillControl_t  *me);

void SawmillControl_MessageStop(SawmillControl_t  *me);

void SawmillControl_SawRun(SawmillControl_t  *me);

void SawmillControl_SawStop(SawmillControl_t  *me);

void SawmillControl_MessageBadSpeed(SawmillControl_t  *me);

void SawmillControl_MessageStallDetected(SawmillControl_t  *me);


#endif
