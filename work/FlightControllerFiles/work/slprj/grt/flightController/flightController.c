/*
 * Code generation for system model 'flightController'
 *
 * Model                      : flightController
 * Model version              : 4.2
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue Apr  5 22:10:57 2022
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "flightController.h"
#include "flightController_private.h"

MdlrefDW_flightController_T flightController_MdlrefDW;

/* Block states (default storage) */
DW_flightController_f_T flightController_DW;

/* System initialize for referenced model: 'flightController' */
void flightController_Init(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for Delay: '<S3>/Delay' */
  flightController_DW.Delay_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for Delay: '<S3>/Delay' */
  flightController_DW.Delay_DSTATE[1] = 0.0F;
}

/* System reset for referenced model: 'flightController' */
void flightController_Reset(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for Delay: '<S3>/Delay' */
  flightController_DW.Delay_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for Delay: '<S3>/Delay' */
  flightController_DW.Delay_DSTATE[1] = 0.0F;
}

/* Output and update for referenced model: 'flightController' */
void flightController(const CommandBus *rtu_ReferenceValueServerBus, const
                      statesEstim_t *rtu_states_estim, real32_T
                      rty_motors_refout[4])
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
   *  Sum: '<S6>/Sum15'
   *  Sum: '<S6>/Sum3'
   */
  u0 = ((rtu_ReferenceValueServerBus->pos_ref[2] - rtu_states_estim->Z) * 0.8F -
        0.3F * rtu_states_estim->dz) + (-0.61803F);

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
   *  Sum: '<S5>/Sum1'
   */
  rtb_Sum2 = (rtu_ReferenceValueServerBus->orient_ref[0] - rtu_states_estim->yaw)
    * 0.004F - 0.0012F * rtu_states_estim->r;

  /* Trigonometry: '<S4>/Trigonometric Function' */
  rtb_TrigonometricFunction_o1 = (real32_T)sin(rtu_states_estim->yaw);
  rtb_TrigonometricFunction_o2 = (real32_T)cos(rtu_states_estim->yaw);

  /* Sum: '<S4>/Sum17' */
  rtb_DiscreteTimeIntegrator_idx_1 = rtu_ReferenceValueServerBus->pos_ref[0] -
    rtu_states_estim->X;
  u0 = rtu_ReferenceValueServerBus->pos_ref[1] - rtu_states_estim->Y;

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
   *  Sum: '<S4>/Sum18'
   */
  rtb_pitchrollerror_idx_0 = ((-0.24F) * rtb_pitchrollerror_idx_0 + 0.1F *
    rtu_states_estim->dx) - rtu_states_estim->pitch;

  /* Saturate: '<S4>/Saturation' */
  if (u0 > 3.0F) {
    u0 = 3.0F;
  } else if (u0 < (-3.0F)) {
    u0 = (-3.0F);
  }

  /* Sum: '<S3>/Sum19' incorporates:
   *  Gain: '<S4>/D_xy'
   *  Gain: '<S4>/P_xy'
   *  Sum: '<S4>/Sum18'
   */
  rtb_pitchrollerror_idx_1 = (0.24F * u0 + (-0.1F) * rtu_states_estim->dy) -
    rtu_states_estim->roll;

  /* SignalConversion generated from: '<S2>/Product' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Gain: '<S3>/D_pr'
   *  Gain: '<S3>/I_pr'
   *  Gain: '<S3>/P_pr'
   *  Sum: '<S3>/Sum16'
   */
  rtb_SaturationThrust_idx_2 = (0.013F * rtb_pitchrollerror_idx_0 + 0.01F *
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0]) - 0.002F *
    rtu_states_estim->q;
  rtb_SaturationThrust_idx_3 = (0.01F * rtb_pitchrollerror_idx_1 + 0.01F *
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1]) - 0.0028F *
    rtu_states_estim->p;
  for (i = 0; i < 4; i++) {
    /* Saturate: '<S7>/Saturation5' incorporates:
     *  Constant: '<S2>/TorqueTotalThrustToThrustPerMotor'
     *  Gain: '<S7>/ThrustToMotorCommand'
     *  Product: '<S2>/Product'
     *  SignalConversion generated from: '<S2>/Product'
     */
    u0 = (-1530.72681F) * (rtCP_TorqueTotalThrustToThrustPerMotor_Value[i + 12] *
      rtb_SaturationThrust_idx_3 +
      (rtCP_TorqueTotalThrustToThrustPerMotor_Value[i + 8] *
       rtb_SaturationThrust_idx_2 +
       (rtCP_TorqueTotalThrustToThrustPerMotor_Value[i + 4] * rtb_Sum2 +
        rtCP_TorqueTotalThrustToThrustPerMotor_Value[i] * rtb_SaturationThrust)));
    if (u0 > 500.0F) {
      u0 = 500.0F;
    } else if (u0 < 10.0F) {
      u0 = 10.0F;
    }

    /* End of Saturate: '<S7>/Saturation5' */

    /* Gain: '<S7>/MotorDirections' */
    rty_motors_refout[i] = rtCP_MotorDirections_Gain[i] * u0;
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
}

/* Model initialize function */
void flightController_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_flightController_T *const flightController_M =
    &(flightController_MdlrefDW.rtm);

  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(flightController_M, rt_errorStatus);

  /* states (dwork) */
  (void) memset((void *)&flightController_DW, 0,
                sizeof(DW_flightController_f_T));
}
