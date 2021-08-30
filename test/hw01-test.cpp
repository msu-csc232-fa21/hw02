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

#include "plain-box.h"
#include "toy-box.h"
#include "magic-box.h"

SCENARIO( "PlainBox objects store modifiable items", "[PlainBox]" )
{
    GIVEN( "a Default PlainBox" )
    {
        BoxInterface<std::string>* emptyPlainBoxPtr = new PlainBox<std::string> { };
        REQUIRE( emptyPlainBoxPtr != nullptr );
        REQUIRE( emptyPlainBoxPtr->GetItem( ).empty( ) );

        WHEN( "we set an item in the plain box" )
        {
            std::string anItem { "An Item" };
            emptyPlainBoxPtr->SetItem( anItem );

            THEN( "the plain box is no longer empty" )
            {
                REQUIRE_FALSE( emptyPlainBoxPtr->GetItem( ).empty( ) );
            }

            AND_WHEN( "we retrieve the box contents, it's the item we set there" )
            {
                REQUIRE( emptyPlainBoxPtr->GetItem( ) == anItem );
            }
        }
    }

    GIVEN( "an initialized PlainBox" )
    {
        std::string initialItem { "An Item" };
        BoxInterface<std::string>* initializedPlainBoxPtr = new PlainBox<std::string> { initialItem };
        REQUIRE( initializedPlainBoxPtr != nullptr );
        REQUIRE( initializedPlainBoxPtr->GetItem( ) == initialItem );

        WHEN( "we set an item in the initialized plain box" )
        {
            std::string aDifferentItem { "A Different Item" };
            initializedPlainBoxPtr->SetItem( aDifferentItem );
            REQUIRE( initialItem != aDifferentItem );

            THEN( "the initialized plain box contains a different item" )
            {
                REQUIRE( initializedPlainBoxPtr->GetItem( ) == aDifferentItem );
            }
        }
    }
}

SCENARIO( "ToyBox objects store modifiable items in a box with color", "[ToyBox]" )
{
    GIVEN( "a default ToyBox" )
    {
        BoxInterface<std::string>* genericToyBoxPtr = new ToyBox<std::string> { };
        REQUIRE( genericToyBoxPtr != nullptr );
        WHEN( "we inspect the contents of the toy box" )
        {
            std::string contents = genericToyBoxPtr->GetItem( );

            THEN( "the box is initially empty" )
            {
                REQUIRE( contents.empty( ) );
                AND_WHEN( "we retrieve the box color" )
                {
                    auto toyBoxPtr = dynamic_cast<ToyBox<std::string>*>(genericToyBoxPtr);
                    Color boxColor = toyBoxPtr->GetColor( );
                    THEN( "it is found to be BLACK" )
                    {
                        REQUIRE( boxColor == BLACK );
                    }
                }
            }
        }

        WHEN( "we set something in the toy box" )
        {
            std::string anItem { "An item" };
            genericToyBoxPtr->SetItem( anItem );
            THEN( "the item is found in the box when we get it" )
            {
                std::string storedItem = genericToyBoxPtr->GetItem( );
                REQUIRE( storedItem == anItem );
                AND_WHEN( "we inspect the color" )
                {
                    auto toyBoxPtr = dynamic_cast<ToyBox<std::string>*>(genericToyBoxPtr);
                    Color boxColor = toyBoxPtr->GetColor( );
                    THEN( "it is still found to be BLACK" )
                    {
                        REQUIRE( boxColor == BLACK );
                    }
                }
            }
        }
    }

    GIVEN( "an empty ToyBox that is initially RED" )
    {
        BoxInterface<std::string>* redToyBoxPtr = new ToyBox<std::string> { RED };
        REQUIRE( redToyBoxPtr != nullptr );
        WHEN( "we inspect the contents of the toy box" )
        {
            std::string contents = redToyBoxPtr->GetItem( );
            THEN( "the box is initially empty" )
            {
                REQUIRE( contents.empty( ) );
                AND_WHEN( "we retrieve the box color" )
                {
                    auto toyBoxPtr = dynamic_cast<ToyBox<std::string>*>(redToyBoxPtr);
                    Color boxColor = toyBoxPtr->GetColor( );
                    THEN( "it is found to be RED" )
                    {
                        REQUIRE( boxColor == RED );
                    }
                }
            }
        }

        WHEN( "we set something in the toy box" )
        {
            std::string anItem { "An item" };
            redToyBoxPtr->SetItem( anItem );
            THEN( "the item is found in the box when we get it" )
            {
                std::string storedItem = redToyBoxPtr->GetItem( );
                REQUIRE( storedItem == anItem );
                AND_WHEN( "we inspect the color" )
                {
                    auto toyBoxPtr = dynamic_cast<ToyBox<std::string>*>(redToyBoxPtr);
                    Color boxColor = toyBoxPtr->GetColor( );
                    THEN( "it is still found to be RED" )
                    {
                        REQUIRE( boxColor == RED );
                    }
                }
            }
        }
    }

    GIVEN( "an initialized ToyBox that is initially GREEN" )
    {
        std::string initialItem { "Initial item" };
        BoxInterface<std::string>* greenInitializedToyBox = new ToyBox<std::string> { initialItem, GREEN };
        REQUIRE( greenInitializedToyBox != nullptr );
        WHEN( "we inspect the contents of the toy box" )
        {
            std::string contents = greenInitializedToyBox->GetItem( );
            THEN( "the box is initially non-empty" )
            {
                REQUIRE_FALSE( contents.empty( ) );
                AND_WHEN( "we retrieve the box color" )
                {
                    auto toyBoxPtr = dynamic_cast<ToyBox<std::string>*>(greenInitializedToyBox);
                    Color boxColor = toyBoxPtr->GetColor( );
                    THEN( "it is found to be GREEN" )
                    {
                        REQUIRE( boxColor == GREEN );
                    }
                }
            }
        }

        WHEN( "we set something in the toy box" )
        {
            std::string anItem { "A different item" };
            greenInitializedToyBox->SetItem( anItem );
            THEN( "the item is found in the box when we get it" )
            {
                std::string storedItem = greenInitializedToyBox->GetItem( );
                REQUIRE( storedItem == anItem );
                AND_WHEN( "we inspect the color" )
                {
                    auto toyBoxPtr = dynamic_cast<ToyBox<std::string>*>(greenInitializedToyBox);
                    Color boxColor = toyBoxPtr->GetColor( );
                    THEN( "it is still found to be GREEN" )
                    {
                        REQUIRE( boxColor == GREEN );
                    }
                }
            }
        }
    }
}

SCENARIO( "MagicBox objects store items that never change", "[MagicBox]" )
{
    GIVEN( "a default MagicBox" )
    {
        BoxInterface<std::string>* genericMagicBox = new MagicBox<std::string> { };
        REQUIRE( genericMagicBox != nullptr );
        WHEN( "we inspect the contents of the toy box" )
        {
            std::string contents = genericMagicBox->GetItem( );

            THEN( "the box is initially empty" )
            {
                REQUIRE( contents.empty( ) );
            }

            AND_WHEN( "we put something in the box" )
            {
                std::string magicItem { "I'm magical!" };
                genericMagicBox->SetItem( magicItem );
                THEN( "the item is found in the box when we get it" )
                {
                    std::string storedItem = genericMagicBox->GetItem( );
                    REQUIRE( storedItem == magicItem );
                }

                AND_WHEN( "another item is put in the box" )
                {
                    std::string anotherItem { "Another item" };
                    genericMagicBox->SetItem( anotherItem );
                    THEN( "the original item is still in the box" )
                    {
                        std::string currentContents = genericMagicBox->GetItem( );
                        REQUIRE( currentContents == magicItem );
                    }
                }
            }
        }
    }
}
