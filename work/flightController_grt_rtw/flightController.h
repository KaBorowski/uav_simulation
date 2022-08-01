/*
 * flightController.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flightController".
 *
 * Model version              : 4.2
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue Apr  5 21:55:09 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_flightController_h_
#define RTW_HEADER_flightController_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef flightController_COMMON_INCLUDES_
#define flightController_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* flightController_COMMON_INCLUDES_ */

#include "flightController_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE[2];/* '<S3>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE[2];            /* '<S3>/Delay' */
} DW_flightController_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: TorqueTotalThrustToThrustPerMotor_Value
   * Referenced by: '<S2>/TorqueTotalThrustToThrustPerMotor'
   */
  real32_T TorqueTotalThrustToThrustPerMotor_Value[16];

  /* Computed Parameter: MotorDirections_Gain
   * Referenced by: '<S7>/MotorDirections'
   */
  real32_T MotorDirections_Gain[4];
} ConstP_flightController_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  CommandBus ReferenceValueServerBus;  /* '<Root>/ReferenceValueServerBus' */
  statesEstim_t states_estim;          /* '<Root>/states_estim' */
} ExtU_flightController_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T motors_refout[4];           /* '<Root>/motors_refout' */
} ExtY_flightController_T;

/* Real-time Model Data Structure */
struct tag_RTM_flightController_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block states (default storage) */
extern DW_flightController_T flightController_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_flightController_T flightController_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_flightController_T flightController_Y;

/* Constant parameters (default storage) */
extern const ConstP_flightController_T flightController_ConstP;

/* Model entry point functions */
extern void flightController_initialize(void);
extern void flightController_step(void);
extern void flightController_terminate(void);

/* Real-time Model object */
extern RT_MODEL_flightController_T *const flightController_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'flightController'
 * '<S1>'   : 'flightController/Flight Controller'
 * '<S2>'   : 'flightController/Flight Controller/ControlMixer'
 * '<S3>'   : 'flightController/Flight Controller/Inner loop roll, pitch controller'
 * '<S4>'   : 'flightController/Flight Controller/Outer loop XY-to-reference-orientation'
 * '<S5>'   : 'flightController/Flight Controller/Yaw'
 * '<S6>'   : 'flightController/Flight Controller/altitude controller'
 * '<S7>'   : 'flightController/Flight Controller/thrustsToMotorCommands'
 */
#endif                                 /* RTW_HEADER_flightController_h_ */
