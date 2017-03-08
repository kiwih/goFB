// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Composite Function Block for Plant
#include "Plant.h"

//When running a composite block, note that you would call the functions in this order (and this is very important)
//_preinit(); 
//_init();
//do {
//	_syncOutputEvents();
//	_syncInputEvents();
//	_syncOutputData();
//	_syncInputData();
//	_run();
//} loop;


/* Plant_preinit() is required to be called to 
 * initialise an instance of Plant. 
 * It sets all I/O values to zero.
 */
int Plant_preinit(Plant_t  *me) {
	//if there are input events, reset them
	me->inputEvents.event.Zero = 0;
	me->inputEvents.event.ControlChange = 0;
	
	//if there are output events, reset them
	me->outputEvents.event.ValueChange = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(BadRandom_preinit(&me->badRNG) != 0) {
		return 1;
	}
	if(PlantProcess_preinit(&me->plantProc) != 0) {
		return 1;
	}
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	

	return 0;
}

/* Plant_init() is required to be called to 
 * set up an instance of Plant. 
 * It passes around configuration data.
 */
int Plant_init(Plant_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	me->plantProc.Control = me->Control;
	me->Value = me->plantProc.Value;
	me->plantProc.Random = me->badRNG.Random;
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(BadRandom_init(&me->badRNG) != 0) {
		return 1;
	}
	if(PlantProcess_init(&me->plantProc) != 0) {
		return 1;
	}
	
	

	return 0;
}



/* Plant_syncOutputEvents() synchronises the output events of an
 * instance of Plant as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void Plant_syncOutputEvents(Plant_t  *me) {
	//first, for all cfb children, call this same function
	
	
	//then, for all connections that are connected to an output on the parent, run their run their copy
	
	me->outputEvents.event.ValueChange = me->plantProc.outputEvents.event.ValueChange; 
	
}

/* Plant_syncInputEvents() synchronises the input events of an
 * instance of Plant as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void Plant_syncInputEvents(Plant_t  *me) {
	//first, we explicitly synchronise the children
	
	me->plantProc.inputEvents.event.Zero = me->inputEvents.event.Zero; 
	
	me->plantProc.inputEvents.event.ControlChange = me->inputEvents.event.ControlChange; 
	
	me->plantProc.inputEvents.event.RandomChange = me->badRNG.outputEvents.event.RandomChange; 
	

	//then, call this same function on all cfb children
	
}

/* Plant_syncOutputData() synchronises the output data connections of an
 * instance of Plant as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void Plant_syncOutputData(Plant_t  *me) {
	//for all composite function block children, call this same function
	
	
	//for data that is sent from child to this CFB (me), always copy (event controlled copies will be resolved at the next level up) //TODO: arrays!?
	me->Value = me->plantProc.Value;
	
	
}

/* Plant_syncInputData() synchronises the input data connections of an
 * instance of Plant as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void Plant_syncInputData(Plant_t  *me) {
	//for all basic function block children, perform their synchronisations explicitly
	
	//sync for badRNG (of type BadRandom) which is a BFB
	
	
	//sync for plantProc (of type PlantProcess) which is a BFB
	
	if(me->plantProc.inputEvents.event.ControlChange == 1) { 
		me->plantProc.Control = me->Control;
	} 
	if(me->plantProc.inputEvents.event.RandomChange == 1) { 
		me->plantProc.Random = me->badRNG.Random;
	} 
	
	
	//for all composite function block children, call this same function
	
	
}


/* Plant_run() executes a single tick of an
 * instance of Plant according to synchronise semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * is done using the _syncX functions at this (and any higher) level.
 */
void Plant_run(Plant_t  *me) {
	BadRandom_run(&me->badRNG);
	PlantProcess_run(&me->plantProc);
	
}
