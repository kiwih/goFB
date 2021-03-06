// This file is generated by FBC.

#include "SawmillPosGen.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void SawmillPosGeninit(SawmillPosGen* me)
{
    me->_state = 0;
    me->_entered = false;
    me->_input.events = 0;
    me->_output.events = 0;
    me->PosArrayLen = 20;
    me->PosArrayPos = 0;
    me->PosArray[0] = 0;
    me->PosArray[1] = 0.5;
    me->PosArray[2] = 1;
    me->PosArray[3] = 1.5;
    me->PosArray[4] = 2;
    me->PosArray[5] = 2.5;
    me->PosArray[6] = 3;
    me->PosArray[7] = 3.5;
    me->PosArray[8] = 4;
    me->PosArray[9] = 4.5;
    me->PosArray[10] = 5;
    me->PosArray[11] = 4.5;
    me->PosArray[12] = 4;
    me->PosArray[13] = 3.5;
    me->PosArray[14] = 3;
    me->PosArray[15] = 2.5;
    me->PosArray[16] = 2;
    me->PosArray[17] = 1.5;
    me->PosArray[18] = 1;
    me->PosArray[19] = 0.5;
}

/* ECC algorithms */
void SawmillPosGen_posgen_service(SawmillPosGen* me)
{
if(me->SawRun) {
 me->_output.event.NewPosChange = 1;
 me->NewPos = me->PosArray[me->PosArrayPos];
 me->PosArrayPos++;
 me->PosArrayPos = me->PosArrayPos % me->PosArrayLen;
} else {
 me->_output.event.NewPosChange = 0;
}
}

/* Function block execution function */
void SawmillPosGenrun(SawmillPosGen* me)
{
    me->_output.events = 0;

    if (me->_input.event.SawRunChange) {
        me->SawRun = me->_SawRun;
    }
    #pragma loopbound min 1 max 2
    for (;;) {
        if (me->_state == 0) {
            // State: Start
            if (!me->_entered) {
                me->_entered = true;
            }
            else {
                me->_state = 1;
                me->_entered = false;
                continue;
            }
        }
        else {
            // State: run
            if (!me->_entered) {
                SawmillPosGen_posgen_service(me);
                me->_entered = true;
            }
            else {
                me->_state = 1;
                me->_entered = false;
                continue;
            }
        }
        break;
    }
    if (me->_output.event.NewPosChange) {
        me->_NewPos = me->NewPos;
    }

    me->_input.events = 0;
}

