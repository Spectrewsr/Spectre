#include <iostream>
#include "princess.hpp"

princess::princess()
{
    this->name = "princess room";
}

void princess::print() 
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

    std::cout<<"Princess: thank you for saving me!\n"
                <<"You: let's get back to lobby\n"
                <<"Princess: now which door shall we go?\n"
                <<std::endl;
}

