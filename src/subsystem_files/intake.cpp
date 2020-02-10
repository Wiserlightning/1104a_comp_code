#include "subsystem_headers\globals.hpp"
#include "subsystem_headers\intake.hpp"

using namespace okapi;


std::shared_ptr<AsyncVelocityController<double, double>> intake_controller = AsyncVelControllerBuilder()
    .withMotor(intake_grp)
    .build();

void intake_op(void) {
    intake_grp.setBrakeMode(BRKE_HOLD);
    if (master_ctrler.getDigital(BUT_R1)) {
        intake_controller->setTarget(200);
    } else if (master_ctrler.getDigital(BUT_L2)) {
        if (arm.getPosition() > 1200.0) {
            intake_controller->setTarget(-40);
        } else {
            intake_controller->setTarget(-200);
        }
    } else {
        intake_controller->setTarget(0);
    }
}

void intake_aut(int intake_velocity) {
    intake_grp.setBrakeMode(BRKE_HOLD);
    intake_controller->setTarget(intake_velocity);
}