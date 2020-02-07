#include "main.h"

#ifndef GLOBALS_HPP
#define GLOBALS_HPP

//Include Necessary Libraries
#include <vector>

//Important Constants
#define ARM_TOWER_1 1000.0
#define ARM_TOWER_2 2000.0
#define TOWER_STACK 2500.0

//Initialization Variables
extern std::vector<std::string> drive_modes;
extern std::string selected_drive_mode;

//Hardware Enums. and Misc.
#define GRN_CART okapi::Motor::gearset::green
#define RED_CART okapi::Motor::gearset::red

#define BRKE_COAST okapi::Motor::brakeMode::coast
#define BRKE_HOLD okapi::Motor::brakeMode::hold

#define ENC_TIC okapi::Motor::encoderUnits::counts

#define JOY_LX okapi::ControllerAnalog::leftX
#define JOY_LY okapi::ControllerAnalog::leftY
#define JOY_RX okapi::ControllerAnalog::rightX
#define JOY_RY okapi::ControllerAnalog::rightY
#define BUT_L1 okapi::ControllerDigital::L1
#define BUT_L2 okapi::ControllerDigital::L2
#define BUT_R1 okapi::ControllerDigital::R1 
#define BUT_R2 okapi::ControllerDigital::R2
#define BUT_UP okapi::ControllerDigital::up
#define BUT_DWN okapi::ControllerDigital::down
#define BUT_LFT okapi::ControllerDigital::left
#define BUT_RGT okapi::ControllerDigital::right
#define BUT_A okapi::ControllerDigital::A
#define BUT_B okapi::ControllerDigital::B
#define BUT_X okapi::ControllerDigital::X
#define BUT_Y okapi::ControllerDigital::Y

//Hardware Prototypes
#define DRV_L_FRONT 19
#define DRV_L_BACK 20
#define DRV_R_FRONT -9
#define DRV_R_BACK -10

extern okapi::Controller master_ctrler;

extern okapi::Motor intake_lf;
extern okapi::Motor intake_rt;
extern okapi::MotorGroup intake_grp;

extern okapi::Motor angler;
extern okapi::Motor arm;

#endif