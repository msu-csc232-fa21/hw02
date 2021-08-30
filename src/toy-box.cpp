/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2021
 *
 * @file    toy-box.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   ToyBox implementation.
 */

#include "toy-box.h"

template<typename ItemType>
ToyBox<ItemType>::ToyBox ( const ItemType& theItem, const Color& theColor ) : PlainBox<ItemType> { theItem },
                                                                              boxColor { theColor }
{

}

template<typename ItemType>
ToyBox<ItemType>::ToyBox ( const Color& theColor ) : PlainBox<ItemType> { ItemType { } },
                                                     boxColor { theColor }
{

}

template<typename ItemType>
Color ToyBox<ItemType>::GetColor ( ) const
{
    return boxColor;
}
