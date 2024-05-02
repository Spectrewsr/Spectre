// 包含student类的定义头文件。
#include "S.hpp"

// 包含string类和iostream库，用于处理字符串和输入输出操作。
#include <string>
#include <iostream>

using namespace std;

// student类的构造函数定义。
// 接收一个整型的id，一个字符串name和一个整型数组score作为参数。
student::student( int id, string name, int score[])
{
    // 将传入的id赋值给类的成员变量id。
    this->id = id;
    // 将传入的name赋值给类的成员变量name。
    this->name = name;
    // 使用循环将传入的score数组中的值赋值给类的成员变量score数组。
    for ( int i = 0; i < 3; ++i )
    {
        this->score[i] = score[i];
    }
}

// 定义一个名为score_average的成员函数，用于计算学生三门课程成绩的平均值。
double student::score_average()
{
    // 计算三门课程成绩的和，然后除以3，返回平均成绩。
    return (double)(score[1] + score[0] + score[2]) / 3;
}
