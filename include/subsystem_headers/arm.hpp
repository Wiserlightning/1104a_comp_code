#include "main.h"

#ifndef ARM_HPP
#define ARM_HPP

extern class arm_functions {
    private:
        std::shared_ptr<okapi::AsyncVelocityController<double, double>> arm_controller;
        void arm_position_vel_throttler(float arm_position, bool arm_control_async);
    public:
        void arm_op(void);
        void arm_aut(float arm_distance, bool arm_async);
        void arm_aut_reset(void);
};

#endif