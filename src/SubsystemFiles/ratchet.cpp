#include "main.h"

bool isEngaged = false;
pros::ADIDigitalOut ratchetPiston('A');



void updateRatchet(){

    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)){
        isEngaged=!isEngaged;
        ratchetPiston.set_value(isEngaged);
    }

}

