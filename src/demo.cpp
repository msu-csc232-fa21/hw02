/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2021
 *
 * @file    demo.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Entry point of hw01-demo target.
 */

#include "car.h"

int main ( )
{
    std::cout << "Hello, Demo!" << std::endl;

    Car car("Dodge", "Ram 1500");
    std::cout << "Taking my " << car.GetMake() << " " << car.GetModel() << " out for a ride..." << std::endl;
    car.Start( );
    car.ChangeGear( Gear::D );
    car.Drive( );
    car.Brake( );
    car.Stop( );
    car.Turn( Direction::Left );
    car.Drive( );
    car.Brake( );
    car.Stop( );
    car.ChangeGear( Gear::P );
    car.TurnOff( );

    return EXIT_SUCCESS;
}
