/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2021
 *
 * @file    car.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Car implementation.
 */

#include "car.h"

#include <utility>

Car::Car ( std::string make, std::string model ) : make_ { std::move( make ) }, model_ { std::move( model ) },
                                                   current_gear_ { Gear::P }
{
    // Intentionally empty; state initialized via initializer list
}

void Car::Start ( )
{
    std::cout << "Engine starting..." << std::endl;
}

void Car::Stop ( )
{
    std::cout << "Car is stopped..." << std::endl;
}

void Car::TurnOff ( )
{
    std::cout << "Engine is off..." << std::endl;
}

void Car::ChangeGear ( Gear gear )
{
    SetCurrentGear( gear );
}

void Car::Drive ( )
{
    Gear gear = GetCurrentGear( );
    if ( gear != Gear::P && gear != Gear::N )
    {
        std::cout << "Car is currently driving..." << std::endl;
    }
}

void Car::Brake ( )
{
    std::cout << "Car is braking..." << std::endl;
}

void Car::Turn ( Direction direction )
{
    std::cout << "Turning ";
    switch ( direction )
    {
    case Direction::Left:
        std::cout << "left";
        break;
    case Direction::Right:
        std::cout << "right";
    }
    std::cout << "..." << std::endl;
}

std::string Car::GetMake ( ) const
{
    return make_;
}

std::string Car::GetModel ( ) const
{
    return model_;
}

Gear Car::GetCurrentGear ( ) const
{
    return current_gear_;
}

void Car::SetCurrentGear ( Gear gear )
{
    current_gear_ = gear;
}