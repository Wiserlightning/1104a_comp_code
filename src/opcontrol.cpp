#include "subsystem_headers\angler.hpp"
#include "subsystem_headers\arm.hpp"
#include "subsystem_headers\drive.hpp"
#include "subsystem_headers\intake.hpp"
#include "subsystem_headers\globals.hpp"

drive_functions drive_ctrl;
arm_functions arm_ctrl;
angler_functions angler_ctrl;
intake_functions intake_ctrl;

void opcontrol(void) {
    while (true) {
        drive_ctrl.drive_op();
        arm_ctrl.arm_op();
        angler_ctrl.angler_op();
        intake_ctrl.intake_op();
        pros::delay(5);
    }
}