#include "subsystem_headers\globals.hpp"
#include "subsystem_headers\arm.hpp"

using namespace okapi;

class arm_functions {
    private:
        std::shared_ptr<AsyncVelocityController<double, double>> arm_controller = AsyncVelControllerBuilder()
            .withMotor(arm)
            .build();
        
        void arm_position_vel_throttler(float arm_position, bool arm_control_async) {
            if (arm.getPosition() > arm_position - 5 && arm.getPosition() < arm_position + 5) {
                arm_controller->setTarget(std::copysign(200, arm_position));
            } else {
                arm_controller->setTarget(0);
            }

            if (arm_control_async == false) {
                arm_controller->waitUntilSettled();
            }
        }
    
    public:
        void arm_op(void) {
            arm.setBrakeMode(BRKE_HOLD);
            if (master_ctrler.getDigital(BUT_L1) || master_ctrler.getDigital(BUT_L2)) {
                arm_controller->setTarget(200 * (master_ctrler.getDigital(BUT_L1) - master_ctrler.getDigital(BUT_L2)));
            } else if (master_ctrler.getDigital(BUT_UP)) {
                arm_position_vel_throttler(ARM_TOWER_1, true);
            } else if (master_ctrler.getDigital(BUT_RGT)) {
                arm_position_vel_throttler(ARM_TOWER_2, true);
            } else {
                arm_controller->setTarget(0);
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
};