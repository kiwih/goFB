// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for SawmillControl
#include "SawmillControl.h"


/* SawmillControl_preinit() is required to be called to 
 * initialise an instance of SawmillControl. 
 * It sets all I/O values to zero.
 */
int SawmillControl_preinit(SawmillControl_t  *me) {
	//if there are input events, reset them
	me->inputEvents.event.ControlChange = 0;
	me->inputEvents.event.WeightChange = 0;
	me->inputEvents.event.LaserChange = 0;
	me->inputEvents.event.BadSpeedChange = 0;
	me->inputEvents.event.StallDetectedChange = 0;
	
	//if there are output events, reset them
	me->outputEvents.event.CommandChange = 0;
	me->outputEvents.event.MessageChange = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_SawmillControl_Start;
	

	return 0;
}

/* SawmillControl_init() is required to be called to 
 * set up an instance of SawmillControl. 
 * It passes around configuration data.
 */
int SawmillControl_init(SawmillControl_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



/* SawmillControl_run() executes a single tick of an
 * instance of SawmillControl according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void SawmillControl_run(SawmillControl_t  *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.CommandChange = 0;
	me->outputEvents.event.MessageChange = 0;
	

	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_SawmillControl_Start:
			if(true) {
				me->_state = STATE_SawmillControl_startup;
				me->_trigger = true;
				
			};
			break;
		case STATE_SawmillControl_startup:
			if(true) {
				me->_state = STATE_SawmillControl_await_command;
				me->_trigger = true;
				
			};
			break;
		case STATE_SawmillControl_check_weight:
			if( ! me->ScaleOverweight) {
				me->_state = STATE_SawmillControl_check_laser;
				me->_trigger = true;
				
			} else if(me->ScaleOverweight) {
				me->_state = STATE_SawmillControl_await_weight;
				me->_trigger = true;
				
			};
			break;
		case STATE_SawmillControl_check_laser:
			if( ! me->LaserBroken) {
				me->_state = STATE_SawmillControl_run;
				me->_trigger = true;
				
			} else if(me->LaserBroken) {
				me->_state = STATE_SawmillControl_await_laser;
				me->_trigger = true;
				
			} else if( ! me->ControlRun) {
				me->_state = STATE_SawmillControl_await_command;
				me->_trigger = true;
				
			};
			break;
		case STATE_SawmillControl_run:
			if(me->LaserBroken) {
				me->_state = STATE_SawmillControl_check_laser;
				me->_trigger = true;
				
			} else if(me->ScaleOverweight) {
				me->_state = STATE_SawmillControl_check_weight;
				me->_trigger = true;
				
			} else if(me->BadSpeed) {
				me->_state = STATE_SawmillControl_bad_speed;
				me->_trigger = true;
				
			} else if( ! me->ControlRun) {
				me->_state = STATE_SawmillControl_control_stop;
				me->_trigger = true;
				
			} else if(me->StallDetected) {
				me->_state = STATE_SawmillControl_stall_detected;
				me->_trigger = true;
				
			};
			break;
		case STATE_SawmillControl_await_weight:
			if( ! me->ScaleOverweight) {
				me->_state = STATE_SawmillControl_check_weight;
				me->_trigger = true;
				
			};
			break;
		case STATE_SawmillControl_await_laser:
			if( ! me->LaserBroken) {
				me->_state = STATE_SawmillControl_check_laser;
				me->_trigger = true;
				
			};
			break;
		case STATE_SawmillControl_await_command:
			if(me->inputEvents.event.ControlChange && (me->ControlRun)) {
				me->_state = STATE_SawmillControl_check_weight;
				me->_trigger = true;
				
			};
			break;
		case STATE_SawmillControl_bad_speed:
			if(true) {
				me->_state = STATE_SawmillControl_await_command;
				me->_trigger = true;
				
			};
			break;
		case STATE_SawmillControl_control_stop:
			if(true) {
				me->_state = STATE_SawmillControl_await_command;
				me->_trigger = true;
				
			};
			break;
		case STATE_SawmillControl_stall_detected:
			if(true) {
				me->_state = STATE_SawmillControl_await_command;
				me->_trigger = true;
				
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_SawmillControl_Start:
			break;

		case STATE_SawmillControl_startup:
			SawmillControl_SawStop(me);
			me->outputEvents.event.CommandChange = 1;
			SawmillControl_MessageStop(me);
			me->outputEvents.event.MessageChange = 1;
			break;

		case STATE_SawmillControl_check_weight:
			break;

		case STATE_SawmillControl_check_laser:
			break;

		case STATE_SawmillControl_run:
			SawmillControl_SawRun(me);
			me->outputEvents.event.CommandChange = 1;
			SawmillControl_MessageRun(me);
			me->outputEvents.event.MessageChange = 1;
			break;

		case STATE_SawmillControl_await_weight:
			SawmillControl_MessageHaltWeight(me);
			me->outputEvents.event.MessageChange = 1;
			SawmillControl_SawStop(me);
			me->outputEvents.event.CommandChange = 1;
			break;

		case STATE_SawmillControl_await_laser:
			SawmillControl_MessageHaltLaser(me);
			me->outputEvents.event.MessageChange = 1;
			SawmillControl_SawStop(me);
			me->outputEvents.event.CommandChange = 1;
			break;

		case STATE_SawmillControl_await_command:
			break;

		case STATE_SawmillControl_bad_speed:
			SawmillControl_MessageBadSpeed(me);
			me->outputEvents.event.MessageChange = 1;
			SawmillControl_SawStop(me);
			me->outputEvents.event.CommandChange = 1;
			break;

		case STATE_SawmillControl_control_stop:
			SawmillControl_MessageStop(me);
			me->outputEvents.event.MessageChange = 1;
			SawmillControl_SawStop(me);
			me->outputEvents.event.CommandChange = 1;
			break;

		case STATE_SawmillControl_stall_detected:
			SawmillControl_SawStop(me);
			me->outputEvents.event.CommandChange = 1;
			SawmillControl_MessageStallDetected(me);
			me->outputEvents.event.MessageChange = 1;
			break;

		
		}
	}

	me->_trigger = false;
}
//algorithms

void SawmillControl_MessageHaltWeight(SawmillControl_t  *me) {
me->Message = -1;
}

void SawmillControl_MessageHaltLaser(SawmillControl_t  *me) {
me->Message = -2;
}

void SawmillControl_MessageRun(SawmillControl_t  *me) {
me->Message = 1;
}

void SawmillControl_MessageStop(SawmillControl_t  *me) {
me->Message = 0;
}

void SawmillControl_SawRun(SawmillControl_t  *me) {
me->SawRun = 1;
}

void SawmillControl_SawStop(SawmillControl_t  *me) {
me->SawRun = 0;
}

void SawmillControl_MessageBadSpeed(SawmillControl_t  *me) {
me->Message = -4;
}

void SawmillControl_MessageStallDetected(SawmillControl_t  *me) {
me->Message = -3;
}



