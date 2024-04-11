#include "main.h"

/////
// For installation, upgrading, documentations and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 90;  
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;

///
// Constants
///
void default_constants() {
  chassis.pid_heading_constants_set(6.5, 0.1, 17);
  chassis.pid_drive_constants_forward_set(7.3,0,21);
  chassis.pid_drive_constants_backward_set(7.4,0,22.75);
  chassis.pid_turn_constants_set(1.8, 0, 7);
  chassis.pid_swing_constants_forward_set(4.6,0,22);
  chassis.pid_swing_constants_backward_set(4,0,19);

  chassis.pid_turn_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassis.pid_swing_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassis.pid_drive_exit_condition_set(300_ms, 1_in, 500_ms, 3_in, 750_ms, 750_ms);

  chassis.slew_drive_constants_set(7_in, 80);
}



// . . .
// Make your own autonomous functions here!
// . . .

/*
  winPointMatchAuto() psuedo code;

  1. drive forward to the opposite side corner while intaking, this lets us grab the triball that starts under the hang bar.
     We will also outtake the triball in the direction of the side of the net
  2. Matchload the alliance color triball from the corner using our wing
  3. Readjust the robot -> score the alliance color triball into the side of the net as well as score the triball in intake.
  4. Move to the center of the field and grab the triballs in the neutral zone, and outtake them towards the net
  5. After Outtakeing all four triballs in the neutral zone, into the front of the net,
     intake the last triball that is positioned in our alliance zone, and push all 4 triballs 
     from before into the net as well as the new triball in the intake
  6. Push around 2-3 times, exact number will be found via testing.
  6.1. If time permits, the 24"x24" robot is known to shoot triballs into the area on the side of the net
     Try to score all triballs that are grouped at the side of the net.
  7. Touch the Alliance color bar in order to get the win point. 


*/

/* Win Point Autonomous Function*/

void winPointMatchAuto(){


  /*Drop the intake*/

  hangTo(500);
  pros::delay(500);
  hangTo(-1350);
  pros::delay(500);

  /* Step 1 */

  stepOne();

  /*****/

  /* Step 2 */

  stepTwo();

  /*****/

  /* Step 3 */

  stepThree();

  /*****/

  /* Step 4 */

  stepFour();

  /*****/

  /* Step 5 */

  stepFive();

  /*****/

  /* Step 6 */

  stepSix();

  /*****/
}

/*********/

/* Sub Autonomous Functions */
void stepOne(){

  intake();
  chassis.pid_drive_set(136_in,DRIVE_SPEED,true);
  chassis.pid_wait();

  chassis.pid_turn_set(-60_deg,TURN_SPEED);
  hangTo(0);
  chassis.pid_wait();


  outtake();
  pros::delay(1000);
  stopIntake();



}

void stepTwo(){

  chassis.pid_turn_set(-45_deg,TURN_SPEED);
  chassis.pid_wait();

  wingDown();

  chassis.pid_drive_set(28_in,DRIVE_SPEED,true);
  chassis.pid_wait();

  chassis.pid_turn_set(-115_deg,TURN_SPEED/3);
  chassis.pid_wait();

  wingUp();
  pros::delay(250);


}

void stepThree(){


  hangTo(1000);

  chassis.pid_turn_set(-225_deg,TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-15_in,DRIVE_SPEED,true);
  chassis.pid_wait();

  // chassis.pid_turn_set(-270_deg,TURN_SPEED);
  // chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING,-270,TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-26_in,DRIVE_SPEED,true);
  chassis.pid_wait();

}

void stepFour(){

  chassis.pid_drive_set(18_in,DRIVE_SPEED,true);
  chassis.pid_wait();

  chassis.pid_turn_set(-180_deg,TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(40_in,DRIVE_SPEED,true);
  chassis.pid_wait();

  chassis.pid_turn_set(-110_deg,DRIVE_SPEED);
  chassis.pid_wait();

}

void stepFive(){
  // First ball

  ballOne();

  /*****/

  // Second ball

  ballTwo();
  
  /*****/

  // Third ball 

  ballThree();

  /*****/

  // Fourth ball

  ballFour();

  /*****/

  // Fifth ball

  // ballFive();

  /*****/

  stopIntake();

  // Net push
  
  netPush();

  /*****/


}

    void ballOne(){

      intake();

      chassis.pid_drive_set(60_in,DRIVE_SPEED,true);
      chassis.pid_wait();


      chassis.pid_turn_set(0_deg,TURN_SPEED);
      chassis.pid_wait();

      outtake();
      pros::delay(500);

      chassis.pid_drive_set(24_in,DRIVE_SPEED,true);
      chassis.pid_wait();
      
    }

    void ballTwo(){

      chassis.pid_drive_set(-26_in,DRIVE_SPEED,true);
      chassis.pid_wait();

      stopIntake();

      chassis.pid_turn_set(-90_deg,TURN_SPEED);
      chassis.pid_wait();
      
      intake();

      chassis.pid_drive_set(15_in,DRIVE_SPEED,true);
      chassis.pid_wait();

      chassis.pid_drive_set(-15_in,DRIVE_SPEED);
      chassis.pid_wait();

      chassis.pid_turn_set(0_deg,TURN_SPEED);
      chassis.pid_wait();

      outtake();
      pros::delay(500);
      
      chassis.pid_drive_set(28_in,DRIVE_SPEED,true);
      chassis.pid_wait();

    }

    void ballThree(){


      chassis.pid_drive_set(-26_in,DRIVE_SPEED);
      chassis.pid_wait();

      stopIntake();

      chassis.pid_turn_set(-165_deg,TURN_SPEED);
      chassis.pid_wait();

      intake();

      chassis.pid_drive_set(20_in,DRIVE_SPEED,true);
      chassis.pid_wait();

      pros::delay(100);

      chassis.pid_drive_set(-32_in,DRIVE_SPEED,true);
      chassis.pid_wait();

      chassis.pid_turn_set(0,TURN_SPEED);
      chassis.pid_wait();

      outtake();
      pros::delay(500);

      chassis.pid_drive_set(20_in,DRIVE_SPEED);
      chassis.pid_wait();
    }

    void ballFour(){

      chassis.pid_drive_set(-46_in,DRIVE_SPEED,true);
      chassis.pid_wait();

      stopIntake();

      chassis.pid_turn_set(-110_deg,TURN_SPEED);
      chassis.pid_wait();

      intake();

      chassis.pid_drive_set(15_in,DRIVE_SPEED,true);
      chassis.pid_wait();

      chassis.pid_drive_set(-15_in,DRIVE_SPEED,true);
      chassis.pid_wait();

      chassis.pid_turn_set(0_deg,TURN_SPEED);
      chassis.pid_wait();

      chassis.pid_drive_set(36_in,DRIVE_SPEED,true);
      chassis.pid_wait();
      
      outtake();
      pros::delay(500);

      chassis.pid_drive_set(14_in,DRIVE_SPEED);
      chassis.pid_wait();



    }

    void ballFive(){

      chassis.pid_drive_set(-24_in,DRIVE_SPEED,true);
      chassis.pid_wait();

      chassis.pid_turn_set(135_deg,TURN_SPEED);
      chassis.pid_wait();

      intake();

      chassis.pid_drive_set(36_in,DRIVE_SPEED,true);
      chassis.pid_wait();

      chassis.pid_drive_set(-36_in,DRIVE_SPEED,true);
      chassis.pid_wait();
      
      chassis.pid_turn_set(0_deg,TURN_SPEED);
      chassis.pid_wait();


      
      outtake();
      pros::delay(500);

      chassis.pid_drive_set(24_in,DRIVE_SPEED);
      chassis.pid_wait();

      stopIntake();

    }

    void netPush(){

      chassis.pid_drive_set(-18_in,DRIVE_SPEED,true);
      chassis.pid_wait();

      chassis.pid_turn_set(-180_deg,TURN_SPEED);
      chassis.pid_wait();

      wingHorizontal.set(true);
      pros::delay(100);

      chassis.pid_drive_set(-26_in,DRIVE_SPEED,true);
      chassis.pid_wait();

    }

void stepSix(){

  hangTo(-500);


  chassis.pid_drive_set(6_in,DRIVE_SPEED);
  chassis.pid_wait();

  wingHorizontal.set(false);

  chassis.pid_turn_set(-90_deg,TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-105_in,DRIVE_SPEED,true);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg,TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-60_in,DRIVE_SPEED,true);
  chassis.pid_wait();


}

/*********/


/*
  Elims Autonomous Steps!!!

    1. rush the other side with the preload and the triball that starts under the hang bar, unlaod the corner ball & score the three balls into the side of the net
    2. go to the center of the field
    3. score all 5 balls

*/

/* ELIMS Autonomous Function*/

void eliminationMatchAuto(){

  hangTo(500);
  pros::delay(500);
  hangTo(-1350);
  pros::delay(750);

  stepOne();
  stepTwo();
  stepThree();
  stepFour();
  eliminationStepFive();
  eliminationStepSix();
  



}

void eliminationStepFive(){
  // First ball

  ballOne();

  /*****/

  // Second ball

  ballTwo();
  
  /*****/

  // Third ball 

  ballThree();

  /*****/

  // Fourth ball

  ballFour();

  /*****/

  // Fifth ball

  ballFive();

  /*****/

  stopIntake();

  // Net push
  
  eliminationNetPush();

  /*****/
}

void eliminationStepSix(){

  chassis.pid_drive_set(48_in,DRIVE_SPEED,true);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg,DRIVE_SPEED);
  chassis.pid_wait();

}

void eliminationNetPush(){

  chassis.pid_drive_set(-18_in,DRIVE_SPEED,true);
  chassis.pid_wait();

  chassis.pid_turn_set(-180_deg,TURN_SPEED);
  chassis.pid_wait();

  wingHorizontal.set(true);
  pros::delay(100);

  chassis.pid_drive_set(-30_in,DRIVE_SPEED,true);
  chassis.pid_wait();

}




/*********/


/*
  SKILLS auto!!!!

  1. unfinished

*/

/* Skills autonomous functions*/

void skills(){

  // hangTo(500);
  // pros::delay(500);
  // hangTo(-1350);
  // pros::delay(750);
  /*Step 1*/
  /* Pushes Red Triball into net then positions itself for using wing */
  /*with speed unload*/
  chassis.pid_drive_set(-16_in,DRIVE_SPEED,true);
  chassis.pid_wait();
  chassis.pid_drive_set(30_in,DRIVE_SPEED/2,true);
  chassis.pid_wait();
  chassis.pid_turn_set(45_deg,DRIVE_SPEED/2);
  chassis.pid_wait();
  chassis.pid_drive_set(10_in,DRIVE_SPEED,true);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg,DRIVE_SPEED/2);
  chassis.pid_wait();
  chassis.pid_drive_set(16_in,DRIVE_SPEED,true);
  chassis.pid_wait();
  chassis.pid_turn_set(135_deg,DRIVE_SPEED/2);
  chassis.pid_wait();
  chassis.pid_drive_set(-8_in,DRIVE_SPEED,true);
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg,DRIVE_SPEED/2);
  chassis.pid_wait();
  chassis.pid_drive_set(-11_in,DRIVE_SPEED,true);
  chassis.pid_wait();
  chassis.pid_turn_set(225_deg,DRIVE_SPEED/2);
  chassis.pid_wait();
  chassis.pid_drive_set(6_in,DRIVE_SPEED,true);
  chassis.pid_wait();
  wingDown();
  /*Step 2*/
  /*Loop back and forth 10 times moving triballs*/
  pros::delay(500);
  for(int i = 0; i < 8; i++){
    chassis.pid_turn_set(260_deg,DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_turn_set(225_deg,DRIVE_SPEED);
    chassis.pid_wait();
    pros::delay(300);
  }
  /*Step 3*/
  /*Push triballs forward*/
  chassis.pid_turn_set(260_deg,DRIVE_SPEED/2);
  wingUp();
  chassis.pid_turn_set(225_deg,DRIVE_SPEED);
  chassis.pid_drive_set(-24_in,DRIVE_SPEED,true);
  chassis.pid_wait();
  chassis.pid_turn_set(270_deg,DRIVE_SPEED/2);
  pros::delay(300);
  chassis.pid_drive_set(-70_in,DRIVE_SPEED,true);
  chassis.pid_wait();
  /*Step 4*/
  /*Reposition Bot for next triball loop*/
  chassis.pid_drive_set(70_in,DRIVE_SPEED,true);
  chassis.pid_wait();
  pros::delay(300);
  chassis.pid_turn_set(225_deg,DRIVE_SPEED);
  chassis.pid_drive_set(24_in,DRIVE_SPEED,true);
  /*Step 5 Loop Triballs again*/
  wingDown();
  pros::delay(500);
  for(int i = 0; i < 8; i++){
    chassis.pid_turn_set(260_deg,DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_turn_set(225_deg,DRIVE_SPEED);
    chassis.pid_wait();
    pros::delay(300);
  }

  /*Step 6*/
  /*Push triballs forward*/
  chassis.pid_turn_set(260_deg,DRIVE_SPEED/2);
  wingUp();
  chassis.pid_turn_set(225_deg,DRIVE_SPEED);
  chassis.pid_drive_set(-24_in,DRIVE_SPEED,true);
  chassis.pid_wait();
  chassis.pid_turn_set(270_deg,DRIVE_SPEED/2);
  pros::delay(300);
  chassis.pid_drive_set(-70_in,DRIVE_SPEED,true);
  chassis.pid_wait();
}



/*********/







// . . .
// Subsystem Methods
// . . .

void wingDown(){
  wingPiston.set(1);
}

void wingUp(){
  wingPiston.set(0);
}

void intake(){
  intakeMotor=127;
}

void outtake(){
  intakeMotor=-127;
}

void stopIntake(){
  intakeMotor=0;
}


void hangTo(int units){
  hangMotor.move_absolute(units,127);
}

void hangUp(){
  hangMotor = 90;
}

void hangDown(){
  hangMotor = -90;
}

void hangStop(){
  hangMotor=0;
  hangMotor.brake();
}





// . . .
// Functions created to tune PID
// . . .
float valLeft = 0.0;
float valRight = 0.0;
float gyroVal = 0.0;

void tuneSwing(){

  chassis.pid_swing_set(ez::LEFT_SWING,90,SWING_SPEED);
  chassis.pid_wait();
  gyroVal = chassis.drive_imu_get();  

  

  printf("Degrees of turn: %lf\n",gyroVal);


  chassis.pid_swing_set(ez::LEFT_SWING,0,SWING_SPEED);
  chassis.pid_wait();
  gyroVal = chassis.drive_imu_get();  

  

  printf("Degrees of turn: %lf\n",gyroVal);

  

}

void tuneTurn(){

  chassis.pid_turn_set(90,TURN_SPEED);
  chassis.pid_wait();
  gyroVal = chassis.drive_imu_get();  

  

  printf("Degrees of turn: %lf\n",gyroVal);



  chassis.pid_turn_set(0,TURN_SPEED);
  chassis.pid_wait();

  gyroVal = chassis.drive_imu_get();  

  

  printf("Degrees of turn: %lf\n",gyroVal);

}

void tuneHeading(){


  chassis.pid_drive_set(24_in, DRIVE_SPEED,true);
  chassis.pid_wait();

  gyroVal = chassis.drive_imu_get();  

  

  printf("Degrees of turn: %lf\n",gyroVal);

  chassis.pid_drive_set(-24_in, DRIVE_SPEED);
  chassis.pid_wait();

  gyroVal = chassis.drive_imu_get();
  
  printf("Degrees of turn: %lf\n",gyroVal);



}


void tuneForwardBackward() { 
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches

  chassis.pid_drive_set(24_in, DRIVE_SPEED);
  chassis.pid_wait();
  // valLeft = chassis.drive_sensor_left()/  chassis.drive_tick_per_inch();
  // valRight = chassis.drive_sensor_right()/  chassis.drive_tick_per_inch();
    valLeft = chassis.drive_sensor_left();
  valRight = chassis.drive_sensor_right();

  

  printf("Distance Traveled: %lf\t%lf\n",valLeft,valRight);

  chassis.pid_drive_set(-24_in, DRIVE_SPEED);
  chassis.pid_wait();

  valLeft = chassis.drive_sensor_left();
  valRight = chassis.drive_sensor_right();
  
  printf("Distance Traveled: %lf\t%lf\n",valLeft,valRight);
  // chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  // chassis.pid_wait();
}