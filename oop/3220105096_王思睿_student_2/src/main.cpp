// 包含所需的头文件。
//#include "student.hpp" // 如果需要访问student类定义，取消这行的注释。
#include "summary.hpp" // 包含summary类的定义。
#include <fstream> // 用于文件输入输出操作。
#include <sstream> // 用于字符串流操作。

int main()
{
    // 打开一个文件流以读取，文件路径为"../src/final.txt"。
    std::ifstream file("../src/final.txt");
    // 创建一个summary类的实例，命名为table1。
    summary table1;
    // 调用table1实例的summarize函数，读取并处理file文件流中的数据。
    table1.summarize(file);
    // 创建一个用于输出的文件流，文件名为"output.txt"。
    std::ofstream outputfile("output.txt");
    // 调用table1实例的print函数，将汇总信息输出到outputfile文件流中。
    table1.print(outputfile);
}
