#include "main.h"

#ifndef INTAKE_HPP
#define INTAKE_HPP

extern std::shared_ptr<okapi::AsyncVelocityController<double, double>> intake_controller;

extern void intake_op(void);
extern void intake_aut(int intake_velocity);

#endif