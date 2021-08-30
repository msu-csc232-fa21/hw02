/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2021
 *
 * @file    plain-box.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   PlainBox implementation.
 */

#include "plain-box.h"

template<typename ItemType>
PlainBox<ItemType>::PlainBox ( const ItemType& theItem ) : item { theItem }
{
    // Intentionally blank
}

template<typename ItemType>
ItemType PlainBox<ItemType>::GetItem ( ) const
{
    return item;
}

template<typename ItemType>
void PlainBox<ItemType>::SetItem ( const ItemType& theItem )
{
    item = theItem;
}