// 包含必要的头文件
#include "S.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>
#include <numeric> // 用于std::accumulate函数
#include <iterator> // 提供std::begin和std::end函数
#include <algorithm> // 提供std::max_element和std::min_element函数

using namespace std;

int main()
{
    string name;
    int id, num;
    int score[3];
    // 打开包含学生信息的文件
    ifstream file("../src/student.txt");
    string line, token;
    
    cin >> num; // 从标准输入读取学生数量
    student *stu[num]; // 动态创建学生对象数组
    int score1[num], score2[num], score3[num]; // 分别存储每个学生的三门课程成绩
    std::getline(file, line); // 读取文件的第一行
    int num_of_stu = 0;

    // 循环读取文件的每一行
    while (std::getline(file, line)) {

        std::vector<std::string> tokens; // 用于存储分解后的字符串

        istringstream iss(line); // 将行字符串转换为字符串流
        // 将字符串流中的每个元素分解并存储到tokens向量中
        while (iss >> token)
        {
             tokens.push_back(token);
        }

        // 如果读取的数据少于4个，终止循环
        if (tokens.size() < 4)
            break;

        // 将分解的字符串转换为学生信息并存储
        id = stoi(tokens[0]);
        name = tokens[1];
        score1[num_of_stu] = score[0] = stoi(tokens[2]);
        score2[num_of_stu] = score[1] = stoi(tokens[3]);
        score3[num_of_stu] = score[2] = stoi(tokens[4]);
        stu[num_of_stu++] = new student(id, name, score);
    }
    // 创建输出文件
    std::ofstream outputFile("output.txt");
    // 输出表头
    outputFile << "no\t" << "name\t    " << "score1\t" << "score2\t" << "score3\t" << "average\t" << endl;

    // 遍历学生对象数组，输出每个学生的信息及其成绩平均值
    for (int i = 0; i < 10; ++i)
    {
        outputFile << i << "\t" << stu[i]->name << "\t    " << stu[i]->score[0] << "\t    " << stu[i]->score[1] << "\t    " << stu[i]->score[2] << "\t    " << stu[i]->score_average() << "\t" << endl;
    }
    
    // 计算并输出每门课程的平均成绩
    double average1 = std::accumulate(score1, score1 + num, 0.0) / num;
    double average2 = std::accumulate(score2, score2 + num, 0.0) / num;
    double average3 = std::accumulate(score3, score3 + num, 0.0) / num;
    outputFile << " \t" << "average\t    " << average1 << "    \t" << average2 << "   \t" << average3 << "\t" << endl;

    // 计算并输出每门课程的最高分和最低分
    int *max1 = std::max_element(score1, score1 + num);
    int *min1 = std::min_element(score1, score1 + num);
    int *max2 = std::max_element(score2, score2 + num);
    int *min2 = std::min_element(score2, score2 + num);
    int *max3 = std::max_element(score3, score3 + num);
    int *min3 = std::min_element(score3, score3 + num);
    outputFile << " \t" << "max\t        " << *max1 << "    \t" << *max2 << "   \t" << *max3 << "\t" << endl;
    outputFile << " \t" << "min\t        " << *min1 << "    \t" << *min2 << "   \t" << *min3 << "\t" << endl;
    return 0;
}
