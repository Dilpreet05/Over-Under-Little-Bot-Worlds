#pragma once

#include "EZ-Template/drive/drive.hpp"

extern Drive chassis;

void tuneForwardBackward();
void tuneHeading();
void tuneTurn();
void tuneSwing();


void default_constants();


void winPointMatchAuto();
    void stepOne();
    void stepTwo();
    void stepThree();
    void stepFour();
    void stepFive();
        void ballOne();
        void ballTwo();
        void ballThree();
        void ballFour();
        void ballFive();
        void netPush();
    void stepSix();

void eliminationMatchAuto();
    void eliminationStepFive();
        void eliminationNetPush();
    void eliminationStepSix();
    



// void skillsCycle();

void wingUp();
void wingDown();
void intake();
void outtake();
void stopIntake();
void hangTo(int units);
void hangUp();
void hangDown();
void hangStop();

