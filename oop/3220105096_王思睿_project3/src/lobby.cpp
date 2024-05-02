#include "lobby.hpp"
#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>

Lobby::Lobby()
{
    this->name = "lobby room";
    ///printf("LLLLLLLLL\n");
    //this->exit = 3;
    // 初始化随机种子
    this->enter("",0);

    this->check_doors();
}

void Lobby::enter(std::string, int num_of_exits)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    // 随机选择2或3
    std::uniform_int_distribution<> dist(2, 4);
    this->exits = dist(gen);

    // 打乱方向
    std::shuffle(directions.begin(), directions.end(), gen);

    // 设置前2或3个方向为true
    for (int i = 0; i < this->exits; ++i) {
        *directions[i] = true;
    }
}

