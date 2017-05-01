// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Device Function Block for _WaterHeater
#include "FB__WaterHeater.h"

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



/* _WaterHeater_preinit() is required to be called to 
 * initialise an instance of _WaterHeater. 
 * It sets all I/O values to zero.
 */
int _WaterHeater_preinit(_WaterHeater_t  *me) {
	//if there are input events, reset them
	
	//if there are output events, reset them
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	if(_WaterHeaterController_preinit(&me->controller) != 0) {
		return 1;
	}
	if(_WaterHeaterPlant_preinit(&me->plant) != 0) {
		return 1;
	}
	
	//if this is a BFB/odeFB, set start state so that the start state is properly executed and _trigger if necessary
	
	
	return 0;
}

/* _WaterHeater_init() is required to be called to 
 * set up an instance of _WaterHeater. 
 * It passes around configuration data.
 */
int _WaterHeater_init(_WaterHeater_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	if(_WaterHeaterController_init(&me->controller) != 0) {
		return 1;
	}
	if(_WaterHeaterPlant_init(&me->plant) != 0) {
		return 1;
	}
	

	return 0;
}



/* _WaterHeater_sync[Output/Input]Events() synchronises the events of an
 * instance of _WaterHeater as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _WaterHeater_syncOutputEvents(_WaterHeater_t  *me) {
	//for all device function block resource function blocks, call this same function
	//resources are the only things that can be embedded in devices
	//sync for controller (of type _WaterHeaterController) which is a Resource
	_WaterHeaterController_syncOutputEvents(&me->controller);//sync for plant (of type _WaterHeaterPlant) which is a Resource
	_WaterHeaterPlant_syncOutputEvents(&me->plant);
	
}
void _WaterHeater_syncInputEvents(_WaterHeater_t  *me) {
	//for all device function block resource function blocks, call this same function
	//resources are the only things that can be embedded in devices
	//sync for controller (of type _WaterHeaterController) which is a Resource
	_WaterHeaterController_syncInputEvents(&me->controller);//sync for plant (of type _WaterHeaterPlant) which is a Resource
	_WaterHeaterPlant_syncInputEvents(&me->plant);
	
}

/* _WaterHeater_sync[Output/Input]Data() synchronises the data connections of an
 * instance of _WaterHeater as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _WaterHeater_syncOutputData(_WaterHeater_t  *me) {
	//for all device function block resource function blocks, call this same function
	//resources are the only things that can be embedded in devices
	//sync for controller (of type _WaterHeaterController) which is a Resource
	_WaterHeaterController_syncOutputData(&me->controller);//sync for plant (of type _WaterHeaterPlant) which is a Resource
	_WaterHeaterPlant_syncOutputData(&me->plant);

}
void _WaterHeater_syncInputData(_WaterHeater_t  *me) {
	//for all device function block resource function blocks, call this same function
	//resources are the only things that can be embedded in devices
	//sync for controller (of type _WaterHeaterController) which is a Resource
	_WaterHeaterController_syncInputData(&me->controller);//sync for plant (of type _WaterHeaterPlant) which is a Resource
	_WaterHeaterPlant_syncInputData(&me->plant);

}


/* _WaterHeater_run() executes a single tick of an
 * instance of _WaterHeater according to synchronise semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * is done using the _syncX functions at this (and any higher) level.
 */
void _WaterHeater_run(_WaterHeater_t  *me) {
	_WaterHeaterController_run(&me->controller);
	_WaterHeaterPlant_run(&me->plant);
	
}
