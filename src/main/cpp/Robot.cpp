/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.		                    */
/* Open Source Software - may be modified and shared by FRC teams. The code	 */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.		                                                           */
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
frc::Joystick *joy;
// Talons
TalonSRX *talon_drive_left_enc, *talon_drive_right_enc, *talon_drive_left_noenc, *talon_drive_right_noenc,
	*talon_elevator,
	*talon_intake_wheels, *talon_intake_clamp, *talon_intake_pivot,
	*talon_climber_vertical, *talon_climber_wheels;
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

	std::cout<<"andrew boi"<<std::endl;

	// initialize joystick
	joy = new Joystick(0);

	// initialize talons
	talon_drive_left_enc=new TalonSRX( drive_left_enc_talonnum );
	talon_drive_left_noenc=new TalonSRX( drive_left_noenc_talonnum );
	talon_drive_right_enc=new TalonSRX( drive_right_enc_talonnum );
	talon_drive_right_noenc=new TalonSRX( drive_right_noenc_talonnum );

	talon_elevator=new TalonSRX( elevator_talonnum );

	talon_intake_wheels=new TalonSRX( intake_wheels_talonnum );
	talon_intake_clamp=new TalonSRX( intake_clamp_talonnum );
	talon_intake_pivot=new TalonSRX( intake_pivot_talonnum );

	talon_climber_vertical=new TalonSRX( climber_vertical_talonnum );
	talon_climber_wheels=new TalonSRX( climber_wheels_talonnum );

	// initialize classes

	drivebase=new Drivebase(
		joy,
		talon_drive_left_enc,
		talon_drive_left_noenc,
		talon_drive_right_enc,
		talon_drive_right_noenc);

	elevator=new Elevator(
		joy,
		talon_elevator);

	intake_wheels=new Intake_wheels(
		joy,
		talon_intake_wheels);
	intake_clamp=new Intake_clamp(
		joy,
		talon_intake_clamp);
	intake_pivot=new Intake_pivot(
		joy,
		talon_intake_pivot);
	intake=new Intake(
		intake_wheels,
		intake_clamp);

	climber=new Climber(
		joy,
		talon_climber_vertical,
		talon_climber_wheels);

	pid=new PID(
		talon_drive_right_enc,
		talon_drive_left_enc,
		talon_intake_pivot,
		talon_climber_vertical,
		talon_climber_wheels,
		talon_elevator,
		talon_seat_enc);

	diagnostic=new Diagnostic(
		joy,
		talon_drive_left_enc,
		talon_drive_left_noenc,
		talon_drive_right_enc,
		talon_drive_right_noenc,
		talon_intake_wheels,
		talon_intake_clamp,
		talon_intake_pivot,
		talon_elevator,
		talon_elevator_noenc,
		talon_climber_wheels);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
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

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {}

void Robot::TestInit(){
	std::cout<<"aiight we gon' diagnose dis nau"<<std::endl;
}

void Robot::TestPeriodic() {
	diagnostic->update();
}

#ifndef RUNNING_FRC_TESTS
int main() { return StartRobot<Robot>(); }
#endif