#include <iostream>
#include "conclude.hpp" // 引入游戏中使用的自定义类的头文件
#include <sstream>
#include <istream>

// int choice1;
// 根据随机数生成的结果，创建并分配不同类型的房间给指定的指针
void random_choice(Room*& room) 
{ 
    int choice = std::rand() % 6; // 生成一个0到5之间的随机数
    //choice1 = 5;
    switch(choice) 
    {
        case 0:
            room = new Moster(); // 如果随机数是0，创建一个怪物房间
            break;
        case 1:
        case 2:
        case 3:
            room = new Room(); // 如果随机数是1、2或3，创建一个普通房间
            break;
        case 4:
            room = new one_way(); // 如果随机数是4，创建一个单向通行房间
            break;
        case 5:
            room = new princess(); // 如果随机数是5，创建一个含公主的房间
            break;
    }
}

// 与random_choice函数类似，但考虑了与Lobby（大厅）对象的关联
void random_choice2(Room*& room, Lobby*& lo) 
{ 
    int choice = std::rand() % 6; // 再次生成一个0到5之间的随机数
    switch(choice) 
    {
        case 0:
        case 1:
        case 2:
        case 3:
            room = new Room(); // 默认情况下，创建一个普通房间
            break;
        case 4:
            room = new one_way(); // 如果随机数是4，创建一个单向通行房间
            break;
        case 5:
            room = lo; // 如果随机数是5，返回大厅（Lobby）对象的引用
            break;
    }
}

// 程序的主入口
int main()
{

A:  std::srand(static_cast<unsigned int>(std::time(0))); // 随机数种子

    std::string input;
    std::string command;
    std::string direction;
    Lobby *lo = new Lobby();
    bool have_princess = false;
    princess *prin = new princess();
    Room* room ;Room* wait = nullptr;
    room = lo;
    lo->print();

    while ( getline(std::cin, input) )
    {
        // 使用istringstream分割字符串，方便提取命令和方向
        std::istringstream iss(input);

        // 读取命令和方向
        iss >> command >> direction;

        // 如果玩家输入的命令是"go"并且根据当前房间的逻辑，玩家可以往指定方向离开
        if ( command == "go" && room->leave(direction) )
        {
            // 如果玩家已经救出公主
            if (have_princess)
            {
                // 检查指定方向是否有下一个房间
                if (room->check_next(direction))
                {
                    wait = room->check_next(direction); // 获取下一个房间的引用
                    wait->print(); // 打印下一个房间的描述信息

                    if (wait->name == "lobby room")
                    {
                        if ( std::find( lo->enable_doors.begin(), lo->enable_doors.end(), direction) != lo->enable_doors.end())
                        {
                            lo->print();
                            std::cout<<"You have saved the princess! You Win"<<std::endl;
                            break;
                        }
                    }
                }
                else
                {
                    // 如果指定方向没有下一个房间，则根据游戏逻辑随机生成一个房间
                    random_choice2(wait, lo);
                    // 特殊房间逻辑处理：遇到怪物房间或者成功返回大厅并拥有公主
                    if (wait->name == "Moster room")
                    {
                        std::cout<<"You meet a Moster! Game over"<<std::endl; // 遇到怪物，游戏结束
                        break;
                    }

                     if (wait->name == "lobby room")
                    {
                        if ( std::find( lo->enable_doors.begin(), lo->enable_doors.end(), direction) != lo->enable_doors.end())
                        {
                            lo->print();
                            std::cout<<"You have saved the princess! You Win"<<std::endl;
                            break;
                        }
                        else
                        {
                            delete wait;
                            wait = new Room();
                        }
                        
                    }
                    // 设置当前房间与下一个房间的连接关系
                    room->next(wait, direction); // 在当前房间设置下一个房间的引用
                    wait->before(room, direction); // 在下一个房间设置返回上一个房间的引用
                    wait->enter(direction, 0); // 调用下一个房间的enter方法，可能会触发特定的房间逻辑
                }

            }
        
            else // 如果玩家还没有救出公主
            {
                if (room->check_next(direction)) // 检查指定方向上是否已经有下一个房间
                {
                    wait = room->check_next(direction); // 获取下一个房间的引用
                    wait->print(); // 打印下一个房间的描述信息
                }
                else // 如果指定方向上没有下一个房间
                {
                    random_choice(wait); // 随机生成一个新的房间
                    if (wait->name == "Moster room") // 如果随机生成的是怪物房间
                    {
                        std::cout<<"You meet a Moster! Game over"<<std::endl; // 遇到怪物，游戏结束
                        break;
                    }
                    else if(wait->name == "princess room") // 如果随机生成的是公主房间
                    {
                        have_princess = true; // 标记玩家已经救出公主
                    }
                    room->next(wait, direction); // 设置当前房间在指定方向上的下一个房间为wait
                    wait->before(room, direction); // 设置wait房间在相反方向上的前一个房间为当前房间
                    wait->enter(direction, 0); // 调用wait房间的enter方法，可能会触发特定的房间逻辑
                }
            }
            
            room = wait; // 更新当前房间为等待中的房间


        }
        else
        {
            std::cout<<"Illegal command"<<std::endl;
        }
    }

    char a;
    std::cout <<"You have played this game, would you like to play it again? Y/N"<<std::endl;
    std::cin>>a;
    getchar();
    if (a == 'Y' || a == 'y')
    {
        goto A;
    }
    else
    {
        return 0;
    }
    //room->print();
}