/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: ADAS_Direction_Detection.c
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

#include "ADAS_Direction_Detection.h"
#include "rtwtypes.h"

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;
static void IfActionSubsystem(boolean_T *rty_Out1);

/*
 * Output and update for action system:
 *    '<S1>/If Action Subsystem'
 *    '<S1>/If Action Subsystem1'
 */
static void IfActionSubsystem(boolean_T *rty_Out1)
{
  /* SignalConversion generated from: '<S2>/Out1' incorporates:
   *  Constant: '<S2>/Constant'
   */
  *rty_Out1 = true;
}

/* Model step function */
void ADAS_Direction_Detection_step(void)
{
  int16_T rtb_Turn_Direction_Status;
  int16_T tmp;
  int16_T tmp_0;

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/SteeringAngle_Straight'
   *  Constant: '<S1>/TurnLimit_Right'
   *  Inport: '<Root>/Steering_Input_YawRate'
   *  RelationalOperator: '<S1>/Relational Operator'
   */
  if (rtU.Steering_Input_YawRate >= 30) {
    tmp = 30;
  } else {
    tmp = 0;
  }

  /* Switch: '<S1>/Switch1' incorporates:
   *  Constant: '<S1>/SteeringAngle_Straight'
   *  Constant: '<S1>/TurnLimit_Left'
   *  Inport: '<Root>/Steering_Input_YawRate'
   *  RelationalOperator: '<S1>/Relational Operator1'
   */
  if (rtU.Steering_Input_YawRate <= -120) {
    tmp_0 = -120;
  } else {
    tmp_0 = 0;
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Switch: '<S1>/Switch'
   *  Switch: '<S1>/Switch1'
   */
  rtb_Turn_Direction_Status = (int16_T)(tmp + tmp_0);

  /* Switch: '<S1>/Switch2' incorporates:
   *  Constant: '<S1>/RoadSign_Left'
   *  Constant: '<S1>/RoadSign_Right'
   *  Constant: '<S1>/RoadSign_Straight'
   *  Inport: '<Root>/RoadSign_Input_Camera'
   *  Switch: '<S1>/Switch3'
   */
  if (rtU.RoadSign_Input_Camera) {
    tmp = 30;
    tmp_0 = -120;
  } else {
    tmp = 0;
    tmp_0 = 0;
  }

  /* If: '<S1>/If' incorporates:
   *  Inport: '<Root>/RoadSign_Input_Camera'
   *  Switch: '<S1>/Switch2'
   *  Switch: '<S1>/Switch3'
   */
  if (rtU.RoadSign_Input_Camera && ((rtb_Turn_Direction_Status == tmp) ||
       (rtb_Turn_Direction_Status == tmp_0))) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Outport: '<Root>/Direction_Indecator_Output' */
    IfActionSubsystem(&rtY.Direction_Indecator_Output);

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem' */
  } else if ((!rtU.RoadSign_Input_Camera) && (rtb_Turn_Direction_Status == 0)) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Outport: '<Root>/Direction_Indecator_Output' */
    IfActionSubsystem(&rtY.Direction_Indecator_Output);

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Outport: '<Root>/Direction_Indecator_Output' incorporates:
     *  Constant: '<S4>/Constant'
     *  SignalConversion generated from: '<S4>/Out1'
     */
    rtY.Direction_Indecator_Output = false;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem2' */
  }

  /* End of If: '<S1>/If' */
}

/* Model initialize function */
void ADAS_Direction_Detection_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
