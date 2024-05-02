#include <iostream>
#include "oper.hpp"

int main()
{
    bool state = true;
    fractionoper* begin;

    while (state)
    {
        begin = new fractionoper();
        state = begin->state;
    }
    std::cout<<"Exit\n";
    return 0;
}