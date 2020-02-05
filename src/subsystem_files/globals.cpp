#include "subsystem_headers\globals.hpp"

using namespace okapi;

//Initialization Variables
std::vector<std::string> drive_modes = {
    "ARCADE",
    "TANK"
};
std::string selected_drive_mode;

//Hardware Declarations
Controller master_ctrler(ControllerId::master);

Motor intake_lf(11, false, GRN_CART, ENC_TIC);
Motor intake_rt(1, true, GRN_CART, ENC_TIC);
MotorGroup intake_grp({intake_lf, intake_rt});

Motor angler(8, true, RED_CART, ENC_TIC);
Motor arm(2, false, GRN_CART, ENC_TIC);