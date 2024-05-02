// 防止头文件重复包含
#ifndef _STUDENT_H_
#define _STUDENT_H_

// 包含输入输出流库和向量库
#include <iostream>
#include <vector>

// 定义student类
class student
{
private:
    // 私有成员

public:
    // 公共成员变量：学生姓名
    std::string name;
    // 公共成员变量：学生ID
    int id;
    // 公共成员变量：课程列表，每个课程是一个pair，包括课程名称和成绩
    std::vector<std::pair<std::string, int>> courselist;

    // 构造函数：初始化学生姓名和ID
    student(std::string name, int id)
    {
        this->id = id, this->name = name;
    }

    // 成员函数：添加一门课程及其成绩到课程列表中
    void add_course(std::string name, int score);
    // 成员函数：计算学生所有课程的平均成绩
    double average();
};

// 结束头文件防重复包含的条件编译指令
#endif
