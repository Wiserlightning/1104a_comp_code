#include "main.h"

#ifndef ANGLER_HPP
#define ANGLER_HPP

extern class angler_functions {
    private:
        std::shared_ptr<okapi::AsyncVelocityController<double, double>> angler_controller;
        void angler_position_vel_throttler(float angler_position, bool angler_control_async);
    public:
        void angler_op(void);
        void angler_aut(float angler_distance, bool angler_async);
        void angler_aut_reset(void);
};

#endif