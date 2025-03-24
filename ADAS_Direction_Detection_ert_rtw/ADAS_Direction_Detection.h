/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: ADAS_Direction_Detection.h
 *
 * Code generated for Simulink model 'ADAS_Direction_Detection'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Mar 25 01:18:01 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef ADAS_Direction_Detection_h_
#define ADAS_Direction_Detection_h_
#ifndef ADAS_Direction_Detection_COMMON_INCLUDES_
#define ADAS_Direction_Detection_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                           /* ADAS_Direction_Detection_COMMON_INCLUDES_ */

/* External inputs (root inport signals with default storage) */
typedef struct {
  int16_T Steering_Input_YawRate;      /* '<Root>/Steering_Input_YawRate' */
  boolean_T RoadSign_Input_Camera;     /* '<Root>/RoadSign_Input_Camera' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T Direction_Indecator_Output;/* '<Root>/Direction_Indecator_Output' */
} ExtY;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void ADAS_Direction_Detection_initialize(void);
extern void ADAS_Direction_Detection_step(void);

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
 * '<Root>' : 'ADAS_Direction_Detection'
 * '<S1>'   : 'ADAS_Direction_Detection/ADAS'
 * '<S2>'   : 'ADAS_Direction_Detection/ADAS/If Action Subsystem'
 * '<S3>'   : 'ADAS_Direction_Detection/ADAS/If Action Subsystem1'
 * '<S4>'   : 'ADAS_Direction_Detection/ADAS/If Action Subsystem2'
 */
#endif                                 /* ADAS_Direction_Detection_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
