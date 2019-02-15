#include <climber.h>

using namespace frc;
/*climb sequence:
	-raise elevator
	-servo disengage/reengage to drop boom
	-lower climb arm
	-simultaneously:
		-lower elevator
		-lower climb arm
		-roll climb wheels
*/

void Climber::run_climber (double max_speed){
	climber_talon_vertical_enc->Set(ControlMode::PercentOutput,
		max_speed*joy1->GetRawAxis(4) );
	climber_talon_drive_enc->Set(ControlMode::PercentOutput,
		max_speed*joy1->GetRawButton(1) );
	climber_talon_drive_enc->Set(ControlMode::PercentOutput,
		-1 *max_speed*joy1->GetRawButton(2) );

}
