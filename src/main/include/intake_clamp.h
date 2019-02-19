#ifndef INTAKE_CLAMP_H
#define INTAKE_CLAMP_H

#include <constants.h>
#include <frc/DigitalInput.h>


class Intake_clamp {
public:
	// initialize intake_clamp
	Intake_clamp (
		// receive parameters
		frc::Joystick *joy1,
		TalonSRX *talon_clamp,
		frc::DigitalInput *limit_inner,
		frc::DigitalInput *limit_outer
	):
		// initialize member variables
		joy1(joy1),
		talon_clamp(talon_clamp),
		limit_inner(limit_inner),
		limit_outer(limit_outer)
	{
		// run on initialization
		std::cout<<"\n\t\tintake_clamp";
	};

	// run this in TeleopPeriodic
	void update();
private:
	frc::Joystick *joy1;
	TalonSRX *talon_clamp;
	frc::DigitalInput *limit_outer, *limit_inner;
	bool closeButton=false, openButton=false;
	float clampSpeed = intake_clamp_speed;
};

#endif
