// This file is generated by FBC.

#include "MaskedSwitch.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void MaskedSwitchinit(MaskedSwitch* me)
{
    me->_state = 0;
    me->_entered = false;
    me->_output.events = 0;
}

/* ECC algorithms */
void MaskedSwitch_SwitchesService(MaskedSwitch* me)
{
int m = (SWITCHES & me->_SwitchMask) != 0;
if(m != me->SwitchOn) {
	//switch is pressed
	me->SwitchOn = m;
	me->_output.event.SwitchChanged = 1;
} 
}

/* Function block execution function */
void MaskedSwitchrun(MaskedSwitch* me)
{
    me->_output.events = 0;
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
            // State: Update
            if (!me->_entered) {
                MaskedSwitch_SwitchesService(me);
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
    if (me->_output.event.SwitchChanged) {
        me->_SwitchOn = me->SwitchOn;
    }

}

