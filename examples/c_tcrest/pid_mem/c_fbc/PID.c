// This file is generated by FBC.

#include "PID.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void PIDinit(PID* me)
{
    me->_state = 0;
    me->_entered = false;
    me->_output.event.ControlChanged = 0;
}

/* ECC algorithms */
void PID_PIDTick(PID* me)
{
 REAL diff;
 REAL p_term;
 REAL i_term;
 REAL d_term;

 REAL currentError = me->DesiredValue - me->ActualValue;
 
    // integration with windup guarding
    me->IntegrationError += currentError;
    if (me->IntegrationError < -(me->WindupGuard)) {
        me->IntegrationError = -(me->WindupGuard);

 } else if (me->IntegrationError > me->WindupGuard) {
        me->IntegrationError = me->WindupGuard;

 }

    // differentiation
    diff = currentError - me->PreviousError;
 
    // scaling
    p_term = (me->PGain * currentError);
    i_term = (me->IGain * me->IntegrationError);
    d_term = (me->DGain * diff);
 
    // summation of terms
    me->Control = p_term + i_term + d_term;
 
    // save current error as previous error for next iteration
    me->PreviousError = currentError;
}

void PID_PIDZero(PID* me)
{
me->PreviousError = 0.0;
me->IntegrationError = 0.0;
}

/* Function block execution function */
void PIDrun(PID* me)
{
    me->_output.event.ControlChanged = 0;


        if (me->_input.event.Zero) {
            me->PGain = me->_PGain;
            me->IGain = me->_IGain;
            me->DGain = me->_DGain;
            me->WindupGuard = me->_WindupGuard;
        }
        if (me->_input.event.Tick) {
            me->DesiredValue = me->_DesiredValue;
        }
        if (me->_input.event.ActualValueChanged) {
            me->ActualValue = me->_ActualValue;
        }
    

	#pragma loopbound min 1 max 2
    for (;;) {
        switch (me->_state) {
            case 0:
                // State: Start
                if (!me->_entered) {
                    me->_entered = true;
                }
                else {
                    me->_state = 1;
                    me->_entered = false;
                    continue;
                }
                break;
            case 1:
                // State: zero
                if (!me->_entered) {
                    PID_PIDZero(me);
                    me->_entered = true;
                }
                else {
                    if (me->_input.event.Tick) {
                        me->_state = 2;
                        me->_entered = false;
                        continue;
                    }
                    else if (me->_input.event.Zero) {
                        me->_state = 1;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 2:
                // State: update
                if (!me->_entered) {
                    PID_PIDTick(me);
                    me->_output.event.ControlChanged = 1;
                    me->_entered = true;
                }
                else {
                    if (me->_input.event.Zero) {
                        me->_state = 1;
                        me->_entered = false;
                        continue;
                    }
                    else if (me->_input.event.Tick) {
                        me->_state = 2;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
        }
        break;
    }
    if (me->_output.event.ControlChanged) {
        me->_Control = me->Control;
    }

}

