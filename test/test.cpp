/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2021
 *
 * @file     hw01-test.cpp
 * @authors  Jim Daehn <jdaehn@missouristate.edu>
 * @brief    HW01 Unit test implementation -- DO NOT MODIFY THIS FILE!!!
 */

#define CATCH_CONFIG_MAIN  // Tell Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include "csc232.h"

SCENARIO( "Base case of Ackermann function (m = 0)", "[acker]" )
{
    GIVEN( "Initial values of m == 0 and n == 0" )
    {
        int m{ 0 };
        int n{ 0 };

        WHEN( "We compute the value of the Ackermann function acker(0, 0)" )
        {
            REQUIRE( m == 0 );
            REQUIRE( n == 0 );

            int actual{ csc232::acker( m, n ) };
            int expected{ 1 };

            THEN( "We obtain the desired result" )
            {
                REQUIRE( actual == expected );
            }
        }
    }

    GIVEN( "Initial value of m == 0 and n == 1" )
    {
        int m{ 0 };
        int n{ 1 };
        
        WHEN( "We compute the value of the Ackermann function acker(0, 1)" )
        {
            REQUIRE( m == 0 );
            REQUIRE( n == 1 );

            int actual{ csc232::acker( m, n ) };
            int expected{ 2 };

            THEN( "We obtain the desired result" )
            {
                REQUIRE( actual == expected );
            }
        }
    }

    
    GIVEN( "Initial value of m == 0 and n == 2")
    {
        int m{ 0 };
        int n{ 2 };
        
        WHEN( "We compute the value of the Ackermann function acker( 0, 2)" )
        {
            REQUIRE( m == 0 );
            REQUIRE( n == 2 );

            int actual{ csc232::acker( m, n ) };
            int expected{ 3 };

            THEN( "We obtain the desired result" )
            {
                REQUIRE( actual == expected );
            }
        }
    }
}

SCENARIO( "Ackermann function computes values given in Exercise 26", "[acker]" )
{
    GIVEN( "The values presented in Exercise 26" )
    {
        int m{ 1 };
        int n{ 2 };

        WHEN( "We compute the value of the Ackermann function aker(1, 2)" )
        {
            REQUIRE( m == 1 );
            REQUIRE( n == 2 );

            int actual{ csc232::acker( m, n ) };
            int expected{ 4 };

            THEN( "We obtain the desired result")
            {
                REQUIRE( actual == expected );
            }
        }
    }
}
