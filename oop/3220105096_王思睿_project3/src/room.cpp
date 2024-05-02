// 引入Room类的头文件以及必要的输入/输出、算法函数和随机数生成库。
#include "room.hpp"
#include <algorithm>
#include <iostream>
#include <random>

// Room类的默认构造函数初始化房间名称为"normal room"。
Room::Room()
{
    this->name = "normal room";
   
}

// 打印一条欢迎信息，包含房间名称以及关于可用出口和启用的门的细节。
void Room::print()
{
    std::cout<<"Welcome to the "<<this->name<<std::endl;
    // 以下代码打印出口数量并列出启用的门。
    std::cout<< "There are "<<this->exits<<" exits :";
    this->flag = 1; 
    int i = 0;
    // 遍历enable_doors向量打印所有除最后两个门外的门，门之间用逗号分隔。
    for ( i = 0; i < this->enable_doors.size()-2; ++i)
    {
        std::cout<< enable_doors[i]<<",";
    }

    // 如果enable_doors大小至少为2，则以"和"连接最后两扇门并打印。
    if ( enable_doors.size() >= 2 )
    {
        std::cout<<enable_doors[i]<<" and "<<enable_doors[i+1] <<std::endl;
    }
    else
    {
        // 如果不足两扇门，仅打印最后一扇门。
        std::cout<<enable_doors[i];
    }
}

// 检查房间的门，初始化出口为0，根据门的状态更新enable_doors向量和出口数量。
void Room::check_doors()
{
    this->exits = 0;
    // 根据每个方向的门是否存在，更新enable_doors向量并增加出口数量。
    if (this->west)
    {
        enable_doors.push_back("west");
        this->exits++;
    }
    if (this->east)
    {
        enable_doors.push_back("east");
        ++this->exits;
    }
    if ( this->north )
    {
        enable_doors.push_back("north");
        ++this->exits;
    }
    if( this->south)
    {
        enable_doors.push_back("south");
        ++this->exits;
    }
}

// next函数用于设置房间在特定方向上的下一个房间，以便于导航。
void Room::next(Room*& room, std::string direction)
{
    // 根据指定的方向，将传入的房间对象设置为相应方向上的下一个房间。
    if (direction == "east")
    {
        this->ea_do_ne = room;
    }

    // 以下类似的代码块针对其他方向执行相同的操作。
    if (direction == "south")
    {
        this->so_do_ne = room;
    }

    if (direction == "north")
    {
        this->no_do_ne = room;
    }

    if (direction == "west")
    {
        this->so_do_ne = room;
    }
}

// before函数用于设置房间在特定方向上的前一个房间。
void Room::before(Room*& room, std::string direction)
{
    // 类似于next函数，但用于设置前一个房间而非下一个房间。
    if (direction == "east")
    {
        this->we_do_ne = room;
    }

    // 以下代码块执行类似操作，针对其他方向。
    if (direction == "south")
    {
        this->no_do_ne = room;
    }

    if (direction == "north")
    {
        this->so_do_ne = room;
    }

    if (direction == "west")
    {
        this->ea_do_ne = room;
    }
}

// enter函数处理进入房间时的逻辑，包括设置方向状态为true，随机决定出口数量，打乱方向，并根据随机结果更新门的状态。
void Room::enter(std::string direction, int num_of_exits)
{
    // 根据传入的方向参数，设置对应方向的门为开启状态。
    if (direction == "west") {
        this->east = true;
    } else if (direction == "east") {
        this->west = true;
    } else if (direction == "south") {
        this->north = true;
    } else if (direction == "north") {
        this->south = true;
    }

    // 使用随机数生成器来决定出口的数量。
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(2, 4);
    this->exits = dist(gen);

    // 打乱方向向量，然后根据exits的值来决定哪些方向上的门是开启的。
    std::shuffle(directions.begin(), directions.end(), gen);
    for (int i = 0; i < this->exits; ++i) {
        *directions[i] = true;
    }
    // 检查门的状态并打印房间详情。
    this->check_doors();
    this->print();
}

// leave函数检查是否可以通过指定方向的门离开房间。
bool Room::leave(std::string direction)
{
    // 如果指定方向的门在enable_doors向量中，则可以离开房间。
    if (std::find(enable_doors.begin(), enable_doors.end(), direction) != enable_doors.end())
    {
        return true;
    }
    else 
    {
        return false;
    }
}

// check_next函数返回指定方向上的下一个房间对象，如果没有则返回nullptr。
Room* Room::check_next(std::string direction)
{
    // 根据传入的方向返回对应方向上的下一个房间对象。
    if (direction == "east")
    {
        return ea_do_ne;
    }

    // 以下代码块针对其他方向执行类似的检查。
    if (direction == "west")
    {
        return we_do_ne;
    }

    if (direction == "south")
    {
        return so_do_ne;
    }

    if( direction == "north")
    {
        return no_do_ne;
    }

    return nullptr;
}
