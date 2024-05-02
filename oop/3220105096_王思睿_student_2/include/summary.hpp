// 防止头文件重复包含
#ifndef _SUMMARY_H_
#define _SUMMARY_H_

// 包含所需的头文件
#include "student.hpp" // 包含学生类定义
#include <fstream> // 用于文件操作
#include <sstream> // 用于字符串流操作
#include <map> // 用于存储课程和成绩列表的映射
#include<iostream> // 用于输入输出流操作
#include<iomanip> // 用于控制输入输出格式

#include <algorithm> // 用于使用算法，如max_element, min_element等

// 定义summary类
class summary
{
private:
    // 存储学生对象指针的向量
    std::vector<student*> stu;
    // 存储课程名称和对应成绩列表的映射
    std::map< std::string, std::vector<int>> course;
    // 记录学生数量的变量
    int num_of_stu = 0;

public:
    // 构造函数
    summary()
    {
        // 构造函数体为空
    }

    // 成员函数：从文件中读取学生和课程信息，并进行汇总
    void summarize(std::ifstream& file);
    // 成员函数：将汇总信息打印到文件中
    void print(std::ofstream& file);

};

// 结束头文件防重复包含的条件编译指令
#endif
