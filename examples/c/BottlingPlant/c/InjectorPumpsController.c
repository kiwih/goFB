// This file has been automatically generated by go-iec61499 and should not be edited by hand
// Converter written by Hammond Pearce and available at github.com/kiwih/go-iec61499

// This file represents the implementation of the Basic Function Block for InjectorPumpsController
#include "InjectorPumpsController.h"

enum InjectorPumpsController_states { STATE_RejectCanister, STATE_AwaitPump, STATE_VacuumPump, STATE_FinishPump, STATE_StartPump, STATE_OpenValve, STATE_StopVacuum }

void InjectorPumpsController_init(struct InjectorPumpsController *me) {
	//if there are output events, reset them
	me->outputEvents.PumpFinished = 0;
	me->outputEvents.RejectCanister = 0;
	me->outputEvents.InjectorControlsChanged = 0;
	me->outputEvents.FillContentsChanged = 0;
	me->outputEvents.StartVacuumTimer = 0;
	
	//if there are output vars, reset them
	me->outputVars.InjectorContentsValveOpen = 0;
	me->outputVars.InjectorVacuumRun = 0;
	me->outputVars.InjectorPressurePumpRun = 0;
	me->outputVars.FillContents = 0;
	
	//if there are internal vars, reset them
	
}

void InjectorPumpsController_run(struct InjectorPumpsController *me) {
	//current state storage
	static enum InjectorPumpsController_states state = STATE_RejectCanister;
	static BOOL trigger = false;

	//if there are output events, reset them
	me->outputEvents.PumpFinished = 0;
	me->outputEvents.RejectCanister = 0;
	me->outputEvents.InjectorControlsChanged = 0;
	me->outputEvents.FillContentsChanged = 0;
	me->outputEvents.StartVacuumTimer = 0;
	

	//now, let's advance state
	switch(state) {
	case STATE_RejectCanister :
		if(true) {
			state = STATE_AwaitPump;
			trigger = true;
		};
	case STATE_AwaitPump :
		if(me->inputEvents.StartPump) {
			state = STATE_VacuumPump;
			trigger = true;
		};
	case STATE_VacuumPump :
		if(me->inputEvents.VacuumTimerElapsed) {
			state = STATE_RejectCanister;
			trigger = true;
		} else if(me->inputEvents.CanisterPressureChanged AND (CanisterPressure<=10)) {
			state = STATE_StopVacuum;
			trigger = true;
		};
	case STATE_FinishPump :
		if(true) {
			state = STATE_AwaitPump;
			trigger = true;
		};
	case STATE_StartPump :
		if(me->inputEvents.CanisterPressureChanged AND (CanisterPressure>=245)) {
			state = STATE_FinishPump;
			trigger = true;
		};
	case STATE_OpenValve :
		if(true) {
			state = STATE_StartPump;
			trigger = true;
		};
	case STATE_StopVacuum :
		if(true) {
			state = STATE_OpenValve;
			trigger = true;
		};
	
	}

	//now, let's run any algorithms and emit any events that need to occur due to the trigger
	if(trigger == true) {

	}
}

//algorithms

void InjectorPumpsController_StartVacuum(struct InjectorPumpsController *me) {
InjectorVacuumRun <= '1';
 DONE <= '1';
}

void InjectorPumpsController_ClearControls(struct InjectorPumpsController *me) {
InjectorContentsValveOpen <= '0';
 InjectorPressurePumpRun <= '0';
 InjectorVacuumRun <= '0';
 DONE <= '1';
}

void InjectorPumpsController_OpenValve(struct InjectorPumpsController *me) {
InjectorContentsValveOpen <= '1';
 DONE <= '1';
}

void InjectorPumpsController_StartPump(struct InjectorPumpsController *me) {
InjectorPressurePumpRun <= '1';
 DONE <= '1';
}


