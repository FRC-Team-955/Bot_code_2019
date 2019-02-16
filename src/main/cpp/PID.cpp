#include <PID.h>


// run this in teleopPeriodic
void PID :: update (){
	talon_drive_right_enc->Config_kP(0,0,10);
	talon_drive_right_enc->Config_kI(0,0,10);
	talon_drive_right_enc->Config_kD(0,0,10);
	talon_drive_right_enc->Config_kF(0,0,10);
    
	talon_drive_left_enc->Config_kP(0,0,10);
	talon_drive_left_enc->Config_kI(0,0,10);
	talon_drive_left_enc->Config_kD(0,0,10);
	talon_drive_left_enc->Config_kF(0,0,10);
    
	talon_intake_pivot->Config_kP(0,0,10);
	talon_intake_pivot->Config_kI(0,0,10);
	talon_intake_pivot->Config_kD(0,0,10);
	talon_intake_pivot->Config_kF(0,0,10);
    
	talon_climber_enc->Config_kP(0,0,10);
	talon_climber_enc->Config_kI(0,0,10);
	talon_climber_enc->Config_kD(0,0,10);
	talon_climber_enc->Config_kF(0,0,10);
    
	talon_elevator_enc->Config_kP(0,0,10);
	talon_elevator_enc->Config_kI(0,0,10);
	talon_elevator_enc->Config_kD(0,0,10);
	talon_elevator_enc->Config_kF(0,0,10);
    
	talon_seat->Config_kP(0,0,10);
	talon_seat->Config_kI(0,0,10);
	talon_seat->Config_kD(0,0,10);
	talon_seat->Config_kF(0,0,10);
    
	//talon->Config_kP(0, SmartDashboard::GetNumber ("DB/Slider 0"),10);
	//talon->Config_kI(0, SmartDashboard::GetNumber ("DB/Slider 1"),10);
	//talon->Config_kD(0, SmartDashboard::GetNumber ("DB/Slider 2"),10);
	//talon->Config_kF(0, SmartDashboard::GetNumber ("DB/Slider 3"),10);
}
