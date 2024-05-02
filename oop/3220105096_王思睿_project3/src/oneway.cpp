#include "oneway.hpp"
#include <iostream>

one_way::one_way()
{
    this->name = "one_way room";

}

void one_way::before(Room*& room, std::string direction)
{
    return;
}
