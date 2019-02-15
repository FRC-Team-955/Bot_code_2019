#include <elevator.h>

using namespace frc;

/*
// Andrew's code- deprecated
void Elevator :: update () {

	std::cout<<"updating elevator";

	// collect values from joystick
	float upspeed = joy1->GetRawAxis( elevator_up_joynum );
	float downspeed = joy1->GetRawAxis( elevator_down_joynum );

	std::cout<<"\tup throttle="<<upspeed;
	std::cout<<"\tdown throttle="<<downspeed;

	// skew the values to get tiny motion with the belly of the joystick range and high values at the extremes
	upspeed = signedpow(upspeed, elevator_up_exp );
	downspeed = signedpow(downspeed, elevator_down_exp );

	// write to motor; add directions together so switching between up and down is smooth
	talon_enc->Set(ControlMode::PercentOutput, upspeed-downspeed );

	std::cout<<"\televator speed="<<upspeed-downspeed<<std::endl;
};
*/


// set height values
void Elevator :: calibrate (
	double rocket_low_hatch_pos,
	double rocket_low_ball_pos,
	double rocket_medium_hatch_pos,
	double rocket_medium_ball_pos,
	double rocket_high_hatch_pos,
	double rocket_high_ball_pos
) {
	rocket_low_hatch_pos=rocket_low_hatch_pos;
    rocket_low_ball_pos=rocket_low_ball_pos;
    rocket_medium_hatch_pos=rocket_medium_hatch_pos;
    rocket_medium_ball_pos=rocket_medium_ball_pos;
    rocket_high_hatch_pos=rocket_high_hatch_pos;
    rocket_high_ball_pos=rocket_high_ball_pos;
}

// write to the talon using preset settings
void Elevator :: writeToTalon (float vel) {
	talon_elevator->Set(ControlMode::Position, vel * elevator_max_speed);
}

// run this in TeleopPeriodic
void Elevator :: update () {

	//Toggle between auto & manual mode
	if (joy1->GetRawButton(7) and mode_toggle1==0 and mode_toggle2==0){
			man_mode= true;
			mode_toggle1 = 1;
	}
	if (!joy1->GetRawButton(7) and mode_toggle1){
			mode_toggle2=1;
	}
	if (joy1->GetRawButton(7) and mode_toggle2 == 1){
			man_mode = false;
			mode_toggle2 =2;
	}
	if (!joy1->GetRawButton(7) and mode_toggle2 == 2){
			mode_toggle1=0;
			mode_toggle2=0;
	}

		std::cout<<"\televator mode = "<<man_mode?"MANUAL":"AUTO";

	//run in auto mode
	if (!man_mode){
			//Switching Pos
			std::cout<<"current_elevator_pos="<<current_elevator_pos<<std::endl;
			if (joy1->GetRawButton(2)==1 and auto_toggle1 ==0) {
					current_elevator_pos++;
					auto_toggle1 = 1;
			}
			if (joy1->GetRawButton(2)==0 and auto_toggle1 ==1){
					auto_toggle1 = 0;
			}
			if (joy1->GetRawButton(1)==1 and auto_toggle2==0) {
					current_elevator_pos--;
					auto_toggle2=1;
			}
			if (joy1->GetRawButton(1)==0 and auto_toggle2 ==1){
					auto_toggle2 = 0;
			}

			// make sure current_elevator_pos doesn't go outside boundaries of movement
			if (current_elevator_pos < 1) current_elevator_pos = 1;
			if (current_elevator_pos > 3) current_elevator_pos = 3;

			//Determining Ball Pos
			if (!toggle_hatch1){
					switch (current_elevator_pos){
					case 1:
						this->writeToTalon( rocket_low_ball_pos );
						break;
					case 2:
						this->writeToTalon( rocket_medium_ball_pos );
						break;
					case 3:
						this->writeToTalon( rocket_high_ball_pos );
						break;
				}
			}
			//Determining Hatch Pos
			if (joy1->GetRawButton(3)==1 and !toggle_hatch1){
					toggle_hatch1 = true;
					switch (current_elevator_pos){
					case 1:
						this->writeToTalon( rocket_low_hatch_pos );
						break;
					case 2:
						this->writeToTalon( rocket_medium_hatch_pos );
						break;
					case 3:
						this->writeToTalon( rocket_high_hatch_pos );
						break;
					}
			}
			// write to the talon
			if (toggle_hatch1 and joy1->GetRawButton(1)==1 or joy1->GetRawButton(2)== 1){
					toggle_hatch1 = false;	
					switch (current_elevator_pos){
					case 1:
						talon_elevator->Set(ControlMode::Position, rocket_low_ball_pos);
						break;
					case 2:
						talon_elevator->Set(ControlMode::Position, rocket_medium_ball_pos);
						break;
					case 3:
						talon_elevator->Set(ControlMode::Position, rocket_high_ball_pos);
						break;
					}
			}
	}

	// run in manual mode
	if (man_mode){
			talon_elevator->Set(ControlMode::PercentOutput,
				signedpow( joy1->GetRawAxis(1), elevator_move_exp ));
			std::cout<<"MANUAL MODE ON"<<std::endl;
	}


}
