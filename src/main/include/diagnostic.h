#ifndef DIAGNOSTIC_H
#define DIAGNOSTIC_H

#include <constants.h>


class Diagnostic {
public:
	// initialize diagnostic
	Diagnostic (
		// receive parameters
		frc::Joystick *joy,
		TalonSRX *talon_drive_left_noenc,
		TalonSRX *talon_drive_left_enc,
		TalonSRX *talon_drive_right_noenc,
		TalonSRX *talon_drive_right_enc,
		TalonSRX *talon_intake_wheels,
		TalonSRX *talon_climber_arm,
		TalonSRX *talon_climber_wheels,
		TalonSRX *talon_elevator,
		TalonSRX *talon_intake_clamp,
		TalonSRX *talon_intake_pivot
	):
		// initialize member variables
		joy(joy),// joystick
		talonCatalog{// all the talons arranged in an array
			talon_drive_left_noenc,
            talon_drive_left_enc,
            talon_drive_right_noenc,
            talon_drive_right_enc,
            talon_intake_wheels,
            talon_climber_arm,
			talon_climber_wheels,
            talon_elevator,
            talon_intake_clamp,
			talon_intake_pivot
		}
	{
		// run on initialization
		std::cout<<"\n\tdiagnostic";
	};

	// run this in TestPeriodic
	void update();

private:
	// tick the ID number up or down
	void tickID(bool sign);
	// write to the currently selected talon using the builtin ID
	void writeToCurrentTalon(float speed);

	// all the talons are arranged in an array, so we can acces them by ID
	TalonSRX* talonCatalog[10]={};
	// velocities for all talons
	const float test_vels[10]={
		drive_max_speed,
		drive_max_speed,
		drive_max_speed,
		drive_max_speed,
		intake_wheels_speed,
		climber_arm_max_speed,
		climber_wheels_max_speed,
		elevator_max_speed,
		intake_clamp_speed,
		intake_pivot_speed
	};

	// joystick
	frc::Joystick *joy;

	// which talon is being tested right now?
	int currentID=0;
	// booleans for toggling buttons
	bool isPressedA=false;
	bool wasntPressedA=true;
	bool isPressedB=false;
	bool wasntPressedB=true;
};

#endif
