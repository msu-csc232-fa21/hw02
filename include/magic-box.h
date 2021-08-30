/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2021
 *
 * @file    magic-box.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   MagicBox specification.
 */

#ifndef CSC232_MAGIC_BOX_H__
#define CSC232_MAGIC_BOX_H__

#include "plain-box.h"

template<typename ItemType>
class MagicBox : public PlainBox<ItemType>
{
private:
    bool firstItemStored;

public:
    MagicBox();
    explicit MagicBox(const ItemType& theItem);
    void SetItem(const ItemType& theItem);
};

#include "magic-box.cpp"

#endif