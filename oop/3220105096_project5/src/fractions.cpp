#include "fractions.hpp"

// 重载输入流运算符
std::istream& operator >> (std::istream& in, Fraction& frac) 
{
    char slash; // 用于临时存储分隔符
    in >> frac.numerator >> slash >> frac.denominator;
    return in; // 允许链式调用
}      

std::ostream& operator << (std::ostream& out, const Fraction& frac) 
{
    out << frac.numerator << '/' << frac.denominator;
    return out; // 允许链式调用
}

// 默认构造函数，不初始化成员变量。
Fraction::Fraction()
{
}

// 构造函数，用于创建一个具有指定分子和分母的分数对象。
Fraction::Fraction(int a, int b)
{
    // 初始化分子和分母。
    this->denominator = b;
    this->numerator = a;
}

// 从字符串构造分数的构造函数，接受如"1/2"形式的分数表示。
Fraction::Fraction(std::string frac)
{
    // 将字符串转换为分数形式。
    this->str_to_frac(frac);
};

// 拷贝构造函数，用于创建一个已存在分数的副本。
Fraction::Fraction(const Fraction& other)
{
    // 拷贝分子和分母。
    this->denominator = other.denominator;
    this->numerator = other.numerator;
}

// 获取分母。
int Fraction::getden()
{
    return this->denominator;
}

// 获取分子。
int Fraction::getnum()
{
    return this->numerator;
}

// 设置分母。
void Fraction::setden(int den)
{
    this->denominator = den;
}

// 设置分子。
void Fraction::setnum(int num)
{
    this->numerator = num;
}

// 将分数转换为字符串表示，如"1/2"。
std::string Fraction::printstr()
{
    std::stringstream ss;
    ss << this->numerator << "/" << this->denominator;
    return ss.str();
}

// 从字符串中提取分数，格式应为"numerator/denominator"。
void Fraction::str_to_frac(std::string frac)
{
    try
    {
        std::size_t pos = frac.find('/');
        if (pos != std::string::npos && pos != 0 && pos != frac.size()-1)
        {
            numerator = std::stoi(frac.substr(0, pos));
            denominator = std::stoi(frac.substr(pos + 1));
            if (denominator == 0)
            {
                throw FractionFormatException("Denominator shouldn't be 0!");
            }
        }
        else 
        {
            throw FractionFormatException("Format error, should be 'numerator/denominator'.");
        }
    }
    catch(const std::invalid_argument& e)
    {
        throw FractionFormatException("Invalid input: " + frac);
    }
    catch(const std::out_of_range& e)
    {
        throw FractionFormatException("Input value out of range: " + frac);
    }
}

Fraction Fraction::operator + (Fraction addend)
{
    // 创建一个新的分数对象用于存储结果。
    Fraction res;
    // 如果分母相同，直接加分子。
    if (this->denominator == addend.getden())
    {
        int num = this->numerator + addend.getnum();
        // 如果结果分子不为0，尝试化简分数。
        if (num != 0)
        {
            int max_gcd = gcd(this->numerator, num);
            res.setnum(num / max_gcd);
            res.setden(this->denominator / max_gcd);
        }
        else
        {
            // 结果为0，直接设置分数为0。
            res.setnum(0);
        }
    }
    else
    {
        // 分母不同，先找到公共分母，然后加分子。
        int den = this->denominator * addend.getden();
        int num = this->numerator * addend.getden() + this->denominator * addend.getnum();
        // 如果结果分子不为0，尝试化简分数。
        if (num != 0)
        {
            int max_gcd = gcd(den, num);
            res.setden(den / max_gcd);
            res.setnum(num / max_gcd);
        }
        else
        {
            // 结果为0，直接设置分数为0。
            res.setnum(0);
        }
    }
    return res;
}

// 重载减法运算符，用于实现两个分数的减法。
Fraction Fraction::operator - (Fraction subtrahend)
{
    Fraction res; // 结果分数。
    // 如果分母相同，直接减分子。
    if (this->denominator == subtrahend.getden())
    {
        int num = this->numerator - subtrahend.getnum();
        // 如果结果分子不为0，尝试化简分数。
        if (num != 0)
        {
            int max_gcd = gcd(num, this->denominator);
            res.setnum(num / max_gcd);
            res.setden(this->denominator / max_gcd);
        }
        else
        {
            // 结果为0，直接设置分数为0。
            res.setnum(0);
        }
    }
    else
    {
        // 分母不同，先找到公共分母，然后减分子。
        int den = this->denominator * subtrahend.getden();
        int num = this->numerator * subtrahend.getden() - this->denominator * subtrahend.getnum();
        // 如果结果分子不为0，尝试化简分数。
        if (num != 0)
        {
            int max_gcd = gcd(den, num);
            res.setden(den / max_gcd);
            res.setnum(num / max_gcd);
        }
        else
        {
            // 结果为0，直接设置分数为0。
            res.setnum(0);
        }
    }
    return res;
}

// 重载乘法运算符，用于实现两个分数的乘法。
Fraction Fraction::operator * (Fraction multiplicand)
{
    Fraction res; // 结果分数。
    int num = this->numerator * multiplicand.getnum();
    int den = this->denominator * multiplicand.getden();
    // 如果分子为0，结果分数为0。
    if (num == 0)
    {
        res.setnum(0);
        return res;
    }
    // 尝试化简分数。
    int max_gcd = gcd(num, den);
    res.setden(den / max_gcd);
    res.setnum(num / max_gcd);
    return res;
}

// 重载除法运算符，用于实现两个分数的除法。
Fraction Fraction::operator / (Fraction dividend)
{
    Fraction res; // 结果分数。
    if (this->numerator == 0 || !dividend.getnum())
    {
        // 如果被除数或除数的分子为0，结果为0。
        res.setnum(0);
        return res;
    }
    // 除法转换为乘以倒数。
    int num = this->numerator * dividend.getden();
    int den = this->denominator * dividend.getnum();
    // 尝试化简分数。
    int max_gcd = gcd(num, den);
    res.setden(den / max_gcd);
    res.setnum(num / max_gcd);
    return res;
}

// 重载小于运算符，用于比较两个分数的大小。
bool Fraction::operator < (Fraction frac)
{
    // 比较两个分数的大小，通过交叉相乘避免实际除法运算。
    return this->numerator * frac.getden() < this->denominator * frac.getnum();
}

// 重载小于等于运算符。
bool Fraction::operator <= (Fraction frac)
{
    // 使用交叉相乘的方法比较两个分数，判断是否小于等于。
    return this->numerator * frac.getden() <= this->denominator * frac.getnum();
}

// 重载不等于运算符，用于判断两个分数是否不相等。
bool Fraction::operator != (Fraction frac)
{
    // 判断两个分数是否不相等，通过比较分子的乘积与分母的乘积。
    return this->numerator * frac.getden() != this->denominator * frac.getnum();
}

// 重载等于运算符。
bool Fraction::operator == (Fraction frac)
{
    // 判断两个分数是否相等，通过比较分子的乘积与分母的乘积。
    return this->numerator * frac.getden() == this->denominator * frac.getnum();
}

// 重载大于运算符。
bool Fraction::operator > (Fraction frac)
{
    // 使用交叉相乘的方法比较两个分数的大小。
    return this->numerator * frac.getden() > this->denominator * frac.getnum();
}

// 重载大于等于运算符。
bool Fraction::operator >= (Fraction frac)
{
    // 使用交叉相乘的方法判断是否大于等于。
    return this->numerator * frac.getden() >= this->denominator * frac.getnum();
}

