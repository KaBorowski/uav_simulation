/*
 * Code generation for system model 'stateEstimator'
 * For more details, see corresponding source file stateEstimator.c
 *
 */

#ifndef RTW_HEADER_stateEstimator_h_
#define RTW_HEADER_stateEstimator_h_
#include <math.h>
#include <string.h>
#ifndef stateEstimator_COMMON_INCLUDES_
#define stateEstimator_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* stateEstimator_COMMON_INCLUDES_ */

#include "stateEstimator_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Block signals for model 'stateEstimator' */
#ifndef stateEstimator_MDLREF_HIDE_CHILD_

typedef struct {
  real_T altfrompress;                 /* '<S3>/prsToAltGain' */
  real_T Sum[3];                       /* '<S3>/Sum' */
  real_T Product2[2];                  /* '<S66>/Product2' */
  real_T Product3[2];                  /* '<S64>/Product3' */
  real32_T inverseIMU_gain[6];         /* '<S76>/inverseIMU_gain' */
  real32_T Merge[2];                   /* '<S2>/Merge' */
  boolean_T Compare;                   /* '<S14>/Compare' */
} B_stateEstimator_c_T;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for model 'stateEstimator' */
#ifndef stateEstimator_MDLREF_HIDE_CHILD_

typedef struct {
  real_T Delay2_DSTATE;                /* '<S3>/Delay2' */
  real_T MemoryX_DSTATE[2];            /* '<S12>/MemoryX' */
  real32_T SimplyIntegrateVelocity_DSTATE[2];/* '<S69>/SimplyIntegrateVelocity' */
  real32_T IIR_IMUgyro_r_states[5];    /* '<S75>/IIR_IMUgyro_r' */
  real32_T FIR_IMUaccel_states[15];    /* '<S75>/FIR_IMUaccel' */
  real32_T Delay1_DSTATE[2];           /* '<S1>/Delay1' */
  int32_T FIR_IMUaccel_circBuf;        /* '<S75>/FIR_IMUaccel' */
  real32_T Memory_PreviousInput[3];    /* '<S2>/Memory' */
  real32_T IIR_IMUgyro_r_tmp;          /* '<S75>/IIR_IMUgyro_r' */
  int8_T SimplyIntegrateVelocity_PrevResetState;/* '<S69>/SimplyIntegrateVelocity' */
  boolean_T icLoad;                    /* '<S12>/MemoryX' */
  boolean_T EnabledSubsystem_MODE;     /* '<S40>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S34>/MeasurementUpdate' */
} DW_stateEstimator_f_T;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for model 'stateEstimator' */
#ifndef stateEstimator_MDLREF_HIDE_CHILD_

typedef struct {
  const real_T Conversion[2];          /* '<S56>/Conversion' */
  const real_T Conversion_i[2];        /* '<S57>/Conversion' */
  const real_T Conversion_k;           /* '<S58>/Conversion' */
  const real_T Conversion_c[4];        /* '<S59>/Conversion' */
  const real_T ReshapeX0[2];           /* '<S12>/ReshapeX0' */
  const real32_T Conversion_b[4];      /* '<S26>/Conversion' */
} ConstB_stateEstimator_h_T;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

#ifndef stateEstimator_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_stateEstimator_T {
  const char_T **errorStatus;
};

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

#ifndef stateEstimator_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_stateEstimator_T rtm;
} MdlrefDW_stateEstimator_T;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

extern void stateEstimator_Init(void);
extern void stateEstimator_Reset(void);
extern void stateEstimator_Disable(void);
extern void stateEstimator(const boolean_T *rtu_controlModePosVSOrient_flagin,
  const sensordata_t *rtu_sensordata_datin, const real32_T
  rtu_sensorCalibration_datin[8], statesEstim_t *rty_states_estimout);

/* Model reference registration function */
extern void stateEstimator_initialize(const char_T **rt_errorStatus);

#ifndef stateEstimator_MDLREF_HIDE_CHILD_

extern MdlrefDW_stateEstimator_T stateEstimator_MdlrefDW;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

#ifndef stateEstimator_MDLREF_HIDE_CHILD_

/* Block signals (default storage) */
extern B_stateEstimator_c_T stateEstimator_B;

/* Block states (default storage) */
extern DW_stateEstimator_f_T stateEstimator_DW;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'stateEstimator'
 * '<S1>'   : 'stateEstimator/State Estimator'
 * '<S2>'   : 'stateEstimator/State Estimator/Complementary Filter'
 * '<S3>'   : 'stateEstimator/State Estimator/EstimatorAltitude'
 * '<S4>'   : 'stateEstimator/State Estimator/EstimatorXYPosition'
 * '<S5>'   : 'stateEstimator/State Estimator/SensorPreprocessing'
 * '<S6>'   : 'stateEstimator/State Estimator/Complementary Filter/Compare To Constant'
 * '<S7>'   : 'stateEstimator/State Estimator/Complementary Filter/Compare To Constant1'
 * '<S8>'   : 'stateEstimator/State Estimator/Complementary Filter/If Action Subsystem'
 * '<S9>'   : 'stateEstimator/State Estimator/Complementary Filter/If Action Subsystem2'
 * '<S10>'  : 'stateEstimator/State Estimator/Complementary Filter/Wbe'
 * '<S11>'  : 'stateEstimator/State Estimator/Complementary Filter/Wbe/Create 3x3 Matrix'
 * '<S12>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude'
 * '<S13>'  : 'stateEstimator/State Estimator/EstimatorAltitude/Rotation Angles to Direction Cosine Matrix'
 * '<S14>'  : 'stateEstimator/State Estimator/EstimatorAltitude/outlierBelowFloor'
 * '<S15>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL'
 * '<S16>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculateYhat'
 * '<S17>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CovarianceOutputConfigurator'
 * '<S18>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionA'
 * '<S19>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionB'
 * '<S20>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionC'
 * '<S21>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionD'
 * '<S22>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionEnable'
 * '<S23>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionG'
 * '<S24>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionH'
 * '<S25>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionN'
 * '<S26>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionP'
 * '<S27>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionP0'
 * '<S28>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionQ'
 * '<S29>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionR'
 * '<S30>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionX'
 * '<S31>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionX0'
 * '<S32>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionu'
 * '<S33>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/MemoryP'
 * '<S34>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/Observer'
 * '<S35>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/ReducedQRN'
 * '<S36>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/Reshapeyhat'
 * '<S37>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/ScalarExpansionP0'
 * '<S38>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/ScalarExpansionQ'
 * '<S39>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/ScalarExpansionR'
 * '<S40>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/UseCurrentEstimator'
 * '<S41>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkA'
 * '<S42>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkB'
 * '<S43>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkC'
 * '<S44>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkD'
 * '<S45>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkEnable'
 * '<S46>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkG'
 * '<S47>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkH'
 * '<S48>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkN'
 * '<S49>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkP0'
 * '<S50>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkQ'
 * '<S51>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkR'
 * '<S52>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkReset'
 * '<S53>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkX0'
 * '<S54>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checku'
 * '<S55>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checky'
 * '<S56>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL/DataTypeConversionL'
 * '<S57>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL/DataTypeConversionM'
 * '<S58>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL/DataTypeConversionP'
 * '<S59>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL/DataTypeConversionZ'
 * '<S60>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL/Ground'
 * '<S61>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculateYhat/Ground'
 * '<S62>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CovarianceOutputConfigurator/decideOutput'
 * '<S63>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S64>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/Observer/MeasurementUpdate'
 * '<S65>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/ReducedQRN/Ground'
 * '<S66>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/UseCurrentEstimator/Enabled Subsystem'
 * '<S67>'  : 'stateEstimator/State Estimator/EstimatorAltitude/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S68>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity'
 * '<S69>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition'
 * '<S70>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling'
 * '<S71>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling/Rotation Angles to Direction Cosine Matrix'
 * '<S72>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S73>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/Rotation Angles to Direction Cosine Matrix'
 * '<S74>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S75>'  : 'stateEstimator/State Estimator/SensorPreprocessing/Low Pass Filter'
 * '<S76>'  : 'stateEstimator/State Estimator/SensorPreprocessing/Rotate IMU into body frame'
 * '<S77>'  : 'stateEstimator/State Estimator/SensorPreprocessing/Subtract From Ultrasound'
 * '<S78>'  : 'stateEstimator/State Estimator/SensorPreprocessing/Subtract Sensors Bias'
 */
#endif                                 /* RTW_HEADER_stateEstimator_h_ */
