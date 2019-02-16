#ifndef CLIMBER_H
#define CLIMBER_H

#include <constants.h>

class Climber {
public:
	// initialize climber
	Climber(
		// receive parameters
		frc::Joystick *joy0,
		frc::Joystick *joy1,
		TalonSRX *climber_talon_arm,
		TalonSRX *climber_talon_wheel,
		frc::Servo *lock_servo
	):
		// initialize member variables
		joy0(joy0),
		joy1(joy1),
		climber_talon_arm(climber_talon_arm),
		climber_talon_wheel(climber_talon_wheel),
		lock_servo(lock_servo)
	{
		// run on initialization
		std::cout<<"\n\tclimber";
	};

	// put this in teleopPeriodic
	void update();

	// toggle whether or not servo is engaged
	void servo_toggle();

private:
	frc::Joystick *joy0, *joy1;
	TalonSRX *climber_talon_wheel;
	TalonSRX *climber_talon_arm;
	frc::Servo *lock_servo;
};


#endif
