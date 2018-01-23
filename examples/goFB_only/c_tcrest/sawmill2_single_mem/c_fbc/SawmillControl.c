// This file is generated by FBC.

#include "SawmillControl.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void SawmillControlinit(SawmillControl* me)
{
    me->_state = 0;
    me->_entered = false;
    me->_input.events = 0;
    me->_output.events = 0;
}

/* ECC algorithms */
void SawmillControl_MessageHaltWeight(SawmillControl* me)
{
me->Message = -1;
}

void SawmillControl_MessageHaltLaser(SawmillControl* me)
{
me->Message = -2;
}

void SawmillControl_MessageRun(SawmillControl* me)
{
me->Message = 1;
}

void SawmillControl_MessageStop(SawmillControl* me)
{
me->Message = 0;
}

void SawmillControl_SawRun(SawmillControl* me)
{
me->SawRun = 1;
}

void SawmillControl_SawStop(SawmillControl* me)
{
me->SawRun = 0;
}

void SawmillControl_MessageBadSpeed(SawmillControl* me)
{
me->Message = -4;
}

void SawmillControl_MessageStallDetected(SawmillControl* me)
{
me->Message = -3;
}

/* Function block execution function */
void SawmillControlrun(SawmillControl* me)
{
    me->_output.events = 0;

    if (me->_input.events) {
        if (me->_input.event.ControlChange) {
            me->ControlRun = me->_ControlRun;
        }
        if (me->_input.event.WeightChange) {
            me->ScaleOverweight = me->_ScaleOverweight;
        }
        if (me->_input.event.LaserChange) {
            me->LaserBroken = me->_LaserBroken;
        }
        if (me->_input.event.BadSpeedChange) {
            me->BadSpeed = me->_BadSpeed;
        }
        if (me->_input.event.StallDetectedChange) {
            me->StallDetected = me->_StallDetected;
        }
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
                // State: startup
                if (!me->_entered) {
                    SawmillControl_SawStop(me);
                    me->_output.event.CommandChange = 1;
                    SawmillControl_MessageStop(me);
                    me->_output.event.MessageChange = 1;
                    me->_entered = true;
                }
                else {
                    me->_state = 2;
                    me->_entered = false;
                    continue;
                }
                break;
            case 2:
                // State: await_command
                if (!me->_entered) {
                    me->_entered = true;
                }
                else {
                    if (me->_input.event.ControlChange && (me->ControlRun)) {
                        me->_state = 3;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 3:
                // State: check_weight
                if (!me->_entered) {
                    me->_entered = true;
                }
                else {
                    if (! me->ScaleOverweight) {
                        me->_state = 4;
                        me->_entered = false;
                        continue;
                    }
                    else if (me->ScaleOverweight) {
                        me->_state = 10;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 4:
                // State: check_laser
                if (!me->_entered) {
                    me->_entered = true;
                }
                else {
                    if (! me->LaserBroken) {
                        me->_state = 5;
                        me->_entered = false;
                        continue;
                    }
                    else if (me->LaserBroken) {
                        me->_state = 9;
                        me->_entered = false;
                        continue;
                    }
                    else if (! me->ControlRun) {
                        me->_state = 2;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 5:
                // State: run
                if (!me->_entered) {
                    SawmillControl_SawRun(me);
                    me->_output.event.CommandChange = 1;
                    SawmillControl_MessageRun(me);
                    me->_output.event.MessageChange = 1;
                    me->_entered = true;
                }
                else {
                    if (me->LaserBroken) {
                        me->_state = 4;
                        me->_entered = false;
                        continue;
                    }
                    else if (me->ScaleOverweight) {
                        me->_state = 3;
                        me->_entered = false;
                        continue;
                    }
                    else if (me->BadSpeed) {
                        me->_state = 6;
                        me->_entered = false;
                        continue;
                    }
                    else if (! me->ControlRun) {
                        me->_state = 7;
                        me->_entered = false;
                        continue;
                    }
                    else if (me->StallDetected) {
                        me->_state = 8;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 6:
                // State: bad_speed
                if (!me->_entered) {
                    SawmillControl_MessageBadSpeed(me);
                    me->_output.event.MessageChange = 1;
                    SawmillControl_SawStop(me);
                    me->_output.event.CommandChange = 1;
                    me->_entered = true;
                }
                else {
                    me->_state = 2;
                    me->_entered = false;
                    continue;
                }
                break;
            case 7:
                // State: control_stop
                if (!me->_entered) {
                    SawmillControl_MessageStop(me);
                    me->_output.event.MessageChange = 1;
                    SawmillControl_SawStop(me);
                    me->_output.event.CommandChange = 1;
                    me->_entered = true;
                }
                else {
                    me->_state = 2;
                    me->_entered = false;
                    continue;
                }
                break;
            case 8:
                // State: stall_detected
                if (!me->_entered) {
                    SawmillControl_SawStop(me);
                    me->_output.event.CommandChange = 1;
                    SawmillControl_MessageStallDetected(me);
                    me->_output.event.MessageChange = 1;
                    me->_entered = true;
                }
                else {
                    me->_state = 2;
                    me->_entered = false;
                    continue;
                }
                break;
            case 9:
                // State: await_laser
                if (!me->_entered) {
                    SawmillControl_MessageHaltLaser(me);
                    me->_output.event.MessageChange = 1;
                    SawmillControl_SawStop(me);
                    me->_output.event.CommandChange = 1;
                    me->_entered = true;
                }
                else {
                    if (! me->LaserBroken) {
                        me->_state = 4;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 10:
                // State: await_weight
                if (!me->_entered) {
                    SawmillControl_MessageHaltWeight(me);
                    me->_output.event.MessageChange = 1;
                    SawmillControl_SawStop(me);
                    me->_output.event.CommandChange = 1;
                    me->_entered = true;
                }
                else {
                    if (! me->ScaleOverweight) {
                        me->_state = 3;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
        }
        break;
    }
    if (me->_output.event.CommandChange) {
        me->_SawRun = me->SawRun;
    }
    if (me->_output.event.MessageChange) {
        me->_Message = me->Message;
    }

    me->_input.events = 0;
}
