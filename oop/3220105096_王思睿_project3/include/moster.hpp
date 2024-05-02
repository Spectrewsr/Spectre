#ifndef _MOSTER_H_
#define _MOSTER_H_
#include "room.hpp"

class Moster: public Room
{
private:

public:
    Moster();
    std::vector<bool*> directions = {&this->west, &this->east, &this->south, &this->north};
    
};

#endif