// This file is generated by FBC.

#include "PrintStatus.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void PrintStatusinit(PrintStatus* me)
{
    me->_state = 0;
    me->_entered = false;
    me->_input.events = 0;
}

/* ECC algorithms */
void PrintStatus_PrintService(PrintStatus* me)
{
// OFF 0
// RUNNING 1
// WEIGHT -1
// LASER -2
// STALL -3
// SPEED -4

if(me->_input.event.StatusUpdate) {
 printf("Saw 1: ");
 switch(me->Saw1Status) {
  case 0:
   printf("OFF          ");
   break;
  case 1:
   printf("RUNNING      ");
   break;
  case -1:
   printf("ERR:SAWDUST  ");
   break;
  case -2:
   printf("ERR:PROXIMITY");
   break;
  case -3:
   printf("ERR:STALL    ");
   break;
  case -4:
   printf("ERR:JITTER   ");
   break;
  default:
   printf("ERR:UNKNOWN  ");
 }
 printf("\t");

 printf("Saw 2: ");
 switch(me->Saw2Status) {
  case 0:
   printf("OFF          ");
   break;
  case 1:
   printf("RUNNING      ");
   break;
  case -1:
   printf("ERR:SAWDUST  ");
   break;
  case -2:
   printf("ERR:PROXIMITY");
   break;
  case -3:
   printf("ERR:STALL    ");
   break;
  case -4:
   printf("ERR:JITTER   ");
   break;
  default:
   printf("ERR:UNKNOWN  ");
 }
 printf("\t");

 printf("Saw 3: ");
 switch(me->Saw3Status) {
  case 0:
   printf("OFF          ");
   break;
  case 1:
   printf("RUNNING      ");
   break;
  case -1:
   printf("ERR:SAWDUST  ");
   break;
  case -2:
   printf("ERR:PROXIMITY");
   break;
  case -3:
   printf("ERR:STALL    ");
   break;
  case -4:
   printf("ERR:JITTER   ");
   break;
  default:
   printf("ERR:UNKNOWN  ");
 }
 printf("\n");

}
}

/* Function block execution function */
void PrintStatusrun(PrintStatus* me)
{
    
    if (me->_input.event.StatusUpdate) {
        me->Saw1Status = me->_Saw1Status;
        me->Saw2Status = me->_Saw2Status;
        me->Saw3Status = me->_Saw3Status;
    }
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
            // State: Run
            if (!me->_entered) {
                PrintStatus_PrintService(me);
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
    me->_input.events = 0;
}
