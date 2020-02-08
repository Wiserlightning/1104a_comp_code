#include "subsystem_headers\angler.hpp"
#include "subsystem_headers\arm.hpp"
#include "subsystem_headers\drive.hpp"
#include "subsystem_headers\intake.hpp"
#include "subsystem_headers\globals.hpp"

drive_functions drive;
arm_functions arm_ctrl;
angler_functions angler_ctrl;
unsigned current_object;


void pre_init_reset(void) {
    pros::lcd::initialize();
    pros::delay(1000);
    pros::lcd::print(0, "SETTING ZEROES...");
    arm.moveVelocity(-200);
    angler.moveVelocity(-200);

    drive.drive_aut_reset();
    arm_ctrl.arm_aut_reset();
    angler_ctrl.angler_aut_reset();
    pros::delay(2000);
    pros::lcd::print(0, "PRE-INIT COMPLETE");
    pros::delay(1000);
}

void auton_selection(void) {
    current_object = 0;
    pros::lcd::print(0, "AUTON SELECTION");
    pros::lcd::print(1, "[LEFT] and [RIGHT] to scroll.");
    pros::lcd::print(2, "[CENTER] to select.");

    while (true) {
        pros::lcd::print(3, "SELECTED AUTON: %s", autons.at(current_object));
        if (pros::lcd::read_buttons() == LCD_BTN_LEFT) {
            if (current_object == 0) {
                pros::lcd::print(4, "ERROR: UNDERFLOW ERR");
                pros::delay(1000);
                pros::lcd::clear_line(4);
            } else {
                current_object--;
                pros::delay(500);
            }
        } else if (pros::lcd::read_buttons() == LCD_BTN_RIGHT) {
            if (current_object == autons_vector_size) {
                pros::lcd::print(4, "ERROR: OVERFLOW ERR");
                pros::delay(1000);
                pros::lcd::clear_line(4);
            } else {
                current_object++;
                pros::delay(500);
            }
        } else if (pros::lcd::read_buttons() == LCD_BTN_CENTER) {
            sel_auton = autons.at(current_object);
            pros::lcd::clear_line(3);
            pros::lcd::print(3, "AUTON SELECTED");
            pros::delay(500);
            pros::lcd::clear_line(3);
            pros::lcd::clear_line(4);
            break;
        }
        pros::delay(5);
    }

    pros::lcd::print(4, "FINAL AUTON: %s", sel_auton);
    pros::delay(2000);
    pros::lcd::clear();
    pros::lcd::shutdown();
}

void initialize(void) {
    pre_init_reset();
    auton_selection();
}