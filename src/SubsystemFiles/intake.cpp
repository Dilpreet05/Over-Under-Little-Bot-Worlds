#include "main.h"

pros::Motor intakeMotor(20,pros::E_MOTOR_GEARSET_06,true);


void setIntakeBrake(){
        intakeMotor.set_brake_mode(MOTOR_BRAKE_COAST);
}



void spinIntake(){

        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){

                intakeMotor = -127;
                
        }else if(!master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){

                intakeMotor = 127;

        }else{
                intakeMotor.brake();
        }

        pros::delay(20);

}