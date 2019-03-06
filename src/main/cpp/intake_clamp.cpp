#include <intake_clamp.h>

using namespace frc;


// run this in TeleopPeriodic
void Intake_clamp :: update () {

	std::cout<<"updating intake_clamp";

	// collect values from joystick
	closeButton = joy1->GetRawButton( intake_clamp_close_joynum );
	openButton = joy1->GetRawButton( intake_clamp_open_joynum );

	std::cout<<"\tclose-"<<closeButton<<"  open-"<<openButton;

	// container variable for motor speed; default speed=0
	clampSpeed = 0.0;

	// if either button is pressed, change the clamping velocity from zero
	//...but if the inner or outer limit has been reached, the corresponding direction is disabled
	if(openButton ){//&& !limit_outer->Get() ){
		clampSpeed =-intake_clamp_speed;
	}
	// if both buttons are pressed, "close" overwrites "open"
	if(closeButton ){//&& !limit_inner->Get() ){
		 clampSpeed = intake_clamp_speed;
	}

	// write to motors
	talon_clamp->Set(ControlMode::PercentOutput, clampSpeed );

	std::cout<<"\tclamp speed="<<clampSpeed<<std::endl;
}
