#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <constants.h>


class Elevator {
public:
	// initialize elevator
	Elevator(
		// receive parameters
		frc::Joystick* joy1,
		TalonSRX* talon_elevator
	):
		// initialize members with given parameters
		joy1(joy1),
		talon_elevator(talon_elevator)
	{
		// run on initialization
		std::cout<<"\n\t\televator";
	};

	// set height values
	void calibrate (
		double rocket_low_hatch_pos,
		double rocket_low_ball_pos,
		double rocket_medium_hatch_pos,
		double rocket_medium_ball_pos,
		double rocket_high_hatch_pos,
		double rocket_high_ball_pos
	);

	// write to the talon using preset settings
	void writeToTalon(float vel);

	// run this in TeleopPeriodic
	void update();
private:
	frc::Joystick* joy1;
	TalonSRX* talon_elevator;

	double	rocket_low_hatch_pos,
			rocket_low_ball_pos,
			rocket_medium_hatch_pos,
			rocket_medium_ball_pos,
			rocket_high_hatch_pos,
			rocket_high_ball_pos;

	int current_elevator_pos=1;
	int auto_toggle1=0, auto_toggle2=0;
	bool toggle_hatch1=false;
	bool man_mode=true;
	int mode_toggle1=0, mode_toggle2=0;
};



#endif
