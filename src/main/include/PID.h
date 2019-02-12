#ifndef PID_H
#define PID_H

#include <constants.h>


class PID {
public:
	// initialize PID
	PID(
		// receive parameters
		TalonSRX* talon_drive_right_enc,
		TalonSRX* talon_drive_left_enc,
		TalonSRX* talon_intake_pivot,
		TalonSRX* talon_climber_enc,
		TalonSRX* talon_elevator_enc,
		TalonSRX* talon_seat
	):
		// initialize member variables
		talon_drive_right_enc(talon_drive_right_enc),
		talon_drive_left_enc(talon_drive_left_enc),
		talon_intake_pivot(talon_intake_pivot),
		talon_climber_enc(talon_climber_enc),
		talon_elevator_enc(talon_elevator_enc),
		talon_seat(talon_seat)
	{
		// run on initialization
		std::cout<<"initializing PID";
	};

	// run
	void run_pid ();
private:
	TalonSRX* talon_drive_right_enc, *talon_drive_left_enc;
	TalonSRX* talon_intake_pivot;
	TalonSRX* talon_climber_enc;
	TalonSRX* talon_elevator_enc;
	TalonSRX* talon_seat;

};

#endif
