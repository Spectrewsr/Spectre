
#ifndef _PRI_H_
#define _PRI_H_
#include "room.hpp"

class princess: public Room
{
private:

public:
    princess();
    ~princess();
    std::vector<bool*> directions = {&this->west, &this->east, &this->south, &this->north};
    void print() override;
};

#endif