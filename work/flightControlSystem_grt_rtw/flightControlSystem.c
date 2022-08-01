/*
 * flightControlSystem.c
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

#include "flightControlSystem.h"
#include "flightControlSystem_private.h"

const statesEstim_t flightControlSystem_rtZstatesEstim_t = {
  0.0F,                                /* X */
  0.0F,                                /* Y */
  0.0F,                                /* Z */
  0.0F,                                /* yaw */
  0.0F,                                /* pitch */
  0.0F,                                /* roll */
  0.0F,                                /* dx */
  0.0F,                                /* dy */
  0.0F,                                /* dz */
  0.0F,                                /* p */
  0.0F,                                /* q */
  0.0F                                 /* r */
} ;                                    /* statesEstim_t ground */

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<S1>/controller' */
uint8_T flag_outport;                  /* '<S2>/Merge' */

/* Block states (default storage) */
DW_flightControlSystem_T flightControlSystem_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_flightControlSystem_T flightControlSystem_Y;

/* Real-time model */
static RT_MODEL_flightControlSystem_T flightControlSystem_M_;
RT_MODEL_flightControlSystem_T *const flightControlSystem_M =
  &flightControlSystem_M_;

/* System initialize for atomic system: '<S1>/Logging' */
void flightControlSystem_Logging_Init(RT_MODEL_flightControlSystem_T * const
  flightControlSystem_M, DW_Logging_flightControlSystem_T *localDW)
{
  /* SetupRuntimeResources for ToWorkspace: '<S3>/To Workspace1' */
  {
    static int_T rt_ToWksWidths[] = { 1 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 1 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace1";
    localDW->ToWorkspace1_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "posref",
      1,
      0,
      1,
      -2.0,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace1_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S3>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 4 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 4 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace";
    localDW->ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "motor",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S3>/To Workspace2' */
  {
    static int_T rt_ToWksWidths[] = { 12 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 12 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace2";
    localDW->ToWorkspace2_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "estim",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace2_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S3>/To Workspace3' */
  {
    static int_T rt_ToWksWidths[] = { 8 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 8 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace3";
    localDW->ToWorkspace3_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "cmd",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace3_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S3>/To Workspace5' */
  {
    static int_T rt_ToWksWidths[] = { 8 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 8 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "SensorCalibration" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace5";
    localDW->ToWorkspace5_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "calib",
      1,
      0,
      100,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace5_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S3>/To Workspace6' */
  {
    static int_T rt_ToWksWidths[] = { 9 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 9 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace6";
    localDW->ToWorkspace6_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "sensor",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace6_PWORK.LoggedData == (NULL))
      return;
  }
}

/* Output and update for atomic system: '<S1>/Logging' */
void flightControlSystem_Logging(RT_MODEL_flightControlSystem_T * const
  flightControlSystem_M, const real32_T rtu_motorCmds[4], const statesEstim_t
  *rtu_states_estim_Inport_3, const CommandBus
  *rtu_ReferenceValueServerBus_Inport_4, const SensorsBus *rtu_Sensors_Inport_5,
  real32_T rtu_sensordata_datin_Inport_6, uint32_T
  rtu_sensordata_datin_Inport_6_d, real32_T rtu_sensordata_datin_Inport_6_e,
  real32_T rtu_sensordata_datin_Inport_6_c, real32_T
  rtu_sensordata_datin_Inport_6_cg, real32_T rtu_sensordata_datin_Inport_6_i,
  real32_T rtu_sensordata_datin_Inport_6_h, real32_T
  rtu_sensordata_datin_Inport_6_b, real32_T rtu_sensordata_datin_Inport_6_dz,
  DW_Logging_flightControlSystem_T *localDW)
{
  /* local block i/o variables */
  real32_T rtb_DataTypeConversion1;
  real32_T rtb_DataTypeConversion2;
  int32_T i;
  real32_T rtb_TmpSignalConversionAtToWorkspace2Inport1[12];
  real32_T rtb_TmpSignalConversionAtToWorkspace6Inport1[9];
  real32_T rtb_SensorCalibration[8];
  real32_T rtb_TmpSignalConversionAtToWorkspace3Inport1[8];

  /* ToWorkspace: '<S3>/To Workspace' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace_PWORK.LoggedData,
                          &locTime, &rtu_motorCmds[0]);
  }

  /* SignalConversion generated from: '<S3>/To Workspace2' incorporates:
   *  SignalConversion generated from: '<S3>/states_estim_BusSelector'
   */
  rtb_TmpSignalConversionAtToWorkspace2Inport1[0] = rtu_states_estim_Inport_3->X;
  rtb_TmpSignalConversionAtToWorkspace2Inport1[1] = rtu_states_estim_Inport_3->Y;
  rtb_TmpSignalConversionAtToWorkspace2Inport1[2] = rtu_states_estim_Inport_3->Z;
  rtb_TmpSignalConversionAtToWorkspace2Inport1[3] =
    rtu_states_estim_Inport_3->yaw;
  rtb_TmpSignalConversionAtToWorkspace2Inport1[4] =
    rtu_states_estim_Inport_3->pitch;
  rtb_TmpSignalConversionAtToWorkspace2Inport1[5] =
    rtu_states_estim_Inport_3->roll;
  rtb_TmpSignalConversionAtToWorkspace2Inport1[6] =
    rtu_states_estim_Inport_3->dx;
  rtb_TmpSignalConversionAtToWorkspace2Inport1[7] =
    rtu_states_estim_Inport_3->dy;
  rtb_TmpSignalConversionAtToWorkspace2Inport1[8] =
    rtu_states_estim_Inport_3->dz;
  rtb_TmpSignalConversionAtToWorkspace2Inport1[9] = rtu_states_estim_Inport_3->p;
  rtb_TmpSignalConversionAtToWorkspace2Inport1[10] =
    rtu_states_estim_Inport_3->q;
  rtb_TmpSignalConversionAtToWorkspace2Inport1[11] =
    rtu_states_estim_Inport_3->r;

  /* ToWorkspace: '<S3>/To Workspace2' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace2_PWORK.LoggedData,
                          &locTime,
                          &rtb_TmpSignalConversionAtToWorkspace2Inport1[0]);
  }

  /* SignalConversion generated from: '<S3>/To Workspace3' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   *  SignalConversion generated from: '<S3>/ReferenceValueServerBus_BusSelector'
   */
  rtb_TmpSignalConversionAtToWorkspace3Inport1[0] =
    rtu_ReferenceValueServerBus_Inport_4->controlModePosVSOrient;
  rtb_TmpSignalConversionAtToWorkspace3Inport1[4] =
    rtu_ReferenceValueServerBus_Inport_4->takeoff_flag;
  rtb_TmpSignalConversionAtToWorkspace3Inport1[1] =
    rtu_ReferenceValueServerBus_Inport_4->pos_ref[0];
  rtb_TmpSignalConversionAtToWorkspace3Inport1[5] =
    rtu_ReferenceValueServerBus_Inport_4->orient_ref[0];
  rtb_TmpSignalConversionAtToWorkspace3Inport1[2] =
    rtu_ReferenceValueServerBus_Inport_4->pos_ref[1];
  rtb_TmpSignalConversionAtToWorkspace3Inport1[6] =
    rtu_ReferenceValueServerBus_Inport_4->orient_ref[1];
  rtb_TmpSignalConversionAtToWorkspace3Inport1[3] =
    rtu_ReferenceValueServerBus_Inport_4->pos_ref[2];
  rtb_TmpSignalConversionAtToWorkspace3Inport1[7] =
    rtu_ReferenceValueServerBus_Inport_4->orient_ref[2];

  /* ToWorkspace: '<S3>/To Workspace3' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace3_PWORK.LoggedData,
                          &locTime,
                          &rtb_TmpSignalConversionAtToWorkspace3Inport1[0]);
  }

  /* SignalConversion generated from: '<S3>/Sensors_BusSelector' */
  for (i = 0; i < 8; i++) {
    rtb_SensorCalibration[i] = rtu_Sensors_Inport_5->SensorCalibration[i];
  }

  /* End of SignalConversion generated from: '<S3>/Sensors_BusSelector' */

  /* ToWorkspace: '<S3>/To Workspace5' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace5_PWORK.LoggedData,
                          &locTime, &rtb_SensorCalibration[0]);
  }

  /* DataTypeConversion: '<S3>/Data Type Conversion1' */
  rtb_DataTypeConversion1 = rtu_sensordata_datin_Inport_6;

  /* DataTypeConversion: '<S3>/Data Type Conversion2' */
  rtb_DataTypeConversion2 = (real32_T)rtu_sensordata_datin_Inport_6_d;

  /* SignalConversion generated from: '<S3>/To Workspace6' */
  rtb_TmpSignalConversionAtToWorkspace6Inport1[0] =
    rtu_sensordata_datin_Inport_6_e;
  rtb_TmpSignalConversionAtToWorkspace6Inport1[1] =
    rtu_sensordata_datin_Inport_6_c;
  rtb_TmpSignalConversionAtToWorkspace6Inport1[2] =
    rtu_sensordata_datin_Inport_6_cg;
  rtb_TmpSignalConversionAtToWorkspace6Inport1[3] =
    rtu_sensordata_datin_Inport_6_i;
  rtb_TmpSignalConversionAtToWorkspace6Inport1[4] =
    rtu_sensordata_datin_Inport_6_h;
  rtb_TmpSignalConversionAtToWorkspace6Inport1[5] =
    rtu_sensordata_datin_Inport_6_b;
  rtb_TmpSignalConversionAtToWorkspace6Inport1[6] =
    rtu_sensordata_datin_Inport_6_dz;
  rtb_TmpSignalConversionAtToWorkspace6Inport1[7] = rtb_DataTypeConversion1;
  rtb_TmpSignalConversionAtToWorkspace6Inport1[8] = rtb_DataTypeConversion2;

  /* ToWorkspace: '<S3>/To Workspace6' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace6_PWORK.LoggedData,
                          &locTime,
                          &rtb_TmpSignalConversionAtToWorkspace6Inport1[0]);
  }
}

/* ConstCode for atomic system: '<S1>/Logging' */
void flightControlSystem_Logging_Const(real_T rtu_posRef,
  DW_Logging_flightControlSystem_T *localDW)
{
  /* ConstCode for ToWorkspace: '<S3>/To Workspace1' */
  {
    real_T u[1];

    {
      int32_T i;
      for (i = 0; i < 1; i++) {
        u[i] = rtu_posRef;
      }
    }

    {
      double locTime = 0.0;
      ;
      rt_UpdateStructLogVar((StructLogVar *)
                            localDW->ToWorkspace1_PWORK.LoggedData, &locTime, u);
    }
  }
}

/* System initialize for atomic system: '<Root>/Flight Control System' */
void flightControlSystem_FlightControlSystem_Init(RT_MODEL_flightControlSystem_T
  * const flightControlSystem_M, DW_FlightControlSystem_flightControlSystem_T
  *localDW)
{
  /* InitializeConditions for Memory: '<S4>/Memory' */
  localDW->Memory_PreviousInput = flightControlSystem_rtZstatesEstim_t;

  /* SystemInitialize for ModelReference: '<S1>/estimator' */
  stateEstimator_Init();

  /* SystemInitialize for ModelReference: '<S1>/controller' */
  flightController_Init();

  /* SystemInitialize for Atomic SubSystem: '<S1>/Logging' */
  flightControlSystem_Logging_Init(flightControlSystem_M, &localDW->Logging);

  /* End of SystemInitialize for SubSystem: '<S1>/Logging' */

  /* SystemInitialize for Merge: '<S2>/Merge' */
  flag_outport = ((uint8_T)0U);
}

/* Output and update for atomic system: '<Root>/Flight Control System' */
void flightControlSystem_FlightControlSystem(RT_MODEL_flightControlSystem_T *
  const flightControlSystem_M, const CommandBus *rtu_ReferenceValueServerCmds,
  const SensorsBus *rtu_Sensors, DW_FlightControlSystem_flightControlSystem_T
  *localDW)
{
  /* local block i/o variables */
  statesEstim_t rtb_estimator;
  statesEstim_t rtb_Memory;
  uint32_T rtb_vbat_percentage;
  real32_T rtb_x;
  real32_T rtb_y;
  real32_T rtb_z;
  real32_T rtb_x_c;
  real32_T rtb_y_n;
  real32_T rtb_z_p;
  real32_T rtb_pressure;
  real32_T rtb_vbat_V;
  CommandBus rtb_BusCreator;
  sensordata_t rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1;

  /* BusCreator: '<S4>/Bus Creator' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant3'
   *  Constant: '<S4>/Constant4'
   */
  rtb_BusCreator.controlModePosVSOrient = true;
  rtb_BusCreator.takeoff_flag = true;
  rtb_BusCreator.pos_ref[0] = 0.0F;
  rtb_BusCreator.orient_ref[0] = 0.0F;
  rtb_BusCreator.pos_ref[1] = 0.0F;
  rtb_BusCreator.orient_ref[1] = 0.0F;
  rtb_BusCreator.pos_ref[2] = (-0.7F);
  rtb_BusCreator.orient_ref[2] = 0.0F;

  /* SignalConversion generated from: '<S5>/Bus Selector3' */
  rtb_x = rtu_Sensors->HALSensors.HAL_acc_SI.x;

  /* SignalConversion generated from: '<S5>/Bus Selector3' */
  rtb_y = rtu_Sensors->HALSensors.HAL_acc_SI.y;

  /* SignalConversion generated from: '<S5>/Bus Selector3' */
  rtb_z = rtu_Sensors->HALSensors.HAL_acc_SI.z;

  /* SignalConversion generated from: '<S5>/Bus Selector4' */
  rtb_x_c = rtu_Sensors->HALSensors.HAL_gyro_SI.x;

  /* SignalConversion generated from: '<S5>/Bus Selector4' */
  rtb_y_n = rtu_Sensors->HALSensors.HAL_gyro_SI.y;

  /* SignalConversion generated from: '<S5>/Bus Selector4' */
  rtb_z_p = rtu_Sensors->HALSensors.HAL_gyro_SI.z;

  /* SignalConversion generated from: '<S5>/Bus Selector6' */
  rtb_pressure = rtu_Sensors->HALSensors.HAL_pressure_SI.pressure;

  /* SignalConversion generated from: '<S5>/Bus Selector1' */
  rtb_vbat_V = rtu_Sensors->HALSensors.HAL_vbat_SI.vbat_V;

  /* SignalConversion generated from: '<S5>/Bus Selector1' */
  rtb_vbat_percentage = rtu_Sensors->HALSensors.HAL_vbat_SI.vbat_percentage;

  /* BusCreator generated from: '<S1>/estimator' */
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddx = rtb_x;
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddy = rtb_y;
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddz = rtb_z;
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.p = rtb_x_c;
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.q = rtb_y_n;
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.r = rtb_z_p;
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.prs =
    rtb_pressure;
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.vbat_V =
    rtb_vbat_V;
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.vbat_percentage
    = rtb_vbat_percentage;

  /* ModelReference: '<S1>/estimator' */
  stateEstimator(&rtb_BusCreator.controlModePosVSOrient,
                 &rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1,
                 &rtu_Sensors->SensorCalibration[0], &rtb_estimator);

  /* ModelReference: '<S1>/controller' */
  flightController(&rtb_BusCreator, &rtb_estimator, &motors_outport[0]);

  /* Outputs for Atomic SubSystem: '<S1>/Logging' */
  flightControlSystem_Logging(flightControlSystem_M, motors_outport,
    &rtb_estimator, rtu_ReferenceValueServerCmds, rtu_Sensors, rtb_vbat_V,
    rtb_vbat_percentage, rtb_x, rtb_y, rtb_z, rtb_x_c, rtb_y_n, rtb_z_p,
    rtb_pressure, &localDW->Logging);

  /* End of Outputs for SubSystem: '<S1>/Logging' */

  /* If: '<S2>/If' incorporates:
   *  Abs: '<S2>/Abs'
   *  Abs: '<S2>/Abs1'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Logic: '<S2>/Logical Operator'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   */
  if (((real32_T)fabs(rtb_estimator.X) > 10.0F) || ((real32_T)fabs
       (rtb_estimator.Y) > 10.0F)) {
    /* Outputs for IfAction SubSystem: '<S2>/Geofencing error' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S8>/Constant'
     *  SignalConversion generated from: '<S8>/Out1'
     */
    flag_outport = ((uint8_T)1U);

    /* End of Outputs for SubSystem: '<S2>/Geofencing error' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/Normal condition' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S9>/Constant'
     *  SignalConversion generated from: '<S9>/Out1'
     */
    flag_outport = ((uint8_T)0U);

    /* End of Outputs for SubSystem: '<S2>/Normal condition' */
  }

  /* End of If: '<S2>/If' */

  /* Memory: '<S4>/Memory' */
  rtb_Memory = localDW->Memory_PreviousInput;

  /* Update for Memory: '<S4>/Memory' */
  localDW->Memory_PreviousInput = rtb_estimator;
}

/* ConstCode for atomic system: '<Root>/Flight Control System' */
void flightControlSystem_FlightControlSystem_Const
  (DW_FlightControlSystem_flightControlSystem_T *localDW)
{
  /* ConstCode for Atomic SubSystem: '<S1>/Logging' */
  flightControlSystem_Logging_Const(0.0, &localDW->Logging);

  /* End of ConstCode for SubSystem: '<S1>/Logging' */
}

/* Model step function */
void flightControlSystem_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/Flight Control System' */

  /* Inport: '<Root>/AC cmd' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  flightControlSystem_FlightControlSystem(flightControlSystem_M, &cmd_inport,
    &sensor_inport, &flightControlSystem_DW.FlightControlSystem);

  /* End of Outputs for SubSystem: '<Root>/Flight Control System' */

  /* Outport: '<Root>/Actuators' */
  flightControlSystem_Y.Actuators[0] = motors_outport[0];
  flightControlSystem_Y.Actuators[1] = motors_outport[1];
  flightControlSystem_Y.Actuators[2] = motors_outport[2];
  flightControlSystem_Y.Actuators[3] = motors_outport[3];

  /* Outport: '<Root>/Flag' */
  flightControlSystem_Y.Flag = flag_outport;

  /* Matfile logging */
  rt_UpdateTXYLogVars(flightControlSystem_M->rtwLogInfo,
                      (&flightControlSystem_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(flightControlSystem_M)!=-1) &&
        !((rtmGetTFinal(flightControlSystem_M)-
           flightControlSystem_M->Timing.taskTime0) >
          flightControlSystem_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(flightControlSystem_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++flightControlSystem_M->Timing.clockTick0)) {
    ++flightControlSystem_M->Timing.clockTickH0;
  }

  flightControlSystem_M->Timing.taskTime0 =
    flightControlSystem_M->Timing.clockTick0 *
    flightControlSystem_M->Timing.stepSize0 +
    flightControlSystem_M->Timing.clockTickH0 *
    flightControlSystem_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void flightControlSystem_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)flightControlSystem_M, 0,
                sizeof(RT_MODEL_flightControlSystem_T));
  rtmSetTFinal(flightControlSystem_M, 30.0);
  flightControlSystem_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    flightControlSystem_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(flightControlSystem_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(flightControlSystem_M->rtwLogInfo, (NULL));
    rtliSetLogT(flightControlSystem_M->rtwLogInfo, "tout");
    rtliSetLogX(flightControlSystem_M->rtwLogInfo, "");
    rtliSetLogXFinal(flightControlSystem_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(flightControlSystem_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(flightControlSystem_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(flightControlSystem_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(flightControlSystem_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &flightControlSystem_Y.Actuators[0],
        &flightControlSystem_Y.Flag
      };

      rtliSetLogYSignalPtrs(flightControlSystem_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        4,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        4,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_SINGLE,
        SS_UINT8
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL),
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "motors",
        "flag" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "flightControlSystem/Actuators",
        "flightControlSystem/Flag" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_SINGLE, SS_SINGLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_UINT8, SS_UINT8, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          2,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),
          rt_LoggingPreprocessingFcnPtrs,

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(flightControlSystem_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(flightControlSystem_M->rtwLogInfo, "yout");
  }

  /* block I/O */

  /* exported global signals */
  motors_outport[0] = 0.0F;
  motors_outport[1] = 0.0F;
  motors_outport[2] = 0.0F;
  motors_outport[3] = 0.0F;
  flag_outport = 0U;

  /* states (dwork) */
  (void) memset((void *)&flightControlSystem_DW, 0,
                sizeof(DW_flightControlSystem_T));

  /* external inputs */
  (void)memset(&cmd_inport, 0, sizeof(CommandBus));
  (void)memset(&sensor_inport, 0, sizeof(SensorsBus));

  /* external outputs */
  (void) memset((void *)&flightControlSystem_Y, 0,
                sizeof(ExtY_flightControlSystem_T));

  /* Model Initialize function for ModelReference Block: '<S1>/controller' */
  flightController_initialize(rtmGetErrorStatusPointer(flightControlSystem_M));

  /* Model Initialize function for ModelReference Block: '<S1>/estimator' */
  stateEstimator_initialize(rtmGetErrorStatusPointer(flightControlSystem_M));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(flightControlSystem_M->rtwLogInfo, 0.0,
    rtmGetTFinal(flightControlSystem_M), flightControlSystem_M->Timing.stepSize0,
    (&rtmGetErrorStatus(flightControlSystem_M)));

  /* SystemInitialize for Atomic SubSystem: '<Root>/Flight Control System' */

  /* SystemInitialize for Inport: '<Root>/Sensors' */
  flightControlSystem_FlightControlSystem_Init(flightControlSystem_M,
    &flightControlSystem_DW.FlightControlSystem);

  /* End of SystemInitialize for SubSystem: '<Root>/Flight Control System' */

  /* ConstCode for Atomic SubSystem: '<Root>/Flight Control System' */
  flightControlSystem_FlightControlSystem_Const
    (&flightControlSystem_DW.FlightControlSystem);

  /* End of ConstCode for SubSystem: '<Root>/Flight Control System' */
}

/* Model terminate function */
void flightControlSystem_terminate(void)
{
  /* (no terminate code required) */
}
