/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2021
 *
 * @file    magic-box.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   MagicBox implementation.
 */

#include "magic-box.h"

template<typename ItemType>
MagicBox<ItemType>::MagicBox ( ) : firstItemStored { false }
{
    // PlainBox base class constructor called implicitly
    // Box has no magic initially
}

template<typename ItemType>
MagicBox<ItemType>::MagicBox ( const ItemType& theItem ) : firstItemStored { false }
{
    // Box has no magic initially
    SetItem(theItem); // calls MagicBox version of SetItem()
    // Box has magic now
}

template<typename ItemType>
void MagicBox<ItemType>::SetItem ( const ItemType& theItem )
{
    if (!firstItemStored)
    {
        PlainBox<ItemType>::SetItem( theItem );
        firstItemStored = true; // Box now has magic
    }
}