#include "main.h"

#ifndef ANGLER_HPP
#define ANGLER_HPP


extern std::shared_ptr<okapi::AsyncVelocityController<double, double>> angler_controller;

extern void angler_position_vel_throttler(float angler_position, bool angler_control_async);
extern void angler_op(void);
extern void angler_aut(float angler_distance, bool angler_async);
extern void angler_aut_reset(void);

#endif