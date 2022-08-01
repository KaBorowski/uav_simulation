/*
 * flightController.c
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

#include "flightController.h"
#include "flightController_private.h"

/* Block states (default storage) */
DW_flightController_T flightController_DW;

/* External inputs (root inport signals with default storage) */
ExtU_flightController_T flightController_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_flightController_T flightController_Y;

/* Real-time model */
static RT_MODEL_flightController_T flightController_M_;
RT_MODEL_flightController_T *const flightController_M = &flightController_M_;

/* Model step function */
void flightController_step(void)
{
  int32_T i;
  real32_T rtb_DiscreteTimeIntegrator_idx_0;
  real32_T rtb_DiscreteTimeIntegrator_idx_1;
  real32_T rtb_SaturationThrust;
  real32_T rtb_SaturationThrust_idx_2;
  real32_T rtb_SaturationThrust_idx_3;
  real32_T rtb_Sum2;
  real32_T rtb_TrigonometricFunction_o1;
  real32_T rtb_TrigonometricFunction_o2;
  real32_T rtb_pitchrollerror_idx_0;
  real32_T rtb_pitchrollerror_idx_1;
  real32_T u0;

  /* Sum: '<S6>/Sum4' incorporates:
   *  Constant: '<S6>/Drone weight'
   *  Gain: '<S6>/D_z'
   *  Gain: '<S6>/P_z'
   *  Inport: '<Root>/ReferenceValueServerBus'
   *  Inport: '<Root>/states_estim'
   *  Sum: '<S6>/Sum15'
   *  Sum: '<S6>/Sum3'
   */
  u0 = ((flightController_U.ReferenceValueServerBus.pos_ref[2] -
         flightController_U.states_estim.Z) * 0.8F - 0.3F *
        flightController_U.states_estim.dz) + (-0.61803F);

  /* Saturate: '<S6>/SaturationThrust' */
  if (u0 > 1.20204329F) {
    rtb_SaturationThrust = 1.20204329F;
  } else if (u0 < (-1.20204329F)) {
    rtb_SaturationThrust = (-1.20204329F);
  } else {
    rtb_SaturationThrust = u0;
  }

  /* End of Saturate: '<S6>/SaturationThrust' */

  /* Sum: '<S5>/Sum2' incorporates:
   *  Gain: '<S5>/D_yaw'
   *  Gain: '<S5>/P_yaw'
   *  Inport: '<Root>/ReferenceValueServerBus'
   *  Inport: '<Root>/states_estim'
   *  Sum: '<S5>/Sum1'
   */
  rtb_Sum2 = (flightController_U.ReferenceValueServerBus.orient_ref[0] -
              flightController_U.states_estim.yaw) * 0.004F - 0.0012F *
    flightController_U.states_estim.r;

  /* Trigonometry: '<S4>/Trigonometric Function' incorporates:
   *  Inport: '<Root>/states_estim'
   */
  rtb_TrigonometricFunction_o1 = (real32_T)sin
    (flightController_U.states_estim.yaw);
  rtb_TrigonometricFunction_o2 = (real32_T)cos
    (flightController_U.states_estim.yaw);

  /* Sum: '<S4>/Sum17' incorporates:
   *  Inport: '<Root>/ReferenceValueServerBus'
   *  Inport: '<Root>/states_estim'
   */
  rtb_DiscreteTimeIntegrator_idx_1 =
    flightController_U.ReferenceValueServerBus.pos_ref[0] -
    flightController_U.states_estim.X;
  u0 = flightController_U.ReferenceValueServerBus.pos_ref[1] -
    flightController_U.states_estim.Y;

  /* Product: '<S4>/Product' incorporates:
   *  SignalConversion generated from: '<S4>/Vector Concatenate1'
   *  SignalConversion generated from: '<S4>/Vector Concatenate'
   */
  rtb_pitchrollerror_idx_0 = rtb_TrigonometricFunction_o2 *
    rtb_DiscreteTimeIntegrator_idx_1 + rtb_TrigonometricFunction_o1 * u0;

  /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_idx_0 =
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0];

  /* Product: '<S4>/Product' incorporates:
   *  Gain: '<S4>/Gain'
   *  SignalConversion generated from: '<S4>/Vector Concatenate1'
   */
  u0 = (-1.0F) * rtb_TrigonometricFunction_o1 * rtb_DiscreteTimeIntegrator_idx_1
    + rtb_TrigonometricFunction_o2 * u0;

  /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_idx_1 =
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1];

  /* Saturate: '<S4>/Saturation' */
  if (rtb_pitchrollerror_idx_0 > 3.0F) {
    rtb_pitchrollerror_idx_0 = 3.0F;
  } else if (rtb_pitchrollerror_idx_0 < (-3.0F)) {
    rtb_pitchrollerror_idx_0 = (-3.0F);
  }

  /* Sum: '<S3>/Sum19' incorporates:
   *  Gain: '<S4>/D_xy'
   *  Gain: '<S4>/P_xy'
   *  Inport: '<Root>/states_estim'
   *  Sum: '<S4>/Sum18'
   */
  rtb_pitchrollerror_idx_0 = ((-0.24F) * rtb_pitchrollerror_idx_0 + 0.1F *
    flightController_U.states_estim.dx) - flightController_U.states_estim.pitch;

  /* Saturate: '<S4>/Saturation' */
  if (u0 > 3.0F) {
    u0 = 3.0F;
  } else if (u0 < (-3.0F)) {
    u0 = (-3.0F);
  }

  /* Sum: '<S3>/Sum19' incorporates:
   *  Gain: '<S4>/D_xy'
   *  Gain: '<S4>/P_xy'
   *  Inport: '<Root>/states_estim'
   *  Sum: '<S4>/Sum18'
   */
  rtb_pitchrollerror_idx_1 = (0.24F * u0 + (-0.1F) *
    flightController_U.states_estim.dy) - flightController_U.states_estim.roll;

  /* SignalConversion generated from: '<S2>/Product' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Gain: '<S3>/D_pr'
   *  Gain: '<S3>/I_pr'
   *  Gain: '<S3>/P_pr'
   *  Inport: '<Root>/states_estim'
   *  Sum: '<S3>/Sum16'
   */
  rtb_SaturationThrust_idx_2 = (0.013F * rtb_pitchrollerror_idx_0 + 0.01F *
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0]) - 0.002F *
    flightController_U.states_estim.q;
  rtb_SaturationThrust_idx_3 = (0.01F * rtb_pitchrollerror_idx_1 + 0.01F *
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1]) - 0.0028F *
    flightController_U.states_estim.p;
  for (i = 0; i < 4; i++) {
    /* Saturate: '<S7>/Saturation5' incorporates:
     *  Constant: '<S2>/TorqueTotalThrustToThrustPerMotor'
     *  Gain: '<S7>/ThrustToMotorCommand'
     *  Product: '<S2>/Product'
     *  SignalConversion generated from: '<S2>/Product'
     */
    u0 = (-1530.72681F) *
      (flightController_ConstP.TorqueTotalThrustToThrustPerMotor_Value[i + 12] *
       rtb_SaturationThrust_idx_3 +
       (flightController_ConstP.TorqueTotalThrustToThrustPerMotor_Value[i + 8] *
        rtb_SaturationThrust_idx_2 +
        (flightController_ConstP.TorqueTotalThrustToThrustPerMotor_Value[i + 4] *
         rtb_Sum2 +
         flightController_ConstP.TorqueTotalThrustToThrustPerMotor_Value[i] *
         rtb_SaturationThrust)));
    if (u0 > 500.0F) {
      u0 = 500.0F;
    } else if (u0 < 10.0F) {
      u0 = 10.0F;
    }

    /* End of Saturate: '<S7>/Saturation5' */

    /* Outport: '<Root>/motors_refout' incorporates:
     *  Gain: '<S7>/MotorDirections'
     */
    flightController_Y.motors_refout[i] =
      flightController_ConstP.MotorDirections_Gain[i] * u0;
  }

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S3>/Delay'
   *  Gain: '<S3>/antiWU_Gain'
   *  Sum: '<S3>/Add'
   */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] +=
    (rtb_pitchrollerror_idx_0 - 0.001F * flightController_DW.Delay_DSTATE[0]) *
    0.005F;
  if (flightController_DW.DiscreteTimeIntegrator_DSTATE[0] >= 2.0F) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0] = 2.0F;
  } else if (flightController_DW.DiscreteTimeIntegrator_DSTATE[0] <= (-2.0F)) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0] = (-2.0F);
  }

  /* Update for Delay: '<S3>/Delay' */
  flightController_DW.Delay_DSTATE[0] = rtb_DiscreteTimeIntegrator_idx_0;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S3>/Delay'
   *  Gain: '<S3>/antiWU_Gain'
   *  Sum: '<S3>/Add'
   */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] +=
    (rtb_pitchrollerror_idx_1 - 0.001F * flightController_DW.Delay_DSTATE[1]) *
    0.005F;
  if (flightController_DW.DiscreteTimeIntegrator_DSTATE[1] >= 2.0F) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1] = 2.0F;
  } else if (flightController_DW.DiscreteTimeIntegrator_DSTATE[1] <= (-2.0F)) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1] = (-2.0F);
  }

  /* Update for Delay: '<S3>/Delay' */
  flightController_DW.Delay_DSTATE[1] = rtb_DiscreteTimeIntegrator_idx_1;

  /* Matfile logging */
  rt_UpdateTXYLogVars(flightController_M->rtwLogInfo,
                      (&flightController_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(flightController_M)!=-1) &&
        !((rtmGetTFinal(flightController_M)-flightController_M->Timing.taskTime0)
          > flightController_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(flightController_M, "Simulation finished");
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
  if (!(++flightController_M->Timing.clockTick0)) {
    ++flightController_M->Timing.clockTickH0;
  }

  flightController_M->Timing.taskTime0 = flightController_M->Timing.clockTick0 *
    flightController_M->Timing.stepSize0 +
    flightController_M->Timing.clockTickH0 *
    flightController_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void flightController_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)flightController_M, 0,
                sizeof(RT_MODEL_flightController_T));
  rtmSetTFinal(flightController_M, 30.0);
  flightController_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    flightController_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(flightController_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(flightController_M->rtwLogInfo, (NULL));
    rtliSetLogT(flightController_M->rtwLogInfo, "tout");
    rtliSetLogX(flightController_M->rtwLogInfo, "");
    rtliSetLogXFinal(flightController_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(flightController_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(flightController_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(flightController_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(flightController_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &flightController_Y.motors_refout[0]
      };

      rtliSetLogYSignalPtrs(flightController_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        4
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        4
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_SINGLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "flightController/motors_refout" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_SINGLE, SS_SINGLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
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

      rtliSetLogYSignalInfo(flightController_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(flightController_M->rtwLogInfo, "yout");
  }

  /* states (dwork) */
  (void) memset((void *)&flightController_DW, 0,
                sizeof(DW_flightController_T));

  /* external inputs */
  (void)memset(&flightController_U, 0, sizeof(ExtU_flightController_T));

  /* external outputs */
  (void) memset(&flightController_Y.motors_refout[0], 0,
                4U*sizeof(real32_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(flightController_M->rtwLogInfo, 0.0,
    rtmGetTFinal(flightController_M), flightController_M->Timing.stepSize0,
    (&rtmGetErrorStatus(flightController_M)));

  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for Delay: '<S3>/Delay' */
  flightController_DW.Delay_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for Delay: '<S3>/Delay' */
  flightController_DW.Delay_DSTATE[1] = 0.0F;
}

/* Model terminate function */
void flightController_terminate(void)
{
  /* (no terminate code required) */
}
