/*
 * stateEstimator_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "stateEstimator".
 *
 * Model version              : 4.7
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Sun Jul  3 22:40:39 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_stateEstimator_private_h_
#define RTW_HEADER_stateEstimator_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

extern const real_T rtCP_pooled_OlAt8KbpQEG0[3];
extern const real32_T rtCP_pooled_aLwfmFKBoRwh[6];
extern const real32_T rtCP_pooled_adLCBuYxtU1Q[6];
extern const real32_T rtCP_pooled_VH0dmwbCQMUq[6];
extern const real32_T rtCP_pooled_KvfM2cKww6Wz[6];

#define rtCP_gravity_Value             rtCP_pooled_OlAt8KbpQEG0  /* Expression: [0 0 g]
                                                                  * Referenced by: '<S3>/gravity'
                                                                  */
#define rtCP_Assumingthatcalibwasdonelevel_Bias rtCP_pooled_aLwfmFKBoRwh/* Computed Parameter: rtCP_Assumingthatcalibwasdonelevel_Bias
                                                                      * Referenced by: '<S78>/Assuming that calib was done level!'
                                                                      */
#define rtCP_IIR_IMUgyro_r_NumCoef     rtCP_pooled_adLCBuYxtU1Q  /* Computed Parameter: rtCP_IIR_IMUgyro_r_NumCoef
                                                                  * Referenced by: '<S75>/IIR_IMUgyro_r'
                                                                  */
#define rtCP_IIR_IMUgyro_r_DenCoef     rtCP_pooled_VH0dmwbCQMUq  /* Computed Parameter: rtCP_IIR_IMUgyro_r_DenCoef
                                                                  * Referenced by: '<S75>/IIR_IMUgyro_r'
                                                                  */
#define rtCP_FIR_IMUaccel_Coefficients rtCP_pooled_KvfM2cKww6Wz  /* Computed Parameter: rtCP_FIR_IMUaccel_Coefficients
                                                                  * Referenced by: '<S75>/FIR_IMUaccel'
                                                                  */

/* Invariant block signals (default storage) */
extern const ConstB_stateEstimator_h_T stateEstimator_ConstB;

#endif                                /* RTW_HEADER_stateEstimator_private_h_ */
