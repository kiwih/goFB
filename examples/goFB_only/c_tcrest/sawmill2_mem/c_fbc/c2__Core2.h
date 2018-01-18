// This file is generated by FBC.

#ifndef C2__CORE2_H_
#define C2__CORE2_H_

#include "fbtypes.h"
#include "ArgoTx.h"
#include "SawmillMessageHandler.h"
#include "SawmillModule.h"

typedef struct {
    ArgoTx tx;
    SawmillMessageHandler messageHandler;
    SawmillModule sawmill;
} c2__Core2;

/* Function block initialization function */
void c2__Core2init(c2__Core2* me);

/* Function block execution function */
void c2__Core2run(c2__Core2* me);

#endif // C2__CORE2_H_
