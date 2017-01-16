// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for SimpleProducer
#include "SimpleProducer.h"


/* SimpleProducer_preinit() is required to be called to 
 * initialise an instance of SimpleProducer. 
 * It sets all I/O values to zero.
 */
int SimpleProducer_preinit(struct SimpleProducer *me) {
	//if there are input events, reset them
	me->inputEvents.events[0] = 0;
	
	//if there are output events, reset them
	me->outputEvents.events[0] = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	me->Count = 0;
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_SimpleProducer_Start;
	

	return 0;
}

/* SimpleProducer_init() is required to be called to 
 * set up an instance of SimpleProducer. 
 * It passes around configuration data.
 */
int SimpleProducer_init(struct SimpleProducer *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



/* SimpleProducer_run() executes a single tick of an
 * instance of SimpleProducer according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void SimpleProducer_run(struct SimpleProducer *me) {
	//if there are output events, reset them
	me->outputEvents.events[0] = 0;
	
	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_SimpleProducer_Start:
			if(true) {
				me->_state = STATE_SimpleProducer_increment;
				me->_trigger = true;
			};
			break;
		case STATE_SimpleProducer_increment:
			if(true) {
				me->_state = STATE_SimpleProducer_Tx;
				me->_trigger = true;
			};
			break;
		case STATE_SimpleProducer_Tx:
			if(me->inputEvents.event.TxSuccessChanged && (me->TxSuccess)) {
				me->_state = STATE_SimpleProducer_increment;
				me->_trigger = true;
			} else if(me->inputEvents.event.TxSuccessChanged && ( ! me->TxSuccess)) {
				me->_state = STATE_SimpleProducer_Tx;
				me->_trigger = true;
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_SimpleProducer_Start:
			break;

		case STATE_SimpleProducer_increment:
			SimpleProducer_update_count(me);
			break;

		case STATE_SimpleProducer_Tx:
			me->outputEvents.event.DataPresent = 1;
			break;

		
		}
	}

	me->_trigger = false;
}

//algorithms

void SimpleProducer_update_count(struct SimpleProducer *me) {
me->Count++;
me->Data = me->Count;
}


