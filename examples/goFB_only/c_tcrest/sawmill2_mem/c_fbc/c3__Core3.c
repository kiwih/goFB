// This file is generated by FBC.

#include "c3__Core3.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void c3__Core3init(c3__Core3* me)
{
    ArgoTxinit(&me->tx);
    SawmillMessageHandlerinit(&me->messageHandler);
    SawmillModuleinit(&me->sawmill);
    me->tx._ChanId = 3;

    ArgoTxchaninit(&me->tx);
}

/* Function block execution function */
void c3__Core3run(c3__Core3* me)
{
    me->tx._input.event.DataPresent = me->messageHandler._output.event.TxDataPresent;
    me->tx._Data = me->messageHandler._TxData;
    me->messageHandler._TxSuccess = me->tx._Success;
    me->messageHandler._input.event.MessageChanged = me->sawmill._output.event.MessageChange;
    me->messageHandler._Message = me->sawmill._Message;
    me->messageHandler._input.event.TxSuccessChanged = me->tx._output.event.SuccessChanged;
    
    ArgoTxrun(&me->tx);
    SawmillMessageHandlerrun(&me->messageHandler);
    SawmillModulerun(&me->sawmill);
    
}
