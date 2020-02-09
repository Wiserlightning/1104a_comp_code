#include "subsystem_headers\globals.hpp"
#include "subsystem_headers\angler.hpp"

using namespace okapi;

std::shared_ptr<AsyncVelocityController<double, double>> angler_controller = AsyncVelControllerBuilder()
    .withMotor(angler)
    .build();

void angler_position_vel_throttler(float angler_position, bool angler_control_async) {
    if (angler.getPosition() > angler_position - 5.0 && angler.getPosition() < angler_position + 5.0) {
        angler_controller->setTarget(std::copysign(200, angler_position));
    } else {
        angler_controller->setTarget(0);
    }

    if (angler_control_async == false) {
        while (!(angler.getPosition() > angler_position - 5 && angler.getPosition() < angler_position + 5)) {
            pros::delay(1);
        }
    }
}

void angler_op(void) {
    angler.setBrakeMode(BRKE_HOLD);
    if (master_ctrler.getAnalog(JOY_LY) > 0 || master_ctrler.getAnalog(JOY_LY) < 0) {
        angler_controller->setTarget(std::copysign(std::ceil((-0.018 * angler.getPosition()) + 60), master_ctrler.getAnalog(JOY_LY)));
    } else {
        angler_controller->setTarget(0);
    }
}

void angler_aut(float angler_distance, bool angler_async) {
    angler.setBrakeMode(BRKE_HOLD);
    angler_position_vel_throttler(angler_distance, angler_async);
}

void angler_aut_reset(void) {
    angler.tarePosition();
    angler_controller->reset();
}