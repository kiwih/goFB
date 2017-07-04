// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block _Core0
#ifndef _CORE0_H_
#define _CORE0_H_

#include "fbtypes.h"

//This is a CFB, so we need the #includes for the child blocks embedded here
#include "ArgoRx.h"
#include "ArgoRx.h"
#include "ArgoRx.h"
#include "PrintStatus.h"


//this block had no input events


//this block had no output events


typedef struct {
    //input events
	

    //output events
	

    //input vars
	
    //output vars
	
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	ArgoRx_t saw1rx;
	ArgoRx_t saw2rx;
	ArgoRx_t saw3rx;
	PrintStatus_t statusprint;
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	
} _Core0_t;

//all FBs get a preinit function
int _Core0_preinit(_Core0_t  *me);

//all FBs get an init function
int _Core0_init(_Core0_t  *me);

//all FBs get a run function
void _Core0_run(_Core0_t  *me);

//composite/resource/device FBs get sync functions
void _Core0_syncOutputEvents(_Core0_t  *me);
void _Core0_syncInputEvents(_Core0_t  *me);

void _Core0_syncOutputData(_Core0_t  *me);
void _Core0_syncInputData(_Core0_t  *me);



#endif