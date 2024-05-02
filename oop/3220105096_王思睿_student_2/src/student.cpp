#include "student.hpp"
 
// 向学生的课程列表中添加一门新的课程和对应的成绩
void student::add_course( std::string course, int score) {
    // 使用std::make_pair创建一个包含课程名称和成绩的pair，然后添加到courselist向量中
    this->courselist.push_back(std::make_pair( course, score));
}

// 计算学生所有课程的平均分数
double student::average() {
    double sum = 0.0; // 用于累加所有课程的分数
    int size = this->courselist.size(); // 获取学生课程列表的大小，即课程数量
    // 遍历课程列表，累加所有课程的成绩
    for ( int i = 0; i < size; ++i ) {
        sum += this->courselist[i].second; // courselist[i].second表示第i门课程的成绩
    }
    // 计算平均分，如果课程数量为0，则返回0，否则返回成绩总和除以课程数量
    return (size == 0 ? 0 : (double)(sum/size));
}
