#ifndef _ONE_WAY_H_
#define _ONE_WAY_H_
#include "room.hpp"

class one_way: public Room//出入是不同的房间
{
private:

public:
    one_way();
    ~one_way()
    {

    };
    void before(Room*& room, std::string direction) override;
};

#endif