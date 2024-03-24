#include "main.h"

pros::Motor grabberMotor(8,pros::E_MOTOR_GEARSET_18,true);

void setGrabberBrake(){
    grabberMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
}


void updateGrabber(){

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){
        grabberMotor = 127;
    }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
        grabberMotor = -127;
    }else{
        grabberMotor = 0; 
        grabberMotor.brake();
    }
    
}