#include "Diary.hpp"

Diary::Diary()
{

}

Diary::~Diary()
{
    if(outfile.is_open()) 
    {
        outfile.close(); // 确保在析构函数中关闭文件
    }
}


void Diary::add(std::string date)
{
    std::vector<std::string> lines; // 存储文件中的所有行，包括新添加的或修改的日记条目
    std::string line; // 用于读取文件中的单行文本
    bool datefound = false; // 标记是否找到相同日期的条目
    std::string content; // 用户输入的日记内容
    std::cout<<"the content you want to write: "<<std::endl;
    getchar(); // 消耗掉之前留在输入流中的换行符
    std::getline(std::cin, content); // 获取用户输入的日记内容

    std::ifstream infile("mydiary.txt"); // 打开日记文件以读取内容
    while (std::getline(infile, line)) 
    {
        // 如果找到与输入日期相同的条目，用新内容替换旧内容
        if (!datefound && line.size() >= date.size() && line.substr(0, date.size()) == date) {
            lines.push_back(date + " " + content); // 更新这一行的内容为新的日记内容
            datefound = true;
        } else {
            lines.push_back(line); // 将未更改的行添加到lines中
        }
    }

    infile.close(); // 关闭文件

    // 如果文件中没有找到相同日期的条目，将新条目添加到lines末尾
    if (!datefound) 
    {
        lines.push_back(date + " " + content);
    }
    
    std::ofstream outfile("mydiary.txt"); // 打开文件以写入更新后的内容
    for (const auto& updatedLine : lines) // 遍历lines中的每一行
    {
        outfile << updatedLine << std::endl; // 写入文件
    }

    outfile.close(); // 关闭文件
}


void Diary::list(std::string start, std::string end) 
{
    int startDay = extractDayNumber(start);
    int endDay = extractDayNumber(end);

    std::ifstream infile("mydiary.txt");
    std::string line;

    while (std::getline(infile, line)) 
    {
        if (line.substr(0, 3) == "day")
        {
            // 假设日期位于每行的开始，并且紧跟在"day"后面
            int lineDay = extractDayNumber(line.substr(0,4));
            // 检查行的日期是否在指定范围内
            if (lineDay >= startDay && lineDay <= endDay) {
                std::cout << line << std::endl; // 打印符合条件的行
            }
        }
        
    }
    infile.close();
}

int Diary::remove(std::string date) {
    std::ifstream infile("mydiary.txt"); // 或者使用成员变量存储文件名
    std::vector<std::string> lines;
    std::string line;
    bool found = false, flag = false;
    //std::cout<<"have found"<<std::endl;
    // 读取并且除去匹配的日期条目
    while (std::getline(infile, line)) 
    {
        // 如果这一行的开始与date匹配，则不将它写入lines
        if (!found && line.size() >= date.size() && line.substr(0,date.size()) == date) 
        {
            found = true;  // 标记已找到
            continue;      // 跳过匹配行和随后的空行（如果有的话）
        }
        if (!flag && found && line.empty()) 
        {
            flag = true; // 如果已找到日期并遇到空行，则继绀读取后续内容
            continue;
        }
        lines.push_back(line);
    }
    infile.close();

    
    // 如果没找到对应日期，返回错误
    if (!found) {
        return -1; // 未找到
    }

    //std::cout<<"have found"<<std::endl;
    // 将除去特定日期条目之外的所有内容写回文件
    std::ofstream outfile("mydiary.txt", std::ios::trunc); // 使用 trunc 模式重写文件
    for (const auto& l : lines) {
        outfile << l<<"\n";
    }

    //printFileContents(); 
    return 0; // 成功
}

void Diary::show(std::string date) 
{
    std::ifstream infile("mydiary.txt");
    //std::vector<std::string> lines;
    std::string line;
    //std::cout << "File contents after modification:" << std::endl;
    bool found = false;

    while (std::getline(infile, line)) 
    {
        // 如果这一行的开始与date匹配，则不将它写入lines
        if (!found && line.size() >= date.size() && line.substr(0,date.size()) == date) 
        {
            found = true;  // 标记已找到
            break;      // 跳过匹配行和随后的空行（如果有的话）
        }
        
    }
    infile.close();
    
    std::cout<<line<<std::endl;
}
