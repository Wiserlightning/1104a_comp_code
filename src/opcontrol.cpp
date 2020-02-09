#include "subsystem_headers\angler.hpp"
#include "subsystem_headers\arm.hpp"
#include "subsystem_headers\drive.hpp"
#include "subsystem_headers\intake.hpp"
#include "subsystem_headers\globals.hpp"

void opcontrol(void) {
    while (true) {
        drive_op();
        arm_op();
        angler_op();
        intake_op();
        pros::delay(5);
    }
}