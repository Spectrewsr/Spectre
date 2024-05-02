#ifndef _ROOM_H_
#define _ROOM_H_
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

class Room
{
protected:
    
    bool west = 0;
    bool east = 0;
    bool south = 0;
    bool north = 0;
    
    bool have_monster = false;
    bool princess = false;
    // bool west_door = false;
    // bool east_door = false;
    // bool north_door = false;
    // bool south_door = false;
    int exits = 0;
    int flag = 0;//是否进入过这个房间

public:
    std::string name;
    bool double_door = 1;
    Room* we_do_ne = nullptr;
    Room* ea_do_ne = nullptr;
    Room* no_do_ne = nullptr;
    Room* so_do_ne = nullptr;
    // Room* we_do_be = nullptr;
    // Room* ea_do_be = nullptr;
    // Room* no_do_be = nullptr;
    // Room* so_do_be = nullptr;
    std::vector<bool*> directions = {&west, &east, &south, &north};
    std::vector<std::string> enable_doors;
    Room();
    ~Room()
    {

    }
    void next(Room*& room, std::string direction);
    virtual void before(Room*& room, std::string direction);
    virtual void print();
    void check_doors();
    ///virtual void move();
    virtual void enter(std::string, int num_of_exits);
    bool leave(std::string);
    Room* check_next(std::string);
};

#endif