#include "main.h"

#ifndef INTAKE_HPP
#define INTAKE_HPP

extern class intake_functions {
    private:
        std::shared_ptr<okapi::AsyncVelocityController<double, double>> intake_controller;
    public:
        void intake_op(void);
        void intake_aut(int intake_velocity);
};

#endif