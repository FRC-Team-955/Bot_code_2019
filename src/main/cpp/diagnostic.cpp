#include <diagnostic.h>

using namespace frc;


// increase or decrease ID number
void Diagnostic :: tickID (bool sign) {
	if(sign){
		// increase
		currentID++;
		// loop back to 0
		if (currentID==10) currentID=0;
	}else{
		// loop back to top
		if (currentID==0) currentID=10;
		// decrease
		currentID--;
	}
	std::cout<<"ID# = "<<currentID+1<<std::endl;
}

// change value of current talon
void Diagnostic :: writeToCurrentTalon (float speed) {
	talonCatalog[currentID]->Set(ControlMode::PercentOutput,
		//each motor has different max speeds built in
		speed * test_vels[currentID] );
}

// public handler for all diagnostic operations
void Diagnostic :: update () {

	// collect tick values
	isPressedA = joy->GetRawButton( diagnostic_tickup_joynum );
	isPressedB = joy->GetRawButton( diagnostic_tickdown_joynum );

	// decide whether to tick or not; tick up gets priority
	if( isPressedA && wasntPressedA ){ // A is pressed now and wasn't pressed last frame
		// neutralize current talon
		writeToCurrentTalon(0.0);
		// switch to the next talon
		tickID(true);

	}else if( isPressedB && wasntPressedB ){ // B is pressed now and wasn't last frame
		// neutralize current talon
		writeToCurrentTalon(0.0);
		// switch to the previous talon
		tickID(false);
	}

	// update speed of current talon
	writeToCurrentTalon(joy->GetRawAxis(diagnostic_test_joynum));

	// collect tick values for next frame
	wasntPressedA = !joy->GetRawButton( diagnostic_tickup_joynum );
	wasntPressedB = !joy->GetRawButton( diagnostic_tickdown_joynum );
}
