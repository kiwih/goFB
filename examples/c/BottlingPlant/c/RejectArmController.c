// This file has been automatically generated by go-iec61499 and should not be edited by hand
// Converter written by Hammond Pearce and available at github.com/kiwih/go-iec61499

// This file represents the implementation of the Basic Function Block for RejectArmController
#include "RejectArmController.h"

enum RejectArmController_states { STATE_Clear, STATE_AwaitCanister, STATE_GoReject }

void RejectArmController_init(struct RejectArmController *me) {
	//if there are output events, reset them
	me->outputEvents.GoRejectArm[0] = 0;
	me->outputEvents->GoRejectArm[1] = 0;
	
	//if there are output vars, reset them
	
	//if there are internal vars, reset them
	
}

void RejectArmController_run(struct RejectArmController *me) {
	static enum RejectArmController_states state = STATE_Clear;
	//first, update variables that have changed based on the input events

	//now, let's advance state
	switch(state) {
	case STATE_Clear :
		if(*(me->inputEvents.RejectCanister)) {
			state <= STATE_AwaitCanister;
		};
	case STATE_AwaitCanister :
		if(*(me->inputEvents.LasersChanged) AND (me->inputVars.RejectSiteLaser)) {
			state <= STATE_GoReject;
		};
	case STATE_GoReject :
		if(*(me->inputEvents.RejectCanister)) {
			state <= STATE_AwaitCanister;
		};
	
	}
}

