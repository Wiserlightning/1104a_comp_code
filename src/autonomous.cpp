#include "subsystem_headers\angler.hpp"
#include "subsystem_headers\arm.hpp"
#include "subsystem_headers\drive.hpp"
#include "subsystem_headers\intake.hpp"
#include "subsystem_headers\globals.hpp"

//GLOBALS AND CONSTANTS
drive_functions drive_ctrl;
arm_functions arm_ctrl;
angler_functions angler_ctrl;
intake_functions intake_ctrl;

//HELPER FUNCTIONS
void flip_out(void) {
    arm_ctrl.arm_aut(1500.0, false);
    arm_ctrl.arm_aut(0.0, false);
}

//MAIN FUNCTIONS
void red(void) {

}

void blue(void) {

}

void one_point(void) {
    drive_ctrl.drive_aut("ONE_POINT", false, false, false);
    flip_out();
}

void skills(void) {

}

void aut_test(void) {

}

void autonomous(void) {
    if (sel_auton == "RED") {
        red();
    } else if (sel_auton == "BLUE") {
        blue();
    } else if (sel_auton == "ONE_POINT") {
        one_point();
    } else if (sel_auton == "SKILLS") {
        skills();
    } else if (sel_auton == "AUT_TEST") {
        aut_test();
    }
}