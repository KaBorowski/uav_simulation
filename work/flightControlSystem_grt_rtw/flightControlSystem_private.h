/*
 * flightControlSystem_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flightControlSystem".
 *
 * Model version              : 4.8
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Thu Jul  7 17:18:09 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_flightControlSystem_private_h_
#define RTW_HEADER_flightControlSystem_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "flightControlSystem.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern void flightControlSystem_Logging_Init(RT_MODEL_flightControlSystem_T *
  const flightControlSystem_M, DW_Logging_flightControlSystem_T *localDW);
extern void flightControlSystem_Logging_Const(real_T rtu_posRef,
  DW_Logging_flightControlSystem_T *localDW);
extern void flightControlSystem_Logging(RT_MODEL_flightControlSystem_T * const
  flightControlSystem_M, const real32_T rtu_motorCmds[4], const statesEstim_t
  *rtu_states_estim_Inport_3, const CommandBus
  *rtu_ReferenceValueServerBus_Inport_4, const SensorsBus *rtu_Sensors_Inport_5,
  real32_T rtu_sensordata_datin_Inport_6, uint32_T
  rtu_sensordata_datin_Inport_6_d, real32_T rtu_sensordata_datin_Inport_6_e,
  real32_T rtu_sensordata_datin_Inport_6_c, real32_T
  rtu_sensordata_datin_Inport_6_cg, real32_T rtu_sensordata_datin_Inport_6_i,
  real32_T rtu_sensordata_datin_Inport_6_h, real32_T
  rtu_sensordata_datin_Inport_6_b, real32_T rtu_sensordata_datin_Inport_6_dz,
  DW_Logging_flightControlSystem_T *localDW);
extern void flightControlSystem_FlightControlSystem_Init
  (RT_MODEL_flightControlSystem_T * const flightControlSystem_M,
   DW_FlightControlSystem_flightControlSystem_T *localDW);
extern void flightControlSystem_FlightControlSystem_Const
  (DW_FlightControlSystem_flightControlSystem_T *localDW);
extern void flightControlSystem_FlightControlSystem
  (RT_MODEL_flightControlSystem_T * const flightControlSystem_M, const
   CommandBus *rtu_ReferenceValueServerCmds, const SensorsBus *rtu_Sensors,
   DW_FlightControlSystem_flightControlSystem_T *localDW);

#endif                           /* RTW_HEADER_flightControlSystem_private_h_ */
