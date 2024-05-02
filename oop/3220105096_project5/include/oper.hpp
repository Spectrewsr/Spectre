#ifndef _OPER_H_
#define _OPER_H_

#include "fractions.hpp"
#include <math.h>

// 类：fractionoper
// 描述：实现分数运算的类
class fractionoper
{
private:

public:
    bool state = true;  // 状态标志，用于表示是否运行成功

    // 构造函数：fractionoper
    // 描述：默认构造函数，无具体实现
    fractionoper();

    // 函数：add
    // 描述：实现两个分数的加法运算
    void add();

    // 函数：sub
    // 描述：实现两个分数的减法运算
    void sub();

    // 函数：mul
    // 描述：实现两个分数的乘法运算
    void mul();

    // 函数：div
    // 描述：实现两个分数的除法运算
    void div();

    // 函数：cin2frac
    // 描述：从标准输入流中读取两个分数
    bool cin2frac(Fraction& a, Fraction& b);

    // 函数：printoper
    // 描述：打印操作菜单
    void printoper();

    // 函数：chooseoper
    // 描述：选择要执行的操作
    void chooseoper();

    // 函数：fraccompare
    // 描述：比较两个分数的大小
    void fraccompare();

    // 函数：frac_to_dou
    // 描述：将分数转换为小数
    void frac_to_dou();

    // 函数：dou_to_frac
    // 描述：将小数转换为分数
    void dou_to_frac();

    //将fraction转化为string
    void frac_to_str();

    //对流进行操作
    void oper_stream();
};

#endif
