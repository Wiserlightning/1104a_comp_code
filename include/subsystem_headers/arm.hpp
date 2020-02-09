#include "main.h"

#ifndef ARM_HPP
#define ARM_HPP


extern std::shared_ptr<okapi::AsyncVelocityController<double, double>> arm_controller;
extern void arm_position_vel_throttler(float arm_position, bool arm_control_async);

extern void arm_op(void);
extern void arm_aut(float arm_distance, bool arm_async);
extern void arm_aut_reset(void);


#endif