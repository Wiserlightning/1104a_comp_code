//Include necessary headers.
#include "subsystem_headers\globals.hpp"
#include "subsystem_headers\drive.hpp"

//Declare the use of the namespace "okapi"
using namespace okapi;

//Declare the source of the external class in "drive.hpp"
class drive_functions {
    private:
        //Create a ChassisController with the wheel motors, 4 inch wheels, a wheelbase of 10 inches, and green cartridges.
        std::shared_ptr<ChassisController> drive_chassis = ChassisControllerBuilder()
            .withMotors({DRV_L_FRONT, DRV_L_BACK}, {DRV_R_FRONT, DRV_L_BACK})
            .withDimensions(GRN_CART, {{4_in, 10_in}, imev5GreenTPR})
            .build();

        //Create an AsyncMotionProfileController with "drive_chassis" as the output chassis, with limits of 1.0 m/s, 2.0 m/s/s and 10.0 m/s/s/s.
        std::shared_ptr<AsyncMotionProfileController> chassis_controller = AsyncMotionProfileControllerBuilder()
            .withOutput(drive_chassis)
            .withLimits({1.0, 2.0, 10.0})
            .buildMotionProfileController();

    public:
        //Operator control for drive.
        void drive_op(void) {
            //If the drive mode selected in initialization is "ARCADE"
            if (selected_drive_mode == "ARCADE") {
                //Control the chassis using arcade with a deadband of 2.5.
                drive_chassis->getModel()->arcade(
                    master_ctrler.getAnalog(JOY_LY),
                    master_ctrler.getAnalog(JOY_LX),
                    2.5
                );
            //Otherwise if the mode is "TANK"
            } else if (selected_drive_mode == "TANK") {
                //Control the chassis using tank with a deadband of 2.5.
                drive_chassis->getModel()->tank(
                    master_ctrler.getAnalog(JOY_LY),
                    master_ctrler.getAnalog(JOY_RY),
                    2.5
                );
            }
        }

        //Autonomous control for drive.
        void drive_aut(std::string drive_path_id, bool drive_backwards, bool drive_mirrored, bool drive_async) {
            //Set the target path, if it's backwards, and if it's mirrored.
            chassis_controller->setTarget(drive_path_id, drive_backwards, drive_mirrored);
            //If we don't want to follow the path asynchronously
            if (drive_async == false) {
                //Wait for the controller to be settled.
                chassis_controller->waitUntilSettled();
            }
        }
}; 
