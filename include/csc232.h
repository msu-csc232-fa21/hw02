/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2021
 *
 * @file    csc232.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Macros, libraries and definitions for use in csc232 assignments.
 */

#ifndef CSC232_COMMON_H__
#define CSC232_COMMON_H__

#define FALSE 0
#define TRUE 1
#define EXECUTE_BLOCK FALSE
#define FINISHED TRUE

#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdexcept>
#include <utility>
#include <vector>
#include "expanded_templates.h"

/** Common iostream objects */
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

/** Common iomanip objects */
using std::setw;
using std::right;
using std::left;
using std::setprecision;

/**
 * @brief Common namespace for CSC232 identifiers.
 */
namespace csc232
{
    /**
     * @brief Generate a quasi-random UUID.
     * @return A string representation of a quasi-random UUID.
     */
    inline std::string GenerateUuid ( )
    {
        static std::random_device random_device;
        static std::mt19937 random_number_generator( random_device( ) );

        std::uniform_int_distribution<int> dist( 0, 15 );

        const char* uuid_alphabet = "0123456789abcdef";
        const bool dash[] = { false, false, false, false, true, false, true, false, true, false, true, false, false,
                              false,
                              false, false };

        std::string uuid;
        for ( bool dash_location : dash )
        {
            if ( dash_location ) uuid += "-";
            uuid += uuid_alphabet[ dist( random_number_generator ) ];
            uuid += uuid_alphabet[ dist( random_number_generator ) ];
        }
        return uuid;
    }
}

#endif // CSC232_COMMON_H__
