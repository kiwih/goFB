// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for Print
#include "Print.h"


/* Print_preinit() is required to be called to 
 * initialise an instance of Print. 
 * It sets all I/O values to zero.
 */
int Print_preinit(Print_t  *me) {
	//if there are input events, reset them
	me->inputEvents.event.CountChanged = 0;
	
	//if there are output events, reset them
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_Print_Start;
	

	return 0;
}

/* Print_init() is required to be called to 
 * set up an instance of Print. 
 * It passes around configuration data.
 */
int Print_init(Print_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



/* Print_run() executes a single tick of an
 * instance of Print according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void Print_run(Print_t  *me) {
	//if there are output events, reset them
	
	

	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_Print_Start:
			if(me->inputEvents.event.CountChanged) {
				me->_state = STATE_Print_print;
				me->_trigger = true;
				
			};
			break;
		case STATE_Print_print:
			if(me->inputEvents.event.CountChanged) {
				me->_state = STATE_Print_print;
				me->_trigger = true;
				
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_Print_Start:
			break;

		case STATE_Print_print:
			Print_PrintService(me);
			break;

		
		}
	}

	me->_trigger = false;
}
//algorithms

void Print_PrintService(Print_t  *me) {
HEX = (unsigned int)me->Count; //printf("%lu\n", me->Count);
}



