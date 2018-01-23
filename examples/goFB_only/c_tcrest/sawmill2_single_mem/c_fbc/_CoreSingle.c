// This file is generated by FBC.

#include "_CoreSingle.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void _CoreSingleinit(_CoreSingle* me)
{
    SawmillModuleinit(&me->saw1);
    SawmillModuleinit(&me->saw2);
    SawmillModuleinit(&me->saw3);
    PrintStatusinit(&me->statusprint);
}

/* Function block execution function */
void _CoreSinglerun(_CoreSingle* me)
{
    me->statusprint._Saw2Status = me->saw2._Message;
    me->statusprint._input.event.StatusUpdate = me->saw1._output.event.MessageChange || me->saw3._output.event.MessageChange || me->saw2._output.event.MessageChange;
    me->statusprint._Saw1Status = me->saw1._Message;
    me->statusprint._Saw3Status = me->saw3._Message;
    
    SawmillModulerun(&me->saw1);
    SawmillModulerun(&me->saw2);
    SawmillModulerun(&me->saw3);
    PrintStatusrun(&me->statusprint);
    
}
