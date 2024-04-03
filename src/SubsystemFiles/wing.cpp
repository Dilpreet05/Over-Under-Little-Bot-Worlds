#include "main.h"

ez::Piston wingPiston('A');
ez::Piston wingHorizontal('H');

void updateWing(){

    wingPiston.button_toggle(master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT));
    wingHorizontal.button_toggle(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y));

}