#include "main.h"

ez::Piston wingPiston('A');

void updateWing(){

    wingPiston.button_toggle(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y));

}