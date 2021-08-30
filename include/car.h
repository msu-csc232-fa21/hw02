/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2021
 *
 * @file    car.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Car specification.
 */

#ifndef CSC232_CAR_H__
#define CSC232_CAR_H__

#include <iostream> // needed for std::cout and std::endl
#include <string>   // needed for std::string

enum class Gear
{
    P, R, N, D
};

enum class Direction
{
    Left, Right
};

class Car
{
public:
    Car ( std::string make, std::string model );
    void Start ( );
    void Stop ( );
    void TurnOff ( );
    void ChangeGear ( Gear gear );
    void Drive ( );
    void Brake ( );
    void Turn ( Direction direction );
    std::string GetMake ( ) const;
    std::string GetModel ( ) const;
    Gear GetCurrentGear ( ) const;
    void SetCurrentGear ( Gear gear );
private:
    std::string make_;
    std::string model_;
    Gear current_gear_;
};
#endif // CSC232_CAR_H__
