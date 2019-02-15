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

// run this in TeleopPeriodic
void Elevator :: update () {
	//Auto Mode
	if (mode==0){
			//Switching Pos
			std::cout<<"AUTO MODE ON"<<std::endl;
			std::cout<<"current_elevator_pos="<<current_elevator_pos<<std::endl;
			if (joy1->GetRawButton(2)==1 and toggle1 ==0) {
					current_elevator_pos = current_elevator_pos +1;
					toggle1 = 1;
			}
			if (joy1->GetRawButton(2)==0 and toggle1 ==1){
					toggle1 = 0;
			}
			if (joy1->GetRawButton(1)==1 and toggle2==0) {
					current_elevator_pos = current_elevator_pos -1;
					toggle2=1;
			}
			if (joy1->GetRawButton(1)==0 and toggle2 ==1){
					toggle2 = 0;
			}
			//Determining Ball Pos
			if (toggle_hatch1 == 0){
					if (current_elevator_pos >= 4){
							current_elevator_pos =3;
					}
					if (current_elevator_pos <=0){
							current_elevator_pos = 1;
					}
					if (current_elevator_pos ==1){
							talon_elevator->Set(ControlMode::Position, rocket_low_ball_pos);
					}
					if (current_elevator_pos ==2){
							talon_elevator->Set(ControlMode::Position, rocket_medium_ball_pos);
					}
					if (current_elevator_pos==3){
							talon_elevator->Set(ControlMode::Position, rocket_high_ball_pos);
					}
			}
			//Determining Hatch Pos
			if (joy1->GetRawButton(3)==1 and toggle_hatch1==0){
					if (current_elevator_pos == 1) {
							talon_elevator->Set(ControlMode::Position, rocket_low_hatch_pos);
					}
					if (current_elevator_pos == 2){
							talon_elevator->Set(ControlMode::Position, rocket_medium_hatch_pos);
					}
					if (current_elevator_pos ==3 ){
							talon_elevator->Set(ControlMode::Position, rocket_high_hatch_pos);
					}
					toggle_hatch1 = 1;
			}
			// write to the talon
			if (toggle_hatch1 == 1 and joy1->GetRawButton(1)==1 or joy1->GetRawButton(2)== 1){
					if (current_elevator_pos >= 4){
							current_elevator_pos =3;
					}
					if (current_elevator_pos <=0){
							current_elevator_pos = 1;
					}
					if (current_elevator_pos ==1){
							talon_elevator->Set(ControlMode::Position, rocket_low_ball_pos);
					}
					if (current_elevator_pos ==2){
							talon_elevator->Set(ControlMode::Position, rocket_medium_ball_pos);
					}
					if (current_elevator_pos==3){
							talon_elevator->Set(ControlMode::Position, rocket_high_ball_pos);
					}
					toggle_hatch1 =0;	
			}
	}

	//Manual Mode
	if (joy1->GetRawButton(7)==1 and mode_toggle1 == 0 and mode_toggle2 ==0){
			mode= 1;
			mode_toggle1 = 1;
	}
	if (joy1->GetRawButton(7)==0 and mode_toggle1){
			mode_toggle2=1;
	}
	if (joy1->GetRawButton(7)== 1 and mode_toggle2 == 1){
			mode = 0;
			mode_toggle2 =2;
	}
	if (joy1->GetRawButton(7)==0 and mode_toggle2 == 2){
			mode_toggle1=0;
			mode_toggle2=0;
	}
	// write to talon if manual mode is engaged
	if (mode ==1){
			talon_elevator->Set(ControlMode::PercentOutput,
				joy1->GetRawAxis(1)* -1 *joy1->GetRawAxis(1)* joy1->GetRawAxis(1));
			std::cout<<"MANUAL MODE ON"<<std::endl;
	}


}




