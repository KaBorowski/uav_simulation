/*
 * Code generation for system model 'stateEstimator'
 *
 * Model                      : stateEstimator
 * Model version              : 4.7
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Sun Jul  3 22:40:39 2022
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "stateEstimator.h"
#include "stateEstimator_private.h"
#include "rt_powf_snf.h"

MdlrefDW_stateEstimator_T stateEstimator_MdlrefDW;

/* Block signals (default storage) */
B_stateEstimator_c_T stateEstimator_B;

/* Block states (default storage) */
DW_stateEstimator_f_T stateEstimator_DW;

/* System initialize for referenced model: 'stateEstimator' */
void stateEstimator_Init(void)
{
  int32_T i;

  /* InitializeConditions for DiscreteIntegrator: '<S69>/SimplyIntegrateVelocity' */
  stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[0] = 0.0F;
  stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[1] = 0.0F;
  stateEstimator_DW.SimplyIntegrateVelocity_PrevResetState = 2;

  /* InitializeConditions for Delay: '<S3>/Delay2' */
  stateEstimator_DW.Delay2_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S12>/MemoryX' */
  stateEstimator_DW.icLoad = true;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  stateEstimator_DW.Memory_PreviousInput[0] = 0.0F;
  stateEstimator_DW.Memory_PreviousInput[1] = 0.0F;
  stateEstimator_DW.Memory_PreviousInput[2] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S75>/IIR_IMUgyro_r' */
  for (i = 0; i < 5; i++) {
    stateEstimator_DW.IIR_IMUgyro_r_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S75>/IIR_IMUgyro_r' */

  /* InitializeConditions for DiscreteFir: '<S75>/FIR_IMUaccel' */
  stateEstimator_DW.FIR_IMUaccel_circBuf = 0;
  for (i = 0; i < 15; i++) {
    stateEstimator_DW.FIR_IMUaccel_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFir: '<S75>/FIR_IMUaccel' */

  /* InitializeConditions for Delay: '<S1>/Delay1' */
  stateEstimator_DW.Delay1_DSTATE[0] = 0.0F;

  /* SystemInitialize for Enabled SubSystem: '<S40>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S66>/Product2' incorporates:
   *  Outport: '<S66>/deltax'
   */
  stateEstimator_B.Product2[0] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S40>/Enabled Subsystem' */

  /* SystemInitialize for Merge: '<S2>/Merge' */
  stateEstimator_B.Merge[0] = 0.0F;

  /* SystemInitialize for Enabled SubSystem: '<S34>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S64>/Product3' incorporates:
   *  Outport: '<S64>/L*(y[k]-yhat[k|k-1])'
   */
  stateEstimator_B.Product3[0] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S34>/MeasurementUpdate' */

  /* InitializeConditions for Delay: '<S1>/Delay1' */
  stateEstimator_DW.Delay1_DSTATE[1] = 0.0F;

  /* SystemInitialize for Enabled SubSystem: '<S40>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S66>/Product2' incorporates:
   *  Outport: '<S66>/deltax'
   */
  stateEstimator_B.Product2[1] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S40>/Enabled Subsystem' */

  /* SystemInitialize for Merge: '<S2>/Merge' */
  stateEstimator_B.Merge[1] = 0.0F;

  /* SystemInitialize for Enabled SubSystem: '<S34>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S64>/Product3' incorporates:
   *  Outport: '<S64>/L*(y[k]-yhat[k|k-1])'
   */
  stateEstimator_B.Product3[1] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S34>/MeasurementUpdate' */
}

/* System reset for referenced model: 'stateEstimator' */
void stateEstimator_Reset(void)
{
  int32_T i;

  /* InitializeConditions for DiscreteIntegrator: '<S69>/SimplyIntegrateVelocity' */
  stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[0] = 0.0F;
  stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[1] = 0.0F;
  stateEstimator_DW.SimplyIntegrateVelocity_PrevResetState = 2;

  /* InitializeConditions for Delay: '<S3>/Delay2' */
  stateEstimator_DW.Delay2_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S12>/MemoryX' */
  stateEstimator_DW.icLoad = true;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  stateEstimator_DW.Memory_PreviousInput[0] = 0.0F;
  stateEstimator_DW.Memory_PreviousInput[1] = 0.0F;
  stateEstimator_DW.Memory_PreviousInput[2] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S75>/IIR_IMUgyro_r' */
  for (i = 0; i < 5; i++) {
    stateEstimator_DW.IIR_IMUgyro_r_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S75>/IIR_IMUgyro_r' */

  /* InitializeConditions for DiscreteFir: '<S75>/FIR_IMUaccel' */
  stateEstimator_DW.FIR_IMUaccel_circBuf = 0;
  for (i = 0; i < 15; i++) {
    stateEstimator_DW.FIR_IMUaccel_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFir: '<S75>/FIR_IMUaccel' */

  /* InitializeConditions for Delay: '<S1>/Delay1' */
  stateEstimator_DW.Delay1_DSTATE[0] = 0.0F;
  stateEstimator_DW.Delay1_DSTATE[1] = 0.0F;
}

/* Disable for referenced model: 'stateEstimator' */
void stateEstimator_Disable(void)
{
  /* Disable for Enabled SubSystem: '<S40>/Enabled Subsystem' */
  if (stateEstimator_DW.EnabledSubsystem_MODE) {
    /* Disable for Product: '<S66>/Product2' incorporates:
     *  Outport: '<S66>/deltax'
     */
    stateEstimator_B.Product2[0] = 0.0;
    stateEstimator_B.Product2[1] = 0.0;
    stateEstimator_DW.EnabledSubsystem_MODE = false;
  }

  /* End of Disable for SubSystem: '<S40>/Enabled Subsystem' */

  /* Disable for Enabled SubSystem: '<S34>/MeasurementUpdate' */
  if (stateEstimator_DW.MeasurementUpdate_MODE) {
    /* Disable for Product: '<S64>/Product3' incorporates:
     *  Outport: '<S64>/L*(y[k]-yhat[k|k-1])'
     */
    stateEstimator_B.Product3[0] = 0.0;
    stateEstimator_B.Product3[1] = 0.0;
    stateEstimator_DW.MeasurementUpdate_MODE = false;
  }

  /* End of Disable for SubSystem: '<S34>/MeasurementUpdate' */
}

/* Output and update for referenced model: 'stateEstimator' */
void stateEstimator(const boolean_T *rtu_controlModePosVSOrient_flagin, const
                    sensordata_t *rtu_sensordata_datin, const real32_T
                    rtu_sensorCalibration_datin[8], statesEstim_t
                    *rty_states_estimout)
{
  /* local block i/o variables */
  real_T rtb_P[4];
  real_T rtb_FIR_IMUaccel_0[3];
  real_T rtb_Product1_d[3];
  real_T rtb_Add1;
  real_T rtb_Add_idx_0;
  real_T rtb_Add_idx_1;
  real_T rtb_Sum;
  real_T tmp;
  real_T tmp_0;
  int32_T cff;
  int32_T i;
  int32_T i_0;
  int32_T i_1;
  int32_T memIdx;
  real32_T rtb_VectorConcatenate[9];
  real32_T rtb_VectorConcatenate_4[9];
  real32_T rtb_VectorConcatenate_a[9];
  real32_T rtb_VectorConcatenate_e[9];
  real32_T rtb_VectorConcatenate_kk[9];
  real32_T rtb_Assumingthatcalibwasdonelevel[6];
  real32_T rtb_FIR_IMUaccel[3];
  real32_T rtb_MathFunction[3];
  real32_T rtb_Product_n[3];
  real32_T rtb_VectorConcatenate_e_0[3];
  real32_T rtb_Sqrt;
  real32_T rtb_TrigonometricFunction_o1_idx_0;
  real32_T rtb_TrigonometricFunction_o1_idx_1;
  real32_T rtb_TrigonometricFunction_o2_idx_0;
  real32_T rtb_TrigonometricFunction_o2_idx_1;
  real32_T rtb_VectorConcatenate_j_tmp;
  real32_T rtb_VectorConcatenate_j_tmp_0;
  real32_T rtb_VectorConcatenate_j_tmp_1;
  real32_T rtb_VectorConcatenate_j_tmp_2;
  real32_T rtb_VectorConcatenate_j_tmp_3;
  real32_T rtb_VectorConcatenate_j_tmp_4;
  real32_T rtb_VectorConcatenate_j_tmp_5;
  real32_T rtb_VectorConcatenate_j_tmp_tmp;
  real32_T rtb_gainaccinput_idx_1;
  real32_T rtb_sincos_o1_idx_1;
  real32_T rtb_sincos_o1_idx_2_tmp_tmp;
  real32_T rtb_sincos_o2_idx_1_tmp_tmp;
  real32_T rtb_sincos_o2_idx_2_tmp_tmp;

  /* DiscreteIntegrator: '<S69>/SimplyIntegrateVelocity' */
  if ((*rtu_controlModePosVSOrient_flagin) &&
      (stateEstimator_DW.SimplyIntegrateVelocity_PrevResetState <= 0)) {
    stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[0] = 0.0F;
    stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[1] = 0.0F;
  }

  /* Gain: '<S3>/prsToAltGain' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  Sum: '<S77>/Sum2'
   */
  stateEstimator_B.altfrompress = (real_T)(rtu_sensordata_datin->prs -
    rtu_sensorCalibration_datin[6]) * 0.0832137167F;

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   *  Delay: '<S3>/Delay2'
   */
  stateEstimator_B.Compare = (stateEstimator_DW.Delay2_DSTATE > 0.0);

  /* Delay: '<S12>/MemoryX' incorporates:
   *  DataTypeConversion: '<S12>/DataTypeConversionReset'
   */
  stateEstimator_DW.icLoad = (stateEstimator_B.Compare ||
    stateEstimator_DW.icLoad);
  if (stateEstimator_DW.icLoad) {
    stateEstimator_DW.MemoryX_DSTATE[0] = stateEstimator_ConstB.ReshapeX0[0];
    stateEstimator_DW.MemoryX_DSTATE[1] = stateEstimator_ConstB.ReshapeX0[1];
  }

  /* Outputs for Enabled SubSystem: '<S40>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S66>/Enable'
   */
  /* Constant: '<S12>/Enable' */
  if (true) {
    stateEstimator_DW.EnabledSubsystem_MODE = true;

    /* Sum: '<S66>/Add1' incorporates:
     *  Constant: '<S12>/C'
     *  Delay: '<S12>/MemoryX'
     *  Product: '<S66>/Product'
     *  Reshape: '<S12>/Reshapey'
     */
    rtb_Add1 = stateEstimator_B.altfrompress - (1.0 *
      stateEstimator_DW.MemoryX_DSTATE[0] + 0.0 *
      stateEstimator_DW.MemoryX_DSTATE[1]);

    /* Product: '<S66>/Product2' incorporates:
     *  DataTypeConversion: '<S57>/Conversion'
     */
    stateEstimator_B.Product2[0] = stateEstimator_ConstB.Conversion_i[0] *
      rtb_Add1;
    stateEstimator_B.Product2[1] = stateEstimator_ConstB.Conversion_i[1] *
      rtb_Add1;
  } else if (stateEstimator_DW.EnabledSubsystem_MODE) {
    /* Disable for Product: '<S66>/Product2' incorporates:
     *  Outport: '<S66>/deltax'
     */
    stateEstimator_B.Product2[0] = 0.0;
    stateEstimator_B.Product2[1] = 0.0;
    stateEstimator_DW.EnabledSubsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S40>/Enabled Subsystem' */

  /* Sum: '<S40>/Add' incorporates:
   *  Delay: '<S12>/MemoryX'
   */
  rtb_Add_idx_0 = stateEstimator_B.Product2[0] +
    stateEstimator_DW.MemoryX_DSTATE[0];
  rtb_Add_idx_1 = stateEstimator_B.Product2[1] +
    stateEstimator_DW.MemoryX_DSTATE[1];

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Reshape: '<S12>/Reshapexhat'
   */
  rty_states_estimout->Z = (real32_T)rtb_Add_idx_0;

  /* SignalConversion generated from: '<S11>/Vector Concatenate' incorporates:
   *  Constant: '<S10>/Constant'
   */
  rtb_VectorConcatenate[0] = 0.0F;

  /* SignalConversion generated from: '<S11>/Vector Concatenate' incorporates:
   *  Constant: '<S10>/Constant'
   */
  rtb_VectorConcatenate[1] = 0.0F;

  /* Trigonometry: '<S10>/Trigonometric Function' incorporates:
   *  Memory: '<S2>/Memory'
   *  SignalConversion generated from: '<S10>/Trigonometric Function'
   */
  rtb_TrigonometricFunction_o1_idx_0 = (real32_T)sin
    (stateEstimator_DW.Memory_PreviousInput[2]);
  rtb_TrigonometricFunction_o2_idx_0 = (real32_T)cos
    (stateEstimator_DW.Memory_PreviousInput[2]);
  rtb_TrigonometricFunction_o1_idx_1 = (real32_T)sin
    (stateEstimator_DW.Memory_PreviousInput[1]);
  rtb_TrigonometricFunction_o2_idx_1 = (real32_T)cos
    (stateEstimator_DW.Memory_PreviousInput[1]);

  /* SignalConversion generated from: '<S11>/Vector Concatenate' */
  rtb_VectorConcatenate[2] = rtb_TrigonometricFunction_o2_idx_1;

  /* SignalConversion generated from: '<S11>/Vector Concatenate' */
  rtb_VectorConcatenate[3] = rtb_TrigonometricFunction_o1_idx_0;

  /* Product: '<S10>/Product1' */
  rtb_VectorConcatenate[4] = rtb_TrigonometricFunction_o2_idx_0 *
    rtb_TrigonometricFunction_o2_idx_1;

  /* Product: '<S10>/Product3' */
  rtb_VectorConcatenate[5] = rtb_TrigonometricFunction_o1_idx_0 *
    rtb_TrigonometricFunction_o1_idx_1;

  /* SignalConversion generated from: '<S11>/Vector Concatenate' */
  rtb_VectorConcatenate[6] = rtb_TrigonometricFunction_o2_idx_0;

  /* Product: '<S10>/Product2' incorporates:
   *  Gain: '<S10>/Gain'
   */
  rtb_VectorConcatenate[7] = (-1.0F) * rtb_TrigonometricFunction_o1_idx_0 *
    rtb_TrigonometricFunction_o2_idx_1;

  /* Product: '<S10>/Product4' */
  rtb_VectorConcatenate[8] = rtb_TrigonometricFunction_o2_idx_0 *
    rtb_TrigonometricFunction_o1_idx_1;

  /* Bias: '<S78>/Assuming that calib was done level!' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   */
  for (i_1 = 0; i_1 < 6; i_1++) {
    rtb_Assumingthatcalibwasdonelevel[i_1] = rtu_sensorCalibration_datin[i_1] +
      rtCP_Assumingthatcalibwasdonelevel_Bias[i_1];
  }

  /* End of Bias: '<S78>/Assuming that calib was done level!' */

  /* Gain: '<S76>/inverseIMU_gain' incorporates:
   *  Sum: '<S78>/Sum1'
   */
  stateEstimator_B.inverseIMU_gain[0] = (rtu_sensordata_datin->ddx -
    rtb_Assumingthatcalibwasdonelevel[0]) * 0.994075298F;
  stateEstimator_B.inverseIMU_gain[1] = (rtu_sensordata_datin->ddy -
    rtb_Assumingthatcalibwasdonelevel[1]) * 0.996184587F;
  stateEstimator_B.inverseIMU_gain[2] = (rtu_sensordata_datin->ddz -
    rtb_Assumingthatcalibwasdonelevel[2]) * 1.00549F;
  stateEstimator_B.inverseIMU_gain[3] = (rtu_sensordata_datin->p -
    rtb_Assumingthatcalibwasdonelevel[3]) * 1.00139189F;
  stateEstimator_B.inverseIMU_gain[4] = (rtu_sensordata_datin->q -
    rtb_Assumingthatcalibwasdonelevel[4]) * 0.993601203F;
  stateEstimator_B.inverseIMU_gain[5] = (rtu_sensordata_datin->r -
    rtb_Assumingthatcalibwasdonelevel[5]) * 1.00003F;

  /* DiscreteFilter: '<S75>/IIR_IMUgyro_r' */
  i_0 = 0;
  rtb_sincos_o1_idx_1 = stateEstimator_B.inverseIMU_gain[5];
  memIdx = 1;
  for (i = 0; i < 5; i++) {
    rtb_sincos_o1_idx_1 -= rtCP_IIR_IMUgyro_r_DenCoef[memIdx] *
      stateEstimator_DW.IIR_IMUgyro_r_states[i];
    memIdx++;
  }

  stateEstimator_DW.IIR_IMUgyro_r_tmp = rtb_sincos_o1_idx_1 / 1.0F;
  rtb_sincos_o1_idx_1 = 0.282124132F * stateEstimator_DW.IIR_IMUgyro_r_tmp;
  memIdx = 1;
  for (i = 0; i < 5; i++) {
    rtb_sincos_o1_idx_1 += rtCP_IIR_IMUgyro_r_NumCoef[memIdx] *
      stateEstimator_DW.IIR_IMUgyro_r_states[i];
    memIdx++;
  }

  /* SignalConversion generated from: '<S2>/Product' incorporates:
   *  DiscreteFilter: '<S75>/IIR_IMUgyro_r'
   */
  rtb_TrigonometricFunction_o1_idx_0 = stateEstimator_B.inverseIMU_gain[3];
  rtb_TrigonometricFunction_o2_idx_0 = stateEstimator_B.inverseIMU_gain[4];
  rtb_TrigonometricFunction_o1_idx_1 = rtb_sincos_o1_idx_1;

  /* Product: '<S10>/Divide' incorporates:
   *  Reshape: '<S11>/Reshape (9) to [3x3] column-major'
   */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate_4[i] = rtb_VectorConcatenate[i] /
      rtb_TrigonometricFunction_o2_idx_1;
  }

  /* End of Product: '<S10>/Divide' */
  for (i_1 = 0; i_1 < 3; i_1++) {
    /* Product: '<S2>/Product' */
    rtb_Product_n[i_1] = 0.0F;
    rtb_Product_n[i_1] += rtb_VectorConcatenate_4[i_1] *
      rtb_TrigonometricFunction_o1_idx_0;
    rtb_Product_n[i_1] += rtb_VectorConcatenate_4[i_1 + 3] *
      rtb_TrigonometricFunction_o2_idx_0;
    rtb_Product_n[i_1] += rtb_VectorConcatenate_4[i_1 + 6] *
      rtb_TrigonometricFunction_o1_idx_1;

    /* DiscreteFir: '<S75>/FIR_IMUaccel' */
    memIdx = i_1 * 5;
    rtb_sincos_o1_idx_1 = stateEstimator_B.inverseIMU_gain[i_0] * 0.0264077242F;
    i_0++;
    cff = 1;
    for (i = stateEstimator_DW.FIR_IMUaccel_circBuf; i < 5; i++) {
      rtb_sincos_o1_idx_1 += stateEstimator_DW.FIR_IMUaccel_states[memIdx + i] *
        rtCP_FIR_IMUaccel_Coefficients[cff];
      cff++;
    }

    for (i = 0; i < stateEstimator_DW.FIR_IMUaccel_circBuf; i++) {
      rtb_sincos_o1_idx_1 += stateEstimator_DW.FIR_IMUaccel_states[memIdx + i] *
        rtCP_FIR_IMUaccel_Coefficients[cff];
      cff++;
    }

    rtb_FIR_IMUaccel[i_1] = rtb_sincos_o1_idx_1;

    /* End of DiscreteFir: '<S75>/FIR_IMUaccel' */

    /* DataTypeConversion: '<S2>/Data Type Conversion2' */
    rtb_sincos_o1_idx_1 = rtb_FIR_IMUaccel[i_1];

    /* Math: '<S2>/Math Function' */
    if ((rtb_sincos_o1_idx_1 < 0.0F) && (2.0F > (real32_T)floor(2.0F))) {
      rtb_MathFunction[i_1] = -rt_powf_snf(-rtb_sincos_o1_idx_1, 2.0F);
    } else {
      rtb_MathFunction[i_1] = rt_powf_snf(rtb_sincos_o1_idx_1, 2.0F);
    }

    /* End of Math: '<S2>/Math Function' */
  }

  /* Sum: '<S2>/Sum' incorporates:
   *  Gain: '<S2>/Gain'
   *  Memory: '<S2>/Memory'
   *  SignalConversion generated from: '<S10>/Trigonometric Function'
   */
  rtb_TrigonometricFunction_o2_idx_1 = 0.005F * rtb_Product_n[0] +
    stateEstimator_DW.Memory_PreviousInput[0];

  /* Sqrt: '<S2>/Sqrt' incorporates:
   *  Sum: '<S2>/Sum of Elements'
   */
  rtb_Sqrt = (real32_T)sqrt((rtb_MathFunction[0] + rtb_MathFunction[1]) +
    rtb_MathFunction[2]);

  /* If: '<S2>/If' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Logic: '<S2>/Logical Operator'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   */
  if ((rtb_Sqrt > 9.79038F) && (rtb_Sqrt < 9.82962F)) {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Sum: '<S8>/Sum' incorporates:
     *  Gain: '<S2>/Gain'
     *  Gain: '<S8>/Gain'
     *  Gain: '<S8>/Gain1'
     *  Memory: '<S2>/Memory'
     *  Product: '<S8>/Divide'
     *  SignalConversion generated from: '<S10>/Trigonometric Function'
     *  Sum: '<S2>/Sum'
     *  Trigonometry: '<S8>/Trigonometric Function'
     */
    stateEstimator_B.Merge[1] = (0.005F * rtb_Product_n[2] +
      stateEstimator_DW.Memory_PreviousInput[2]) * 0.999F + (real32_T)atan
      (rtb_FIR_IMUaccel[1] / rtb_FIR_IMUaccel[2]) * 0.001F;

    /* Gain: '<S8>/Gain2' */
    rtb_sincos_o1_idx_1 = 0.101936802F * rtb_FIR_IMUaccel[0];

    /* Trigonometry: '<S8>/Trigonometric Function1' */
    if (rtb_sincos_o1_idx_1 > 1.0F) {
      rtb_sincos_o1_idx_1 = 1.0F;
    } else if (rtb_sincos_o1_idx_1 < -1.0F) {
      rtb_sincos_o1_idx_1 = -1.0F;
    }

    /* Sum: '<S8>/Sum1' incorporates:
     *  Gain: '<S2>/Gain'
     *  Gain: '<S8>/Gain3'
     *  Gain: '<S8>/Gain4'
     *  Memory: '<S2>/Memory'
     *  SignalConversion generated from: '<S10>/Trigonometric Function'
     *  Sum: '<S2>/Sum'
     *  Trigonometry: '<S8>/Trigonometric Function1'
     */
    stateEstimator_B.Merge[0] = (0.005F * rtb_Product_n[1] +
      stateEstimator_DW.Memory_PreviousInput[1]) * 0.999F + 0.001F * (real32_T)
      asin(rtb_sincos_o1_idx_1);

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Gain: '<S2>/Gain'
     *  Inport: '<S9>/prin'
     *  Memory: '<S2>/Memory'
     *  SignalConversion generated from: '<S10>/Trigonometric Function'
     *  Sum: '<S2>/Sum'
     */
    stateEstimator_B.Merge[0] = 0.005F * rtb_Product_n[1] +
      stateEstimator_DW.Memory_PreviousInput[1];
    stateEstimator_B.Merge[1] = 0.005F * rtb_Product_n[2] +
      stateEstimator_DW.Memory_PreviousInput[2];

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem2' */
  }

  /* End of If: '<S2>/If' */

  /* Trigonometry: '<S71>/sincos' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   *  Trigonometry: '<S13>/sincos'
   *  Trigonometry: '<S73>/sincos'
   */
  rtb_TrigonometricFunction_o1_idx_0 = (real32_T)sin
    (rtb_TrigonometricFunction_o2_idx_1);
  rtb_TrigonometricFunction_o2_idx_0 = (real32_T)cos
    (rtb_TrigonometricFunction_o2_idx_1);
  rtb_sincos_o1_idx_1 = (real32_T)sin(stateEstimator_B.Merge[0]);
  rtb_sincos_o2_idx_1_tmp_tmp = (real32_T)cos(stateEstimator_B.Merge[0]);
  rtb_sincos_o1_idx_2_tmp_tmp = (real32_T)sin(stateEstimator_B.Merge[1]);
  rtb_sincos_o2_idx_2_tmp_tmp = (real32_T)cos(stateEstimator_B.Merge[1]);

  /* Fcn: '<S71>/Fcn11' incorporates:
   *  Fcn: '<S13>/Fcn11'
   *  Trigonometry: '<S71>/sincos'
   */
  rtb_VectorConcatenate_j_tmp_0 = rtb_TrigonometricFunction_o2_idx_0 *
    rtb_sincos_o2_idx_1_tmp_tmp;
  rtb_VectorConcatenate_kk[0] = rtb_VectorConcatenate_j_tmp_0;

  /* Fcn: '<S71>/Fcn21' incorporates:
   *  Fcn: '<S13>/Fcn21'
   *  Fcn: '<S71>/Fcn22'
   *  Trigonometry: '<S71>/sincos'
   */
  rtb_gainaccinput_idx_1 = rtb_sincos_o1_idx_1 * rtb_sincos_o1_idx_2_tmp_tmp;
  rtb_VectorConcatenate_j_tmp_1 = rtb_TrigonometricFunction_o1_idx_0 *
    rtb_sincos_o2_idx_2_tmp_tmp;
  rtb_VectorConcatenate_kk[1] = rtb_gainaccinput_idx_1 *
    rtb_TrigonometricFunction_o2_idx_0 - rtb_VectorConcatenate_j_tmp_1;

  /* Fcn: '<S71>/Fcn31' incorporates:
   *  Fcn: '<S13>/Fcn31'
   *  Fcn: '<S71>/Fcn32'
   *  Trigonometry: '<S71>/sincos'
   */
  rtb_VectorConcatenate_j_tmp = rtb_sincos_o1_idx_1 *
    rtb_sincos_o2_idx_2_tmp_tmp;
  rtb_VectorConcatenate_j_tmp_2 = rtb_TrigonometricFunction_o1_idx_0 *
    rtb_sincos_o1_idx_2_tmp_tmp;
  rtb_VectorConcatenate_kk[2] = rtb_VectorConcatenate_j_tmp *
    rtb_TrigonometricFunction_o2_idx_0 + rtb_VectorConcatenate_j_tmp_2;

  /* Fcn: '<S71>/Fcn12' incorporates:
   *  Fcn: '<S13>/Fcn12'
   *  Trigonometry: '<S71>/sincos'
   */
  rtb_VectorConcatenate_j_tmp_3 = rtb_TrigonometricFunction_o1_idx_0 *
    rtb_sincos_o2_idx_1_tmp_tmp;
  rtb_VectorConcatenate_kk[3] = rtb_VectorConcatenate_j_tmp_3;

  /* Fcn: '<S71>/Fcn22' incorporates:
   *  Fcn: '<S13>/Fcn22'
   *  Trigonometry: '<S71>/sincos'
   */
  rtb_VectorConcatenate_j_tmp_4 = rtb_TrigonometricFunction_o2_idx_0 *
    rtb_sincos_o2_idx_2_tmp_tmp;
  rtb_VectorConcatenate_kk[4] = rtb_gainaccinput_idx_1 *
    rtb_TrigonometricFunction_o1_idx_0 + rtb_VectorConcatenate_j_tmp_4;

  /* Fcn: '<S71>/Fcn32' incorporates:
   *  Fcn: '<S13>/Fcn32'
   *  Trigonometry: '<S71>/sincos'
   */
  rtb_VectorConcatenate_j_tmp_5 = rtb_TrigonometricFunction_o2_idx_0 *
    rtb_sincos_o1_idx_2_tmp_tmp;
  rtb_VectorConcatenate_kk[5] = rtb_VectorConcatenate_j_tmp *
    rtb_TrigonometricFunction_o1_idx_0 - rtb_VectorConcatenate_j_tmp_5;

  /* Fcn: '<S71>/Fcn13' */
  rtb_VectorConcatenate_kk[6] = -rtb_sincos_o1_idx_1;

  /* Fcn: '<S71>/Fcn23' incorporates:
   *  Fcn: '<S13>/Fcn23'
   *  Trigonometry: '<S71>/sincos'
   */
  rtb_VectorConcatenate_j_tmp = rtb_sincos_o2_idx_1_tmp_tmp *
    rtb_sincos_o1_idx_2_tmp_tmp;
  rtb_VectorConcatenate_kk[7] = rtb_VectorConcatenate_j_tmp;

  /* Fcn: '<S71>/Fcn33' incorporates:
   *  Fcn: '<S13>/Fcn33'
   *  Trigonometry: '<S71>/sincos'
   */
  rtb_sincos_o2_idx_1_tmp_tmp *= rtb_sincos_o2_idx_2_tmp_tmp;
  rtb_VectorConcatenate_kk[8] = rtb_sincos_o2_idx_1_tmp_tmp;

  /* Sum: '<S70>/Add' incorporates:
   *  Constant: '<S70>/gravity'
   *  Product: '<S70>/Product1'
   *  Reshape: '<S72>/Reshape (9) to [3x3] column-major'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_FIR_IMUaccel_0[i_0] = rtb_FIR_IMUaccel[i_0] -
      ((rtb_VectorConcatenate_kk[i_0 + 3] * 0.0 + rtb_VectorConcatenate_kk[i_0] *
        0.0) + rtb_VectorConcatenate_kk[i_0 + 6] * (-9.81));
  }

  /* End of Sum: '<S70>/Add' */

  /* Gain: '<S70>/gainaccinput' */
  rtb_sincos_o1_idx_1 = (real32_T)(0.2 * rtb_FIR_IMUaccel_0[0]);
  rtb_gainaccinput_idx_1 = (real32_T)(0.2 * rtb_FIR_IMUaccel_0[1]);

  /* Trigonometry: '<S13>/sincos' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   */
  rtb_VectorConcatenate_j_tmp_tmp = (real32_T)sin(stateEstimator_B.Merge[0]);

  /* Fcn: '<S13>/Fcn11' */
  rtb_VectorConcatenate_a[0] = rtb_VectorConcatenate_j_tmp_0;

  /* Fcn: '<S13>/Fcn21' incorporates:
   *  Fcn: '<S13>/Fcn22'
   *  Trigonometry: '<S13>/sincos'
   *  Trigonometry: '<S71>/sincos'
   */
  rtb_sincos_o1_idx_2_tmp_tmp *= rtb_VectorConcatenate_j_tmp_tmp;
  rtb_VectorConcatenate_a[1] = rtb_sincos_o1_idx_2_tmp_tmp *
    rtb_TrigonometricFunction_o2_idx_0 - rtb_VectorConcatenate_j_tmp_1;

  /* Fcn: '<S13>/Fcn31' incorporates:
   *  Fcn: '<S13>/Fcn32'
   *  Trigonometry: '<S13>/sincos'
   *  Trigonometry: '<S71>/sincos'
   */
  rtb_sincos_o2_idx_2_tmp_tmp *= rtb_VectorConcatenate_j_tmp_tmp;
  rtb_VectorConcatenate_a[2] = rtb_sincos_o2_idx_2_tmp_tmp *
    rtb_TrigonometricFunction_o2_idx_0 + rtb_VectorConcatenate_j_tmp_2;

  /* Fcn: '<S13>/Fcn12' */
  rtb_VectorConcatenate_a[3] = rtb_VectorConcatenate_j_tmp_3;

  /* Fcn: '<S13>/Fcn22' */
  rtb_VectorConcatenate_a[4] = rtb_sincos_o1_idx_2_tmp_tmp *
    rtb_TrigonometricFunction_o1_idx_0 + rtb_VectorConcatenate_j_tmp_4;

  /* Fcn: '<S13>/Fcn32' */
  rtb_VectorConcatenate_a[5] = rtb_sincos_o2_idx_2_tmp_tmp *
    rtb_TrigonometricFunction_o1_idx_0 - rtb_VectorConcatenate_j_tmp_5;

  /* Fcn: '<S13>/Fcn13' incorporates:
   *  Trigonometry: '<S13>/sincos'
   */
  rtb_VectorConcatenate_a[6] = -rtb_VectorConcatenate_j_tmp_tmp;

  /* Fcn: '<S13>/Fcn23' */
  rtb_VectorConcatenate_a[7] = rtb_VectorConcatenate_j_tmp;

  /* Fcn: '<S13>/Fcn33' */
  rtb_VectorConcatenate_a[8] = rtb_sincos_o2_idx_1_tmp_tmp;

  /* SignalConversion generated from: '<S3>/Product1' incorporates:
   *  Delay: '<S1>/Delay1'
   */
  tmp = stateEstimator_DW.Delay1_DSTATE[0];
  tmp_0 = stateEstimator_DW.Delay1_DSTATE[1];

  /* Product: '<S3>/Product1' incorporates:
   *  Reshape: '<S12>/Reshapexhat'
   *  Reshape: '<S67>/Reshape (9) to [3x3] column-major'
   *  SignalConversion generated from: '<S3>/Product1'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_Product1_d[i_0] = rtb_VectorConcatenate_a[i_0 + 6] * rtb_Add_idx_1 +
      (rtb_VectorConcatenate_a[i_0 + 3] * tmp_0 + rtb_VectorConcatenate_a[i_0] *
       tmp);
  }

  /* End of Product: '<S3>/Product1' */

  /* BusCreator generated from: '<Root>/states_estimout' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S69>/SimplyIntegrateVelocity'
   *  SignalConversion generated from: '<S2>/Product'
   */
  rty_states_estimout->X = stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[0];
  rty_states_estimout->Y = stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[1];
  rty_states_estimout->yaw = rtb_TrigonometricFunction_o2_idx_1;
  rty_states_estimout->pitch = stateEstimator_B.Merge[0];
  rty_states_estimout->roll = stateEstimator_B.Merge[1];
  rty_states_estimout->dx = rtb_sincos_o1_idx_1;
  rty_states_estimout->dy = rtb_gainaccinput_idx_1;
  rty_states_estimout->dz = (real32_T)rtb_Product1_d[2];
  rty_states_estimout->p = stateEstimator_B.inverseIMU_gain[3];
  rty_states_estimout->q = stateEstimator_B.inverseIMU_gain[4];
  rty_states_estimout->r = rtb_TrigonometricFunction_o1_idx_1;

  /* MATLAB Function: '<S62>/SqrtUsedFcn' incorporates:
   *  Constant: '<S62>/isSqrtUsed'
   *  DataTypeConversion: '<S59>/Conversion'
   */
  /* MATLAB Function 'Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn': '<S63>:1' */
  /* '<S63>:1:4' if isSqrtUsed */
  if (false) {
    /* '<S63>:1:5' P = u*u.'; */
    for (i_0 = 0; i_0 < 2; i_0++) {
      rtb_P[i_0] = 0.0;
      rtb_P[i_0] += stateEstimator_ConstB.Conversion_c[i_0] *
        stateEstimator_ConstB.Conversion_c[0];
      rtb_Add_idx_1 = stateEstimator_ConstB.Conversion_c[i_0 + 2];
      rtb_P[i_0] += rtb_Add_idx_1 * stateEstimator_ConstB.Conversion_c[2];
      rtb_P[i_0 + 2] = 0.0;
      rtb_P[i_0 + 2] += stateEstimator_ConstB.Conversion_c[i_0] *
        stateEstimator_ConstB.Conversion_c[1];
      rtb_P[i_0 + 2] += rtb_Add_idx_1 * stateEstimator_ConstB.Conversion_c[3];
    }
  } else {
    /* '<S63>:1:6' else */
    /* '<S63>:1:7' P = u; */
    rtb_P[0] = stateEstimator_ConstB.Conversion_c[0];
    rtb_P[1] = stateEstimator_ConstB.Conversion_c[1];
    rtb_P[2] = stateEstimator_ConstB.Conversion_c[2];
    rtb_P[3] = stateEstimator_ConstB.Conversion_c[3];
  }

  /* End of MATLAB Function: '<S62>/SqrtUsedFcn' */
  for (i_0 = 0; i_0 < 3; i_0++) {
    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<S3>/gravity'
     *  Math: '<S3>/Math Function'
     *  Product: '<S3>/Product'
     *  Reshape: '<S67>/Reshape (9) to [3x3] column-major'
     */
    stateEstimator_B.Sum[i_0] = ((rtb_VectorConcatenate_a[3 * i_0 + 1] *
      rtb_FIR_IMUaccel[1] + rtb_VectorConcatenate_a[3 * i_0] * rtb_FIR_IMUaccel
      [0]) + rtb_VectorConcatenate_a[3 * i_0 + 2] * rtb_FIR_IMUaccel[2]) +
      rtCP_gravity_Value[i_0];
  }

  /* Outputs for Enabled SubSystem: '<S34>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S64>/Enable'
   */
  /* Constant: '<S12>/Enable' */
  if (true) {
    stateEstimator_DW.MeasurementUpdate_MODE = true;

    /* Sum: '<S64>/Sum' incorporates:
     *  Constant: '<S12>/C'
     *  Constant: '<S12>/D'
     *  Delay: '<S12>/MemoryX'
     *  Product: '<S64>/C[k]*xhat[k|k-1]'
     *  Product: '<S64>/D[k]*u[k]'
     *  Reshape: '<S12>/Reshapeu'
     *  Reshape: '<S12>/Reshapey'
     *  Sum: '<S64>/Add1'
     */
    rtb_Sum = stateEstimator_B.altfrompress - ((1.0 *
      stateEstimator_DW.MemoryX_DSTATE[0] + 0.0 *
      stateEstimator_DW.MemoryX_DSTATE[1]) + 0.0 * stateEstimator_B.Sum[2]);

    /* Product: '<S64>/Product3' incorporates:
     *  DataTypeConversion: '<S56>/Conversion'
     */
    stateEstimator_B.Product3[0] = stateEstimator_ConstB.Conversion[0] * rtb_Sum;
    stateEstimator_B.Product3[1] = stateEstimator_ConstB.Conversion[1] * rtb_Sum;
  } else if (stateEstimator_DW.MeasurementUpdate_MODE) {
    /* Disable for Product: '<S64>/Product3' incorporates:
     *  Outport: '<S64>/L*(y[k]-yhat[k|k-1])'
     */
    stateEstimator_B.Product3[0] = 0.0;
    stateEstimator_B.Product3[1] = 0.0;
    stateEstimator_DW.MeasurementUpdate_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S34>/MeasurementUpdate' */

  /* Trigonometry: '<S73>/sincos' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   */
  rtb_TrigonometricFunction_o1_idx_1 = (real32_T)sin(stateEstimator_B.Merge[0]);
  rtb_VectorConcatenate_j_tmp_2 = (real32_T)cos(stateEstimator_B.Merge[0]);
  rtb_VectorConcatenate_j_tmp_3 = (real32_T)sin(stateEstimator_B.Merge[1]);
  rtb_VectorConcatenate_j_tmp_4 = (real32_T)cos(stateEstimator_B.Merge[1]);

  /* Fcn: '<S73>/Fcn11' incorporates:
   *  Trigonometry: '<S73>/sincos'
   */
  rtb_VectorConcatenate_e[0] = rtb_TrigonometricFunction_o2_idx_0 *
    rtb_VectorConcatenate_j_tmp_2;

  /* Fcn: '<S73>/Fcn21' incorporates:
   *  Fcn: '<S73>/Fcn22'
   *  Trigonometry: '<S73>/sincos'
   */
  rtb_VectorConcatenate_j_tmp = rtb_TrigonometricFunction_o1_idx_1 *
    rtb_VectorConcatenate_j_tmp_3;
  rtb_VectorConcatenate_e[1] = rtb_VectorConcatenate_j_tmp *
    rtb_TrigonometricFunction_o2_idx_0 - rtb_TrigonometricFunction_o1_idx_0 *
    rtb_VectorConcatenate_j_tmp_4;

  /* Fcn: '<S73>/Fcn31' incorporates:
   *  Fcn: '<S73>/Fcn32'
   *  Trigonometry: '<S73>/sincos'
   */
  rtb_sincos_o1_idx_2_tmp_tmp = rtb_TrigonometricFunction_o1_idx_1 *
    rtb_VectorConcatenate_j_tmp_4;
  rtb_VectorConcatenate_e[2] = rtb_sincos_o1_idx_2_tmp_tmp *
    rtb_TrigonometricFunction_o2_idx_0 + rtb_TrigonometricFunction_o1_idx_0 *
    rtb_VectorConcatenate_j_tmp_3;

  /* Fcn: '<S73>/Fcn12' incorporates:
   *  Trigonometry: '<S73>/sincos'
   */
  rtb_VectorConcatenate_e[3] = rtb_TrigonometricFunction_o1_idx_0 *
    rtb_VectorConcatenate_j_tmp_2;

  /* Fcn: '<S73>/Fcn22' incorporates:
   *  Trigonometry: '<S73>/sincos'
   */
  rtb_VectorConcatenate_e[4] = rtb_VectorConcatenate_j_tmp *
    rtb_TrigonometricFunction_o1_idx_0 + rtb_TrigonometricFunction_o2_idx_0 *
    rtb_VectorConcatenate_j_tmp_4;

  /* Fcn: '<S73>/Fcn32' incorporates:
   *  Trigonometry: '<S73>/sincos'
   */
  rtb_VectorConcatenate_e[5] = rtb_sincos_o1_idx_2_tmp_tmp *
    rtb_TrigonometricFunction_o1_idx_0 - rtb_TrigonometricFunction_o2_idx_0 *
    rtb_VectorConcatenate_j_tmp_3;

  /* Fcn: '<S73>/Fcn13' incorporates:
   *  Trigonometry: '<S73>/sincos'
   */
  rtb_VectorConcatenate_e[6] = -rtb_TrigonometricFunction_o1_idx_1;

  /* Fcn: '<S73>/Fcn23' incorporates:
   *  Trigonometry: '<S73>/sincos'
   */
  rtb_VectorConcatenate_e[7] = rtb_VectorConcatenate_j_tmp_2 *
    rtb_VectorConcatenate_j_tmp_3;

  /* Fcn: '<S73>/Fcn33' incorporates:
   *  Trigonometry: '<S73>/sincos'
   */
  rtb_VectorConcatenate_e[8] = rtb_VectorConcatenate_j_tmp_2 *
    rtb_VectorConcatenate_j_tmp_4;

  /* SignalConversion generated from: '<S69>/Product' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  rtb_TrigonometricFunction_o1_idx_0 = (real32_T)rtb_Product1_d[2];

  /* Product: '<S69>/Product' incorporates:
   *  Math: '<S69>/Math Function'
   *  Reshape: '<S74>/Reshape (9) to [3x3] column-major'
   *  SignalConversion generated from: '<S69>/Product'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_VectorConcatenate_e_0[i_0] = rtb_VectorConcatenate_e[3 * i_0 + 2] *
      rtb_TrigonometricFunction_o1_idx_0 + (rtb_VectorConcatenate_e[3 * i_0 + 1]
      * rtb_gainaccinput_idx_1 + rtb_VectorConcatenate_e[3 * i_0] *
      rtb_sincos_o1_idx_1);
  }

  /* End of Product: '<S69>/Product' */

  /* Update for DiscreteIntegrator: '<S69>/SimplyIntegrateVelocity' */
  stateEstimator_DW.SimplyIntegrateVelocity_PrevResetState = (int8_T)
    *rtu_controlModePosVSOrient_flagin;

  /* Update for Delay: '<S3>/Delay2' incorporates:
   *  Reshape: '<S12>/Reshapexhat'
   */
  stateEstimator_DW.Delay2_DSTATE = rtb_Add_idx_0;

  /* Update for Delay: '<S12>/MemoryX' */
  stateEstimator_DW.icLoad = false;

  /* Update for DiscreteIntegrator: '<S69>/SimplyIntegrateVelocity' */
  stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[0] += 0.005F *
    rtb_VectorConcatenate_e_0[0];

  /* Product: '<S34>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S12>/A'
   *  Delay: '<S12>/MemoryX'
   */
  tmp = 1.0 * stateEstimator_DW.MemoryX_DSTATE[0] +
    stateEstimator_DW.MemoryX_DSTATE[1] * 0.005;

  /* Update for DiscreteIntegrator: '<S69>/SimplyIntegrateVelocity' */
  stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[1] += 0.005F *
    rtb_VectorConcatenate_e_0[1];

  /* Product: '<S34>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S12>/A'
   *  Delay: '<S12>/MemoryX'
   */
  tmp_0 = stateEstimator_DW.MemoryX_DSTATE[0] * 0.0 +
    stateEstimator_DW.MemoryX_DSTATE[1] * 1.0;

  /* Update for Delay: '<S12>/MemoryX' incorporates:
   *  Constant: '<S12>/B'
   *  Product: '<S34>/B[k]*u[k]'
   *  Product: '<S64>/Product3'
   *  Reshape: '<S12>/Reshapeu'
   *  Sum: '<S34>/Add'
   */
  stateEstimator_DW.MemoryX_DSTATE[0] = (0.0 * stateEstimator_B.Sum[2] + tmp) +
    stateEstimator_B.Product3[0];
  stateEstimator_DW.MemoryX_DSTATE[1] = (0.005 * stateEstimator_B.Sum[2] + tmp_0)
    + stateEstimator_B.Product3[1];

  /* Update for Memory: '<S2>/Memory' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   */
  stateEstimator_DW.Memory_PreviousInput[0] = rtb_TrigonometricFunction_o2_idx_1;
  stateEstimator_DW.Memory_PreviousInput[1] = stateEstimator_B.Merge[0];
  stateEstimator_DW.Memory_PreviousInput[2] = stateEstimator_B.Merge[1];

  /* Update for DiscreteFilter: '<S75>/IIR_IMUgyro_r' */
  stateEstimator_DW.IIR_IMUgyro_r_states[4] =
    stateEstimator_DW.IIR_IMUgyro_r_states[3];
  stateEstimator_DW.IIR_IMUgyro_r_states[3] =
    stateEstimator_DW.IIR_IMUgyro_r_states[2];
  stateEstimator_DW.IIR_IMUgyro_r_states[2] =
    stateEstimator_DW.IIR_IMUgyro_r_states[1];
  stateEstimator_DW.IIR_IMUgyro_r_states[1] =
    stateEstimator_DW.IIR_IMUgyro_r_states[0];
  stateEstimator_DW.IIR_IMUgyro_r_states[0] =
    stateEstimator_DW.IIR_IMUgyro_r_tmp;

  /* Update for DiscreteFir: '<S75>/FIR_IMUaccel' */
  /* Update circular buffer index */
  stateEstimator_DW.FIR_IMUaccel_circBuf--;
  if (stateEstimator_DW.FIR_IMUaccel_circBuf < 0) {
    stateEstimator_DW.FIR_IMUaccel_circBuf = 4;
  }

  /* Update circular buffer */
  stateEstimator_DW.FIR_IMUaccel_states[stateEstimator_DW.FIR_IMUaccel_circBuf] =
    stateEstimator_B.inverseIMU_gain[0];
  stateEstimator_DW.FIR_IMUaccel_states[stateEstimator_DW.FIR_IMUaccel_circBuf +
    5] = stateEstimator_B.inverseIMU_gain[1];
  stateEstimator_DW.FIR_IMUaccel_states[stateEstimator_DW.FIR_IMUaccel_circBuf +
    10] = stateEstimator_B.inverseIMU_gain[2];

  /* End of Update for DiscreteFir: '<S75>/FIR_IMUaccel' */

  /* Update for Delay: '<S1>/Delay1' */
  stateEstimator_DW.Delay1_DSTATE[0] = rtb_sincos_o1_idx_1;
  stateEstimator_DW.Delay1_DSTATE[1] = rtb_gainaccinput_idx_1;
}

/* Model initialize function */
void stateEstimator_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_stateEstimator_T *const stateEstimator_M =
    &(stateEstimator_MdlrefDW.rtm);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(stateEstimator_M, rt_errorStatus);

  /* block I/O */
  (void) memset(((void *) &stateEstimator_B), 0,
                sizeof(B_stateEstimator_c_T));

  /* states (dwork) */
  (void) memset((void *)&stateEstimator_DW, 0,
                sizeof(DW_stateEstimator_f_T));
}
