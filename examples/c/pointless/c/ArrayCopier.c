// This file has been automatically generated by goFB and should not be edited by hand
// Transpiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for ArrayCopier
#include "ArrayCopier.h"




/* ArrayCopier_init() is required to be called to 
 * initialise an instance of ArrayCopier. 
 * It sets all I/O values to zero.
 */
void ArrayCopier_init(struct ArrayCopier *me) {
	//if there are input events, reset them
	me->inputEvents.events[0] = 0;
	
	//if there are output events, reset them
	me->outputEvents.events[0] = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are fb children (CFBs only), call this same function on them
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_ArrayCopier_start;
	
}



/* ArrayCopier_run() executes a single tick of an
 * instance of ArrayCopier according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void ArrayCopier_run(struct ArrayCopier *me) {
	//if there are output events, reset them
	me->outputEvents.events[0] = 0;
	
	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_ArrayCopier_start:
			if(true) {
				me->_state = STATE_ArrayCopier_set;
				me->_trigger = true;
			};
			break;
		case STATE_ArrayCopier_set:
			if(true) {
				me->_state = STATE_ArrayCopier_Loop;
				me->_trigger = true;
			};
			break;
		case STATE_ArrayCopier_Loop:
			if(me->inputEvents.event.in) {
				me->_state = STATE_ArrayCopier_Loop;
				me->_trigger = true;
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_ArrayCopier_start:
			me->outputEvents.event.set_default_out = 1;
			break;

		case STATE_ArrayCopier_set:
			ArrayCopier_setArray(me);
			me->outputEvents.event.out = 1;
			break;

		case STATE_ArrayCopier_Loop:
			ArrayCopier_moveArray(me);
			me->outputEvents.event.out = 1;
			break;

		
		}
	}

	me->_trigger = false;
}

//algorithms

void ArrayCopier_moveArray(struct ArrayCopier *me) {
me->out_var[0] = me->in_var[0];
me->out_var[1] = me->in_var[1];
me->out_var[2] = me->in_var[2];
me->out_var[3] = me->in_var[3];

printf("Set to %i %i %i %i\n", me->out_var[0], me->out_var[1], me->out_var[2], me->out_var[3]);
}

void ArrayCopier_setArray(struct ArrayCopier *me) {
me->out_var[0] = me->default_var[0];
me->out_var[1] = me->default_var[1];
me->out_var[2] = me->default_var[2];
me->out_var[3] = me->default_var[3];

}



