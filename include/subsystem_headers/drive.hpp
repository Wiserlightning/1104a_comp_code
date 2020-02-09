//Start of header guard.
#include "main.h"

#ifndef DRIVE_HPP
#define DRIVE_HPP

//Declare a class "drive_hpp" with source outside of current scope.
extern class drive_functions {
    //Declare private members of the class.
    private:
        std::shared_ptr<okapi::ChassisController> drive_chassis;
    //Declare public functions.
    public:
        std::shared_ptr<okapi::AsyncMotionProfileController> chassis_controller;
        void drive_op(void);
        void drive_aut(std::string drive_path_id, bool drive_backwards, bool drive_mirrored, bool drive_async);
        void drive_aut_reset(void);
};

//End of header gaurd.
#endif