#ifndef _LOBBY_H_
#define _LOBBY_H_
#include "room.hpp"
#include <vector>

class Lobby:public Room
{
private:
    
public:
    Lobby();
    std::vector<bool*> directions = {&this->west, &this->east, &this->south, &this->north};
    void enter(std::string, int num_of_exits) override;
};

#endif