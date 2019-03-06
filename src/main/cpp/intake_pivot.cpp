//NEEDS TO BE PID TUNED
#include <intake_pivot.h>

using namespace frc;

// put this in TeleopPeriodic
void Intake_pivot :: update () {
	talon_intake_pivot->Set(ControlMode::PercentOutput, joy1->GetRawButton(intake_pivot_joynum)*intake_pivot_speed);
/*
	if (joy1->GetRawButton(5)==1 and toggle == 0 and toggle_two==0){

		talon_intake_pivot->Set(ControlMode::Position, 20000);
		toggle = 1;
	}
	if (joy1->GetRawButton(5)==0 and toggle == 1) {

		toggle = 2;
	}
	if (joy1->GetRawButton(5)==1 and toggle_two == 2) {

		talon_intake_pivot->Set(ControlMode::Position, -20000);
		toggle_two = 1;
	}
	if (joy1->GetRawButton(5)==0 and toggle_two==1){
		toggle_two =0;
		toggle = 0;
	}
*/
}
