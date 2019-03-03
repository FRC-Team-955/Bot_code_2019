#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <frc/WPILib.h>
#include <frc/Joystick.h>
#include <frc/Servo.h>
#include <frc/DigitalInput.h>
#include <ctre/Phoenix.h>
#include <iostream>
#include <math.h>


// talon numbers
const int drive_left_enc_talonnum = 2;
const int drive_left_noenc_talonnum = 1;
const int drive_right_enc_talonnum = 4;
const int drive_right_noenc_talonnum = 3;
const int elevator_talonnum  = 8;
const int intake_wheels_talonnum = 9;
const int intake_clamp_talonnum = 10;
const int intake_pivot_talonnum = 5;
const int climber_arm_talonnum = 6;
const int climber_wheels_talonnum = 7;

// other RIO-interfacing hardware numbers
const int servo_lock_rionum = 0;
const int clamp_inner_limitnum = 0;
const int clamp_outer_limitnum = 1;


/*			Joystick #0
	  A2           A3			  1,2=	diagnostic talonnum up/down
   _/III\5_______/III\6			  1,3=	out/in climber wheels
  /  A1             4  \			2=	servo toggle
 /  (9)A0  7 H 8  3   2 \<-trg		5=	
 \       ^          1   /<-top		6=	
 /     <POV>    A5      \		   A5=	diagnostic talon test
/        v     (0)A4     \		A2,A3=	climber arm
\      ____________      /		A1,A4=	drive
 \____/            \____/
*/
// joystick 0 axis numbers
const int drive_move_joynum = 1;
const int drive_turn_joynum = 4;
const int climber_arm_down_joynum = 3;
const int climber_arm_up_joynum =2;
// joystick 0 button numbers
const int servo_toggle_joynum = 2;
const int climber_wheels_joynum =1;
const int climber_wheels_rev_joynum =3;

// joystick 0 axis/button numbers for diagnostic mode
const int diagnostic_test_joynum = 5;
const int diagnostic_tickup_joynum = 1;
const int diagnostic_tickdown_joynum = 2;


/*			Joystick #1
	  A2           A3			  	1=	
   _/III\5_______/III\6				2=	
  /  A1             4  \		  1,2=	close/open claw
 /  (9)A0  7 H 8  3   2 \<-trg	  5,6=	in/out intake wheels
 \       ^          1   /<-top		7=	
 /     <POV>    A5      \		   A1=	
/        v     (0)A4     \		A2,A3=	down/up elevator
\      ____________      /		   A5=	
 \____/            \____/
*/
// joystick 1 axis numbers
const int elevator_up_joynum = 3;
const int elevator_down_joynum = 2;
const int intake_pivot_joynum = 5;
// joystick 1 button numbers
const int intake_wheels_in_joynum = 5;
const int intake_wheels_out_joynum = 6;
const int intake_clamp_close_joynum = 1;
const int intake_clamp_open_joynum = 2;



// wheel velocities
const float drive_max_speed = 0.6;
const float elevator_max_speed = 0.15;
const float intake_wheels_speed = 0.3;
const float intake_clamp_speed  = 0.6;
const float intake_pivot_speed  = 0.15;
const float climber_arm_max_speed = 0.1;
const float climber_wheels_max_speed = 0.3;
const float diagnostic_default_speed = 0.5;


// exponents for variable motion values- this way, most of the joystick's range will correspond to low values, and only the extremes will make high speeds
const int drive_move_exp = 2;
const int drive_turn_exp = 3;
const int elevator_move_exp = 3;

// raise number to given exponent, but preserve its sign. I made it a preproccessor macro so the compiler wouldn't complain about defining a function multiple times, and it is faster anyway.
#define signedpow(val,exp) copysignf(powf(val,exp),val)

#endif
