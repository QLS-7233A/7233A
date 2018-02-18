#pragma config(Sensor, in1,    Arm2Potentiometer, sensorPotentiometer)
#pragma config(Motor,  port1,           leftArm,       tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           leftFront,     tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           rightFront,    tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port4,           leftBack,      tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port5,           rightBack,     tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port6,           leftIntake,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rightIntake,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           claw,          tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port9,           arm2,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightArm,      tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


float x;
float y;
float z;


task main()
{
	enableCompetitionMode();
	repeat (forever) {
		//// Place Autonomous Commands Below
		if (getCompetitionAutonomous() == true) {
			// Mobile Goal Intake Down
			setMultipleMotors(90, port6, port7, noMotor, noMotor);
			wait(1, seconds);
			stopMultipleMotors(port6, port7, noMotor, noMotor);
			// Forward towards Mobile Goal
			forward(2.5, seconds, 70);
			// Intake Mobile Goal
			setMultipleMotors(-100, port6, port7, noMotor, noMotor);
			wait(1, seconds);
			stopMultipleMotors(port6, port7, noMotor, noMotor);
			// Go backwards
			backward(1.8, seconds, 65);
			// Turn Left (Or Right depending on location) 
			turnLeft(2, seconds, 55);
			//turnRight(2, seconds, 55);
			// Go forward into 10 pt zone
			forward(1.5, seconds, 70);
			// Go forward into 20 pt zone
			//forward(2.5, seconds, 80);
			// Put Mobile Goal Down
			setMultipleMotors(75, port6, port7, noMotor, noMotor);
			wait(1, seconds);
			stopMultipleMotors(port6, port7, noMotor, noMotor);
			// Go Backwards
			backward(2, seconds, 75);
			// Put Mobile Goal intake back up
			setMultipleMotors(-90, port6, port7, noMotor, noMotor);
			wait(1, seconds);
			stopMultipleMotors(port6, port7, noMotor, noMotor);
		}
		// Place Remote Control Commands Below
		if (getCompetitionDriverControl() == true) {
			repeat (forever) {
				// Drive Train Full Power/65%
				if (vexRT[Btn6U] == 1) {
					setMultipleMotors(127, port3, port5, noMotor, noMotor);
				} else {
					if (vexRT[Btn6D] == 1) {
						setMultipleMotors(-127, port3, port5, noMotor, noMotor);
					} else {
						if (vexRT[Btn8U] == 1) {
							setMultipleMotors(75, port3, port5, noMotor, noMotor);
						} else {
							if (vexRT[Btn8D] == 1) {
								setMultipleMotors(-75, port3, port5, noMotor, noMotor);
							} else {
								setMultipleMotors(0, port3, port5, noMotor, noMotor);
							}
						}
					}
				}
				if (vexRT[Btn5U] == 1) {
					setMultipleMotors(127, port2, port4, noMotor, noMotor);
				} else {
					if (vexRT[Btn5D] == 1) {
						setMultipleMotors(-127, port2, port4, noMotor, noMotor);
					} else {
						if (vexRT[Btn7U] == 1) {
							setMultipleMotors(75, port2, port4, noMotor, noMotor);
						} else {
							if (vexRT[Btn7D] == 1) {
								setMultipleMotors(-75, port2, port4, noMotor, noMotor);
							} else {
								setMultipleMotors(0, port2, port4, noMotor, noMotor);
							}
						}
					}
				}
				// Intake
				if (vexRT[Ch2] > 15) {
					setMultipleMotors(y, leftIntake, rightIntake, noMotor, noMotor);
					y = vexRT[Ch2] * 0.5;
					wait(1, milliseconds);
				} else {
					if (vexRT[Ch2] < -15) {
						setMultipleMotors(y, leftIntake, rightIntake, noMotor, noMotor);
						y = vexRT[Ch2] * 0.5;
						wait(1, milliseconds);
					} else {
						setMultipleMotors(0, leftIntake, rightIntake, noMotor, noMotor);
					}
				}
				// Arm control
				joystickControl(port10, Ch2Xmtr2, 30);
				joystickControl(port1, Ch2Xmtr2, 30);
				// Arm2 control
				joystickControl(Arm2, Ch3Xmtr2, 30);
				// Semi-autonomous for stacking cones, based on # of cones and their individual stacking angles, (all diff b/c of tilt)
				if (vexRT[Btn6DXmtr2] == 1) {
					z = z + 1;
					if (z == 1) {
						setMotor(arm2, 50);
						waitUntil (SensorValue[Arm2Potentiometer] >= val);
						stopMotor(arm2);
					} else {
						if (z == 2) {
							setMotor(arm2, 50);
							waitUntil (SensorValue[Arm2Potentiometer] >= val);
							stopMotor(arm2);
						} else {
							if (z == 3) {
								setMotor(arm2, 50);
								waitUntil (SensorValue[Arm2Potentiometer] >= val);
								stopMotor(arm2);
							} else {
								if (z == 4) {
									setMotor(arm2, 50);
									waitUntil (SensorValue[Arm2Potentiometer] >= val);
									stopMotor(arm2);
								} else {
									if (z == 5) {
										setMotor(arm2, 50);
										waitUntil (SensorValue[Arm2Potentiometer] >= val);
										stopMotor(arm2);
									} else {
										if (z == 6) {
											setMotor(arm2, 50);
											waitUntil (SensorValue[Arm2Potentiometer] >= val);
											stopMotor(arm2);
										} else {
											if (z == 7) {
												setMotor(arm2, 50);
												waitUntil (SensorValue[Arm2Potentiometer] >= val);
												stopMotor(arm2);
											} else {
												if (z == 8) {
													setMotor(arm2, 50);
													waitUntil (SensorValue[Arm2Potentiometer] >= val);
													stopMotor(arm2);
												} else {
													if (z == 9) {
														setMotor(arm2, 50);
														waitUntil (SensorValue[Arm2Potentiometer] >= val);
														stopMotor(arm2);
													} else {
														if (z == 10) {
															setMotor(arm2, 50);
															waitUntil (SensorValue[Arm2Potentiometer] >= val);
															stopMotor(arm2);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				// If cone misses using 7D, subtracts 1 cone from stack memory. If multiple fall off, press according to number of cones that have fallen
				if (vexRT[Btn7RXmtr2] == 1) {
					z = z - 1;
				}
				// When mobile goal has been stacked, reset stack memory
				if (vexRT[Btn7LXmtr2] == 1) {
					z = 0;
				}
				// Holding the cone (claw function)
				if (vexRT[Btn7DXmtr2] == 1) {
					setMotor(claw, 50);
					waitUntil (vexRT[Btn8DXmtr2] == 1);
					stopMotor(claw);
					setMotor(claw, -80);
					wait(1, seconds);
					stopMotor(claw);
				}
				// Claw control
				armControl(claw, Btn5UXmtr2, Btn5DXmtr2, 50);
			}
		}
	}
}
