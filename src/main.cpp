/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2021
 *
 * @file    main.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Entry point of hw01 target.
 */

#include "csc232.h"
#include "plain-box.h"
#include "toy-box.h"
#include "magic-box.h"

int main ( )
{
    cout << "Hello, Main!" << endl;
    PlainBox<int> plainBox { };
    cout << "plainBox.GetItem() = " << plainBox.GetItem( ) << endl;
    plainBox.SetItem( 5 );
    cout << "plainBox.SetItem(5);" << endl;
    cout << "plainBox.GetItem() = " << plainBox.GetItem( ) << endl;

    ToyBox<std::string> blackToyBox { "Black Box" };
    ToyBox<std::string> redToyBox { "Red Box", RED };
    ToyBox<std::string> emptyGreenBox { GREEN };

    cout << "blackToyBox.GetItem() = " << blackToyBox.GetItem( ) << endl;
    cout << "redToyBox.GetItem() = " << redToyBox.GetItem( ) << endl;
    cout << "emptyGreenBox.GetItem() = "
         << ( emptyGreenBox.GetItem( ).empty( ) ? "***empty***" : emptyGreenBox.GetItem( ) ) << endl;

    MagicBox<double> dMagicBox{42.0};
    cout << "dMagicBox.GetItem() = " << dMagicBox.GetItem( ) << endl;
    cout << "dMagicBox.SetItem(3);" << endl;
    cout << "dMagicBox.GetItem() = " << dMagicBox.GetItem() << endl;

    return 0;
}
