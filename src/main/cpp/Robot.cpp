/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include <ctre/Phoenix.h>
#include <frc/Joystick.h>

#include <constants.h>
#include <drivebase.h>
#include <elevator.h>
#include <intake_wheels.h>
#include <intake_clamp.h>
#include <intake_pivot.h>
#include <intake.h>
#include <climber.h>
#include <PID.h>
#include <diagnostic.h>

#include <frc/smartdashboard/SmartDashboard.h>

using namespace frc;

// Joystick
frc::Joystick *joy0, *joy1;
// Talons
TalonSRX *talon_drive_left_enc, *talon_drive_right_enc, *talon_drive_left_noenc, *talon_drive_right_noenc,
	*talon_elevator,
	*talon_intake_wheels, *talon_intake_clamp, *talon_intake_pivot,
	*talon_climber_arm, *talon_climber_wheels;
// Servo
Servo *servo_lock;
// limit switches
DigitalInput *limit_clamp_inner, *limit_clamp_outer;
// classes
Drivebase *drivebase;
Elevator *elevator;
Intake_wheels *intake_wheels;
Intake_clamp *intake_clamp;
Intake_pivot *intake_pivot;
Intake *intake;
Climber *climber;
PID *pid;
Diagnostic *diagnostic;


void Robot::RobotInit() {
	m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
	m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
	frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

	std::cout<<"initializing:";

	// initialize joystick
	std::cout<<"\n\t\tjoysticks";
	joy0 = new Joystick(0);
	joy1 = new Joystick(1);

	// initialize talons
	std::cout<<"\n\t\ttalons";
	talon_drive_left_enc=new TalonSRX( drive_left_enc_talonnum );
	talon_drive_left_noenc=new TalonSRX( drive_left_noenc_talonnum );
	talon_drive_right_enc=new TalonSRX( drive_right_enc_talonnum );
	talon_drive_right_noenc=new TalonSRX( drive_right_noenc_talonnum );

	talon_elevator=new TalonSRX( elevator_talonnum );

	talon_intake_wheels=new TalonSRX( intake_wheels_talonnum );
	talon_intake_clamp=new TalonSRX( intake_clamp_talonnum );
	talon_intake_pivot=new TalonSRX( intake_pivot_talonnum );

	talon_climber_arm=new TalonSRX( climber_arm_talonnum );
	talon_climber_wheels=new TalonSRX( climber_wheels_talonnum );

	// initialize servo
	servo_lock = new Servo( servo_lock_rionum );

	// initialize limit switches
	limit_clamp_inner = new DigitalInput( clamp_inner_limitnum );
	limit_clamp_outer = new DigitalInput( clamp_outer_limitnum );

	// initialize classes
	std::cout<<"\ninitializing classes:";

	drivebase=new Drivebase(
		joy0,
		talon_drive_left_enc,
		talon_drive_left_noenc,
		talon_drive_right_enc,
		talon_drive_right_noenc);

	elevator=new Elevator(
		joy1,
		talon_elevator);

	intake_wheels=new Intake_wheels(
		joy1,
		talon_intake_wheels);
	intake_clamp=new Intake_clamp(
		joy1,
		talon_intake_clamp,
		limit_clamp_inner,
		limit_clamp_outer);
	intake_pivot=new Intake_pivot(
		joy1,
		talon_intake_pivot);
	intake=new Intake(
		intake_wheels,
		intake_clamp,
		intake_pivot);

	climber=new Climber(
		joy0,
		joy1,
		talon_climber_arm,
		talon_climber_wheels,
		servo_lock);

	pid=new PID(
		talon_drive_right_enc,
		talon_drive_left_enc,
		talon_intake_pivot,
		talon_climber_wheels,
		talon_elevator,
		talon_intake_clamp);

	diagnostic=new Diagnostic(
		joy0,
		talon_drive_left_noenc,
		talon_drive_left_enc,
		talon_drive_right_noenc,
		talon_drive_right_enc,
		talon_intake_wheels,
		talon_climber_arm,
		talon_climber_wheels,
		talon_elevator,
		talon_intake_clamp,
		talon_intake_pivot);

	std::cout<<"\nyo, init complete!"<<std::endl;
}

/*
 * This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
	m_autoSelected = m_chooser.GetSelected();
	// m_autoSelected = SmartDashboard::GetString("Auto Selector",
	// 	kAutoNameDefault);
	std::cout << "Auto selected: " << m_autoSelected << std::endl;

	if (m_autoSelected == kAutoNameCustom) {
		// Custom Auto goes here
	} else {
		// Default Auto goes here
	}
}

void Robot::AutonomousPeriodic() {
	if (m_autoSelected == kAutoNameCustom) {
		// Custom Auto goes here
	} else {
		// Default Auto goes here
	}
}

void Robot::TeleopInit() {
	pid->run();
}

void Robot::TeleopPeriodic() {
	//drivebase->update();
	//elevator->update();
	intake->update();
	climber->update();
}

void Robot::TestInit(){
	std::cout<<"aiight we gon' diagnose dis nau"<<std::endl;
}

void Robot::TestPeriodic() {
	std::cout<<"yaboiiii\t";
	diagnostic->update();
}

#ifndef RUNNING_FRC_TESTS
int main() { return StartRobot<Robot>(); }
#endif
