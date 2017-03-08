// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for SawmillSpeed
#include "SawmillSpeed.h"


/* SawmillSpeed_preinit() is required to be called to 
 * initialise an instance of SawmillSpeed. 
 * It sets all I/O values to zero.
 */
int SawmillSpeed_preinit(SawmillSpeed_t _SPM *me) {
	//if there are input events, reset them
	me->inputEvents.event.NewPos = 0;
	
	//if there are output events, reset them
	me->outputEvents.event.BadSpeedChange = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_SawmillSpeed_Start;
	

	return 0;
}

/* SawmillSpeed_init() is required to be called to 
 * set up an instance of SawmillSpeed. 
 * It passes around configuration data.
 */
int SawmillSpeed_init(SawmillSpeed_t _SPM *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



/* SawmillSpeed_run() executes a single tick of an
 * instance of SawmillSpeed according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void SawmillSpeed_run(SawmillSpeed_t _SPM *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.BadSpeedChange = 0;
	

	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_SawmillSpeed_Start:
			if(true) {
				me->_state = STATE_SawmillSpeed_Run;
				me->_trigger = true;
				
			};
			break;
		case STATE_SawmillSpeed_Run:
			if(me->inputEvents.event.NewPos) {
				me->_state = STATE_SawmillSpeed_Run;
				me->_trigger = true;
				
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_SawmillSpeed_Start:
			break;

		case STATE_SawmillSpeed_Run:
			SawmillSpeed_speedChange_service(me);
			break;

		
		}
	}

	me->_trigger = false;
}
//algorithms

void SawmillSpeed_speedChange_service(SawmillSpeed_t _SPM *me) {
if(me->LastPos != 0) {
	if(me->Pos - me->LastPos > 2 || me->LastPos - me->Pos > 2) {
		me->outputEvents.event.BadSpeedChange = 1;
		me->BadSpeed = true;
	} else {
		me->outputEvents.event.BadSpeedChange = 1;
		me->BadSpeed = false;
	}
}

me->LastPos = me->Pos;
}


