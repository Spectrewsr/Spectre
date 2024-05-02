#include "summary.hpp"
#include <algorithm>
#include <numeric>


// 从文件中读取学生和课程信息，然后汇总
void summary::summarize(std::ifstream& file)
{
    std::string line, token, name;
    int size, id;
    
    // 读取每一行数据
    while (getline(file, line))
    {
        std::vector<std::string> tokens;
        std::istringstream iss(line); // 使用istringstream分解字符串

        // 分解每一行的内容到tokens向量
        while (iss >> token)
        {
             tokens.push_back(token);
        }
        
        size = tokens.size();
        // 确保行中有数据
        if (size > 0)
        {
            int i = 1;
            // 创建新的学生对象，并添加到stu向量中
            stu.push_back(new student(tokens[0], num_of_stu));
            size -= 1;
            // 遍历并添加课程及其成绩
            while (size > 0)
            {
                stu[num_of_stu]->add_course(tokens[i], stoi(tokens[i+1]));
                course[tokens[i]].push_back(stoi(tokens[i+1]));
                size -= 2, i += 2; 
            }
            num_of_stu++;
        }
    }
}

// 将汇总信息打印到文件
void summary::print(std::ofstream& file)
{
    using namespace std;
    int size1 = stu.size();
    // 遍历所有学生并打印其信息
    for (int i = 0; i < size1; ++i)
    {
        file << setw(10) << left << stu[i]->name << "\t";
        // 打印每门课程及其成绩
        for (int j = 0; j < stu[i]->courselist.size(); ++j)
        {
            file << setw(10) << left << stu[i]->courselist[j].first  << stu[i]->courselist[j].second << "\t";
        }
        // 打印学生的平均成绩
        file << "average_score " << setw(7) << left << fixed << setprecision(2) << stu[i]->average() << endl;
    }

    file << "           ";
    std::map<std::string, std::vector<int>>::iterator it;
    // 打印课程名称
    for (it = course.begin(); it != course.end(); ++it)
    {
        file << std::setw(10) << std::left << (*it).first;
    }
    file << std::endl;

    file << "average    ";
    // 计算并打印每门课程的平均成绩
    for (it = course.begin(); it != course.end(); ++it)
    {
        int size = (*it).second.size();
        double sum = std::accumulate((*it).second.begin(), (*it).second.end(), 0.0);
        file << setw(10) << left << (size == 0 ? 0 : (double)(sum/size));
    }
    file << endl;

    file << "max        ";
    // 计算并打印每门课程的最高分
    for (it = course.begin(); it != course.end(); ++it)
    {
        auto ma = max_element((*it).second.begin(), (*it).second.end());
        file << setw(10) << left << *ma;
    }
    file << endl;

    file << "min        ";
    // 计算并打印每门课程的最低分
    for (it = course.begin(); it != course.end(); ++it)
    {
        auto ma = min_element((*it).second.begin(), (*it).second.end());
        file << setw(10) << left << *ma;
    }
    file << endl;
}
