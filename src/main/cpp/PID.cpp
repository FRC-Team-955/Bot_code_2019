#include <PID.h>


// run this in teleopPeriodic
void PID :: run (){
	talon_drive_right_enc->Config_kP(3,0,10);
	talon_drive_right_enc->Config_kI(0,0,10);
	talon_drive_right_enc->Config_kD(1,0,10);
	talon_drive_right_enc->Config_kF(0,0,10);
    
	talon_drive_left_enc->Config_kP(3,0,10);
	talon_drive_left_enc->Config_kI(0,0,10);
	talon_drive_left_enc->Config_kD(1,0,10);
	talon_drive_left_enc->Config_kF(0,0,10);
    
	talon_intake_pivot->Config_kP(5,0,10);
	talon_intake_pivot->Config_kI(0,0,10);
	talon_intake_pivot->Config_kD(1,0,10);
	talon_intake_pivot->Config_kF(0,0,10);
    
	talon_climber_arm->Config_kP(0,0,10);
	talon_climber_arm->Config_kI(0,0,10);
	talon_climber_arm->Config_kD(0,0,10);
	talon_climber_arm->Config_kF(0,0,10);
    
	talon_elevator->Config_kP(2.7,0,10);
	talon_elevator->Config_kI(0,0,10);
	talon_elevator->Config_kD(0,0,10);
	talon_elevator->Config_kF(0,0,10);
    
	talon_seat->Config_kP(0,0,10);
	talon_seat->Config_kI(0,0,10);
	talon_seat->Config_kD(0,0,10);
	talon_seat->Config_kF(0,0,10);
    
	//talon->Config_kP(0, SmartDashboard::GetNumber ("DB/Slider 0"),10);
	//talon->Config_kI(0, SmartDashboard::GetNumber ("DB/Slider 1"),10);
	//talon->Config_kD(0, SmartDashboard::GetNumber ("DB/Slider 2"),10);
	//talon->Config_kF(0, SmartDashboard::GetNumber ("DB/Slider 3"),10);
}
