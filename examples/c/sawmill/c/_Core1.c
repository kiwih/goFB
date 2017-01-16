// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Composite Function Block for _Core1
#include "_Core1.h"

//When running a composite block, note that you would call the functions in this order
//_init(); 
//do {
//_syncEvents();
//_syncData();
//_run();
//} loop;


/* _Core1_preinit() is required to be called to 
 * initialise an instance of _Core1. 
 * It sets all I/O values to zero.
 */
int _Core1_preinit(struct _Core1 *me) {
	//if there are input events, reset them
	
	//if there are output events, reset them
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(SawmillModule_preinit(&me->sawmill) != 0) {
		return 1;
	}
	if(SawmillMessageHandler_preinit(&me->messageHandler) != 0) {
		return 1;
	}
	if(ArgoTx_preinit(&me->tx) != 0) {
		return 1;
	}
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	

	return 0;
}

/* _Core1_init() is required to be called to 
 * set up an instance of _Core1. 
 * It passes around configuration data.
 */
int _Core1_init(struct _Core1 *me) {
	//pass in any parameters on this level
	me->tx.ChanId = 1;
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	me->messageHandler.Message = me->sawmill.Message;
	me->tx.Data = me->messageHandler.TxData;
	me->messageHandler.TxSuccess = me->tx.Success;
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(SawmillModule_init(&me->sawmill) != 0) {
		return 1;
	}
	if(SawmillMessageHandler_init(&me->messageHandler) != 0) {
		return 1;
	}
	if(ArgoTx_init(&me->tx) != 0) {
		return 1;
	}
	
	

	return 0;
}



/* _Core1_syncEvents() synchronises the events of an
 * instance of _Core1 as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _Core1_syncEvents(struct _Core1 *me) {
	//for all composite function block children, call this same function
	//sync for sawmill (of type SawmillModule) which is a CFB
	SawmillModule_syncEvents(&me->sawmill);
	//for all basic function block children, perform their synchronisations explicitly
	//events are always copied
	me->messageHandler.inputEvents.event.MessageChanged = me->sawmill.outputEvents.event.MessageChange;
	me->tx.inputEvents.event.DataPresent = me->messageHandler.outputEvents.event.TxDataPresent;
	me->messageHandler.inputEvents.event.TxSuccessChanged = me->tx.outputEvents.event.SuccessChanged;
	
}

/* _Core1_syncData() synchronises the data connections of an
 * instance of _Core1 as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _Core1_syncData(struct _Core1 *me) {
	//for all composite function block children, call this same function
	//sync for sawmill (of type SawmillModule) which is a CFB
	SawmillModule_syncData(&me->sawmill);
	//for all basic function block children, perform their synchronisations explicitly
	//Data is sometimes copied
	
	
	//sync for messageHandler (of type SawmillMessageHandler) which is a BFB
	
	if(me->messageHandler.inputEvents.event.MessageChanged == 1) { 
		me->messageHandler.Message = me->sawmill.Message;
	} 
	if(me->messageHandler.inputEvents.event.TxSuccessChanged == 1) { 
		me->messageHandler.TxSuccess = me->tx.Success;
	} 
	
	//sync for tx (of type ArgoTx) which is a BFB
	
	if(me->tx.inputEvents.event.DataPresent == 1) { 
		me->tx.Data = me->messageHandler.TxData;
	} 
	

}


/* _Core1_run() executes a single tick of an
 * instance of _Core1 according to synchronise semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * is done using the _syncX functions at this (and any higher) level.
 */
void _Core1_run(struct _Core1 *me) {
	SawmillModule_run(&me->sawmill);
	SawmillMessageHandler_run(&me->messageHandler);
	ArgoTx_run(&me->tx);
	
}

