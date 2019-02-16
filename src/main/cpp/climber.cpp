#include <climber.h>

using namespace frc;
/*climb sequence:
	-raise elevator
	-servo disengage/reengage to drop boom
	-lower climb arm
	-simultaneously:
		-lower elevator
		-lower climb arm
		-roll climb wheels
*/

// toggle whether or not servo is engaged
void Climber :: servo_toggle () {
	bool servo_toggle1 =false;
	bool servo_toggle2=false;
	if (joy0->GetRawButton(servo_toggle_joynum)==1 and !servo_toggle1 and !servo_toggle2){
		// unlocks servo
		lock_servo->Set(1.0);
		servo_toggle1 = true;
	}
	if (joy0->GetRawButton(servo_toggle_joynum)==0 and servo_toggle1 ){
		servo_toggle2 = true;
	}
	if (joy0->GetRawButton(servo_toggle_joynum)==1 and servo_toggle2 and servo_toggle1){
		// lock_servo
		lock_servo->Set(0);
		servo_toggle1 = false;
	}
	if (joy0->GetRawButton(servo_toggle_joynum)==0 and servo_toggle2 and !servo_toggle1){
		servo_toggle1 = false;
		servo_toggle2 = false;
	}
}

// put this in teleopPeriodic
void Climber :: update () {
	// check for the servo
	this->servo_toggle();

	// write to climber wheel
	climber_talon_wheel->Set(ControlMode::PercentOutput,
		climber_wheels_max_speed * joy0->GetRawButton(climber_wheels_joynum));

	// lower climber arm
	if (joy0->GetRawButton(climber_arm_down_joynum)==1){
		climber_talon_arm->Set(ControlMode::PercentOutput,  climber_arm_max_speed);
	}
	// raise climber arm
	else if (joy0->GetRawButton(climber_arm_up_joynum)==1){
		climber_talon_arm->Set(ControlMode::PercentOutput, -climber_arm_max_speed);
	}
	// stop arm if neither button is pressed
	else {
		climber_talon_arm->Set(ControlMode::PercentOutput, 0);
	}
}
