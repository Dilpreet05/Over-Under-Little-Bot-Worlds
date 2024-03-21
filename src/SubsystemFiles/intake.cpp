#include "main.h"

pros::Motor intakeMotor(9,pros::E_MOTOR_GEARSET_18,false);

void setIntakeBrake(){

        intakeMotor.set_brake_mode(MOTOR_BRAKE_COAST);

}

void updateIntake(){

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){

        intakeMotor =127;

    }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){

        intakeMotor =-127;

    }else{

        intakeMotor =0;
        intakeMotor .brake();

    }

}