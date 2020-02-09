#include "subsystem_headers\globals.hpp"
#include "subsystem_headers\arm.hpp"

using namespace okapi;

unsigned arm_pos_sel;
unsigned arm_prev_pos;

std::shared_ptr<AsyncVelocityController<double, double>> arm_controller = AsyncVelControllerBuilder()
    .withMotor(arm)
    .build();

void arm_position_vel_throttler(float arm_position, bool arm_control_async) {
    if (!(arm.getPosition() > arm_position - 5 && arm.getPosition() < arm_position + 5)) {
        arm_controller->setTarget(std::copysign(200, arm_position - arm_prev_pos));
    } else {
        arm_controller->setTarget(0);
        arm_pos_sel = 0;
        arm_prev_pos = arm_position;
    }

    if (arm_control_async == false) {
        while (!(arm.getPosition() > arm_position - 5 && arm.getPosition() < arm_position + 5)) {
            pros::delay(1);
        }
    }
}

void arm_op(void) {
    arm.setBrakeMode(BRKE_HOLD);
    if (master_ctrler.getDigital(BUT_L1) || master_ctrler.getDigital(BUT_L2)) {
        arm_controller->setTarget(200 * (master_ctrler.getDigital(BUT_L1) - master_ctrler.getDigital(BUT_L2)));
        arm_pos_sel = 0;
    } else if (master_ctrler.getDigital(BUT_UP)) {
        arm_pos_sel = 1;
    } else if (master_ctrler.getDigital(BUT_RGT)) {
        arm_pos_sel = 2;
    } else {
        arm_controller->setTarget(0);
    }

    if (arm_pos_sel = 1) {
        arm_position_vel_throttler(ARM_TOWER_1, true);
    } else if (arm_pos_sel = 2) {
        arm_position_vel_throttler(ARM_TOWER_2, true);
    }
}

void arm_aut(float arm_distance, bool arm_async) {
    arm.setBrakeMode(BRKE_HOLD);
    arm_position_vel_throttler(arm_distance, arm_async);
}

void arm_aut_reset(void) {
    arm.tarePosition();
    arm_controller.reset();
}