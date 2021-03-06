// This file is generated by FBC.

#ifndef SAWMILLPOSGEN_H_
#define SAWMILLPOSGEN_H_

#include "fbtypes.h"

typedef union {
    UDINT events;
    struct {
        UDINT SawRunChange : 1; // 
    } event;
} SawmillPosGenIEvents;

typedef union {
    UDINT events;
    struct {
        UDINT NewPosChange : 1; // 
    } event;
} SawmillPosGenOEvents;

typedef struct {
    UINT _state;
    BOOL _entered;
    SawmillPosGenIEvents _input;
    BOOL SawRun; // 
    BOOL _SawRun;
    SawmillPosGenOEvents _output;
    LREAL NewPos; // 
    LREAL _NewPos;
    INT PosArrayLen; // 
    INT PosArrayPos; // 
    LREAL PosArray[20]; // 
} SawmillPosGen;

/* Function block initialization function */
void SawmillPosGeninit(SawmillPosGen* me);

/* Function block execution function */
void SawmillPosGenrun(SawmillPosGen* me);

/* ECC algorithms */
void SawmillPosGen_posgen_service(SawmillPosGen* me);

#endif // SAWMILLPOSGEN_H_
