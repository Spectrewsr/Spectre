// 预处理指令，确保这个头文件在同一个编译单元中只被包含一次。
#ifndef S_H
#define S_H

// 包含了几乎所有标准库的头文件。
// 使用这个头文件可以方便，但可能会增加编译时间，
// 并不推荐在生产代码中使用。
#include <bits/stdc++.h>
using namespace std;

// 定义了一个名为student的类。
class student
{
private:
    int id; // 私有成员变量，用于存储学生的ID。

public:
    string name; // 公共成员变量，用于存储学生的姓名。
    int score[3]; // 公共成员变量，数组，用于存储学生的三门课程成绩。

    // 类的构造函数，用于创建student对象时初始化成员变量。
    // 接受一个整数id，一个字符串name和一个整数数组score作为参数。
    student(int id, string name, int score[]);

    // 成员函数，用于计算学生三门课程成绩的平均值。
    double score_average();
};

#endif // 结束预处理指令的条件编译块。
