//Start of header guard.
#include "main.h"

#ifndef DRIVE_HPP
#define DRIVE_HPP

extern std::shared_ptr<okapi::ChassisController> drive_chassis;
extern std::shared_ptr<okapi::AsyncMotionProfileController> chassis_controller;
extern void drive_op(void);
extern void drive_aut(std::string drive_path_id, bool drive_backwards, bool drive_mirrored, bool drive_async);
extern void drive_aut_reset(void);

//End of header gaurd.
#endif