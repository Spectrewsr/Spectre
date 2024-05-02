#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>
#include <string>
#include <sstream>
#include <istream>

// 函数：gcd
// 描述：计算两个整数的最大公约数
static int gcd(int a, int b)
{
    if (b == 0)
        return abs(a);
    return gcd(b, a % b);
}

// 类：FractionFormatException
// 描述：表示分数格式异常的类，继承自 std::exception
class FractionFormatException : public std::exception {
private:
    std::string message;

public:
    // 构造函数：FractionFormatException
    // 描述：初始化异常消息
    FractionFormatException(const std::string& msg) : message(msg) {}

    // 函数：what
    // 描述：返回异常消息的 C 风格字符串
    virtual const char* what() const throw() {
        return message.c_str();
    }
};

// 类：Fraction
// 描述：表示分数的类
class Fraction
{
private:
    int numerator = 1;      // 分子
    int denominator = 1;    // 分母

public:

    friend std::istream& operator>>(std::istream& in, Fraction& frac);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);    
    // 析构函数：~Fraction
    // 描述：析构函数，无具体实现
    ~Fraction()
    {

    }

    // 构造函数：Fraction
    // 描述：默认构造函数，分子和分母都为1
    Fraction();

    // 构造函数：Fraction
    // 描述：带参构造函数，初始化分子和分母为给定值
    Fraction(int a, int b);

    // 构造函数：Fraction
    // 描述：字符串构造函数，从给定的字符串中解析出分子和分母
    Fraction(std::string frac);

    // 构造函数：Fraction
    // 描述：拷贝构造函数，用于创建一个 Fraction 类型的副本
    Fraction(const Fraction& other);

    // 函数：getden
    // 描述：获取分母的值
    int getden();

    // 函数：getnum
    // 描述：获取分子的值
    int getnum();

    // 函数：setden
    // 描述：设置分母的值
    void setden(int);

    // 函数：setnum
    // 描述：设置分子的值
    void setnum(int);

    // 函数：printstr
    // 描述：将分数转换为字符串形式
    std::string printstr();

    // 函数：str_to_frac
    // 描述：从字符串中解析出分数的分子和分母
    void str_to_frac(std::string frac); 

    // 运算符重载：+
    // 描述：实现分数的加法运算
    Fraction operator + (Fraction);

    // 运算符重载：-
    // 描述：实现分数的减法运算
    Fraction operator - (Fraction);

    // 运算符重载：*
    // 描述：实现分数的乘法运算
    Fraction operator * (Fraction);

    // 运算符重载：/
    // 描述：实现分数的除法运算
    Fraction operator / (Fraction);

    // 运算符重载：< 
    // 描述：实现分数的小于比较运算
    bool operator < (Fraction);            

    // 运算符重载：<= 
    // 描述：实现分数的小于等于比较运算
    bool operator <= (Fraction);

    // 运算符重载：!=
    // 描述：实现分数的不等于比较运算
    bool operator != (Fraction);

    // 运算符重载：==
    // 描述：实现分数的等于比较运算
    bool operator == (Fraction);                    

    // 运算符重载：>
    // 描述：实现分数的大于比较运算
    bool operator > (Fraction);                

    // 运算符重载：>=
    // 描述：实现分数的大于等于比较运算
    bool operator >= (Fraction);     

     
  
};



#endif
