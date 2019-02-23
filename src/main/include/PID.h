#ifndef PID_H
#define PID_H

#include <constants.h>


class PID {
public:
	// initialize PID
	PID(
		// receive parameters
		TalonSRX *talon_drive_right_enc,
		TalonSRX *talon_drive_left_enc,
		TalonSRX *talon_intake_pivot,
		TalonSRX *talon_climber_arm,
		TalonSRX *talon_elevator,
		TalonSRX *talon_seat
	):
		// initialize member variables
		talon_drive_right_enc(talon_drive_right_enc),
		talon_drive_left_enc(talon_drive_left_enc),
		talon_intake_pivot(talon_intake_pivot),
		talon_climber_arm(talon_climber_arm),
		talon_elevator(talon_elevator),
		talon_seat(talon_seat)
	{
		// run on initialization
		std::cout<<"initializing PID";
	};

	// run this in teleopPeriodic
	void run ();

private:
	TalonSRX *talon_drive_right_enc, *talon_drive_left_enc;
	TalonSRX *talon_intake_pivot;
	TalonSRX *talon_climber_arm;
	TalonSRX *talon_elevator;
	TalonSRX *talon_seat;

};

#endif
