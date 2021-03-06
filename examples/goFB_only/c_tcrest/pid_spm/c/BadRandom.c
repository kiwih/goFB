// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for BadRandom
#include "BadRandom.h"


/* BadRandom_preinit() is required to be called to 
 * initialise an instance of BadRandom. 
 * It sets all I/O values to zero.
 */
int BadRandom_preinit(BadRandom_t _SPM *me) {
	//if there are input events, reset them
	
	//if there are output events, reset them
	me->outputEvents.event.RandomChange = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	me->Len = 10;
	me->Pos = 0;
	me->Vals[0] = 0.01;
	me->Vals[1] = 0.05;
	me->Vals[2] = -0.02;
	me->Vals[3] = 0.03;
	me->Vals[4] = -0.04;
	me->Vals[5] = -0.02;
	me->Vals[6] = 0.01;
	me->Vals[7] = 0.03;
	me->Vals[8] = -0.02;
	me->Vals[9] = -0.02;
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_BadRandom_Start;
	

	return 0;
}

/* BadRandom_init() is required to be called to 
 * set up an instance of BadRandom. 
 * It passes around configuration data.
 */
int BadRandom_init(BadRandom_t _SPM *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



//algorithms

void BadRandom_BadRandomRun(BadRandom_t _SPM *me) {
me->Random = me->Vals[me->Pos];

me->Pos++;

if(me->Pos >= me->Len) {
	me->Pos = 0;
}
}



/* BadRandom_run() executes a single tick of an
 * instance of BadRandom according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void BadRandom_run(BadRandom_t _SPM *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.RandomChange = 0;
	

	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_BadRandom_Start:
			if(true) {
				me->_state = STATE_BadRandom_r;
				me->_trigger = true;
				
			};
			break;
		case STATE_BadRandom_r:
			if(true) {
				me->_state = STATE_BadRandom_r;
				me->_trigger = true;
				
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_BadRandom_Start:
			break;

		case STATE_BadRandom_r:
			BadRandom_BadRandomRun(me);
			me->outputEvents.event.RandomChange = 1;
			break;

		
		}
	}

	me->_trigger = false;
}


