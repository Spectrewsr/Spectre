#include "oper.hpp"

// 构造函数，在对象创建时自动调用。它输出操作选项并等待用户选择。
fractionoper::fractionoper()
{
    // 打印操作菜单。
    this->printoper();
    // 提示用户选择操作。
    this->chooseoper();
}

// 输出可用操作的列表。
void fractionoper::printoper()
{
    std::cout << "Which operation would you like to take?" << std::endl;
    std::cout << "1: Add\n"
              << "2: Sub\n"
              << "3: Mul\n"
              << "4: Div\n"
              << "5: Compare 2 fractions\n"
              << "6: Turn a fraction to double\n"
              << "7: Turn a double to fraction\n"
              << "8: Turn a fraction to string\n"
              << "9: Inserter and extractor for streams\n"
              << "10: Exit\n"
              << std::endl;
}

// 根据用户输入选择相应的操作。
void fractionoper::chooseoper()
{
    int choice;
    std::cin >> choice; // 获取用户选择。
    switch(choice)
    {
        case 1: // 加法。
            this->add();
            break;

        case 2: // 减法。
            this->sub();
            break;
        
        case 3: // 乘法。
            this->mul();
            break;

        case 4: // 除法。
            this->div();
            break;
        
        case 5: // 比较两个分数。
            this->fraccompare();
            break;

        case 6: // 将分数转换为双精度浮点数。
            this->frac_to_dou();
            break;

        case 7: // 将双精度浮点数转换为分数。
            this->dou_to_frac();
            break;

        case 8: // 将分数转化为string。
            this->frac_to_str();
            break;

        case 9: // 自定义的其他操作。
            this->oper_stream();
            break;

        case 10: // 退出程序。
            this->state = false;
            break;

        default: // 当输入不匹配以上任何一个选项时。
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
    }
}

// 从用户输入中读取两个分数，用于后续操作。
bool fractionoper::cin2frac(Fraction& a, Fraction& b)
{
    std::string frac1, frac2;
    std::cout << "Enter your first fraction:" << std::endl;

    std::cin >> frac1;
    try
    {
        a = Fraction(frac1); // 尝试将字符串转换为分数对象。
    }
    catch(const std::exception& e)
    {
        system("clear"); // 清屏。
        std::cerr << e.what() << '\n'; // 打印错误信息。
        return false; // 返回失败。
    }
    
    std::cout << "Enter your second fraction:" << std::endl;
    std::cin >> frac2;
    try
    {
        b = Fraction(frac2); // 同上。
    }
    catch(const std::exception& e)
    {
        system("clear"); // 清屏。
        std::cerr << e.what() << '\n'; // 打印错误信息。
        return false; // 返回失败。
    }
    return true; // 成功读取两个分数。
}

// 实现分数加法操作。
void fractionoper::add()
{
    Fraction a, b;
    if (!cin2frac(a, b)) // 如果读取分数失败，则返回。
    {
        return;
    }
    
    Fraction res = a + b; // 执行加法。
    // 输出结果。
    if (res.getnum())
        std::cout << "The result of " << a.printstr() << " + " << b.printstr() << " is " << res.printstr() << std::endl;
    else
        std::cout << "The result of " << a.printstr() << " + " << b.printstr() << " is " << "0" << std::endl;
}

// 实现分数减法操作。
void fractionoper::sub()
{
    Fraction a, b;
    if (!cin2frac(a, b))
    {
        return;
    }

    Fraction res = a - b; // 执行减法。
    // 输出结果。
    if (res.getnum())
    {
        std::cout << "The result of " << a.printstr() << " - " << b.printstr() << " is " << res.printstr() << std::endl;
    }
    else
    {
        std::cout << "The result of " << a.printstr() << " - " << b.printstr() << " is " << "0" << std::endl;
    }
}

// 实现分数乘法操作。
void fractionoper::mul()
{
    Fraction a, b;
    if (!cin2frac(a, b))
    {
        return;
    }

    Fraction res = a * b; // 执行乘法。
    // 输出结果。
    if (res.getnum())
    {
        std::cout << "The result of " << a.printstr() << " * " << b.printstr() << " is " << res.printstr() << std::endl;
    }
    else
    {
        std::cout << "The result of " << a.printstr() << " * " << b.printstr() << " is " << "0" << std::endl;
    }
}

// 实现分数除法操作。
void fractionoper::div()
{
    Fraction a, b;
    if (!cin2frac(a, b))
    {
        return;
    }

    Fraction res = a / b; // 执行除法。
    // 输出结果。
    if (res.getnum())
    {
        std::cout << "The result of (" << a.printstr() << ") / (" << b.printstr() << ") is " << res.printstr() << std::endl;
    }
    else
    {
        std::cout << "The result of (" << a.printstr() << ") / (" << b.printstr() << ") is " << "0" << std::endl;
    }
}

// 比较两个分数。
void fractionoper::fraccompare()
{
    Fraction a, b;
    if (!cin2frac(a, b))
    {
        return;
    }

    // 执行比较并输出结果。
    if (a == b) std::cout << a.printstr() << " == " << b.printstr() << std::endl;
    if (a < b) std::cout << a.printstr() << " < " << b.printstr() << std::endl;
    if (a <= b) std::cout << a.printstr() << " <= " << b.printstr() << std::endl;
    if (a > b) std::cout << a.printstr() << " > " << b.printstr() << std::endl;
    if (a >= b) std::cout << a.printstr() << " >= " << b.printstr() << std::endl;
    if (a != b) std::cout << a.printstr() << " != " << b.printstr() << std::endl;
}

// 将分数转换为双精度浮点数并输出。
void fractionoper::frac_to_dou()
{
    Fraction a;
    double a_double;
    std::string frac1;
    std::cout << "Enter your fraction:" << std::endl;

    std::cin >> frac1;
    try
    {
        a = Fraction(frac1); // 尝试将字符串转换为分数对象。
    }
    catch(const std::exception& e)
    {
        system("clear"); // 清屏。
        std::cerr << e.what() << '\n'; // 打印错误信息。
        return;
    }
    // 进行转换并输出结果。
    a_double = static_cast<double>(a.getnum()) / static_cast<double>(a.getden());
    std::cout << a_double << std::endl;
}

// 将双精度浮点数转换为分数并输出。
void fractionoper::dou_to_frac()
{
    std::string frac1;
    std::cout << "Enter your double number" << std::endl;
    getchar(); // 清理输入缓冲区。
    std::cin >> frac1;
    double num = std::stod(frac1); // 将字符串转换为double。
    int places = frac1.find('.'); // 查找小数点的位置。
    places = frac1.size() - places; // 计算小数位数。
    int numerator = static_cast<int>(num * pow(10, places)); // 转换为分子。
    int denominator = static_cast<int>(pow(10, places)); // 计算分母。
    int max_gcd = gcd(numerator, denominator); // 计算最大公约数以简化分数。
    // 输出转换结果。
    std::cout << "Conversion from a finite decimal string: " << frac1 << " to a fraction is " << numerator / max_gcd << "/" << denominator / max_gcd << std::endl;
}

void fractionoper::frac_to_str()
{
    int a, b;
    std::cout<< "Input your numerator and denominator:\n";
    std::cin >> a >> b;
    Fraction frac = Fraction(a,b);
    std::cout<<"The fraction to string is: "<<frac.printstr()<<std::endl;
}

//Inserter and extractor for streams
void fractionoper::oper_stream()
{
    Fraction a;
    std::cout<<"Input a fraction\n";
    std::cin>>a;
    std::cout<<"The fraction is "<<a<<std::endl;
}