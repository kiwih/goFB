// This file is generated by FBC.

#ifndef INJECTORMOTORCONTROLLER_H_
#define INJECTORMOTORCONTROLLER_H_

#include "fbtypes.h"

typedef union {
    struct {
        UDINT InjectorArmFinishedMovement ; // 
        UDINT EmergencyStopChanged ; // 
        UDINT ConveyorStoppedForInject ; // 
        UDINT PumpFinished ; // 
    } event;
} InjectorMotorControllerIEvents;

typedef union {
    struct {
        UDINT StartPump ; // 
        UDINT InjectDone ; // 
        UDINT InjectorPositionChanged ; // 
        UDINT InjectRunning ; // 
    } event;
} InjectorMotorControllerOEvents;

typedef struct {
    UINT _state;
    BOOL _entered;
    InjectorMotorControllerIEvents _input;
    BOOL EmergencyStop; // 
    BOOL _EmergencyStop;
    InjectorMotorControllerOEvents _output;
    BYTE InjectorPosition; // 
    BYTE _InjectorPosition;
} InjectorMotorController;

/* Function block initialization function */
void InjectorMotorControllerinit(InjectorMotorController* me);

/* Function block execution function */
void InjectorMotorControllerrun(InjectorMotorController* me);

/* ECC algorithms */
void InjectorMotorController_SetArmDownPosition(InjectorMotorController* me);
void InjectorMotorController_SetArmUpPosition(InjectorMotorController* me);
void InjectorMotorController_Algorithm1(InjectorMotorController* me);

#endif // INJECTORMOTORCONTROLLER_H_
