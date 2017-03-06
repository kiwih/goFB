// This file is generated by FBC.

#ifndef _CORE_H_
#define _CORE_H_

#include "fbtypes.h"
#include "PID.h"
#include "Manager.h"
#include "Plant.h"

typedef struct {
    PID pid;
    Manager manager;
    Plant plant;
} _Core;

/* Function block initialization function */
void _Coreinit(_Core* me);

/* Function block execution function */
void _Corerun(_Core* me);

#endif // _CORE_H_
