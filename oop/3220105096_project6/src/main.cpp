#include <iostream>
#include "vector.hpp"
#include<string>

int main()
{
    Vector <int> a1;
    int num;
    for ( int i = 0; i < 100; ++i )
    {
       
        a1.push_back(i);
    }

    for ( int i = 0; i < 100; ++i )
    {
        std::cout<<a1[i]<<" ";
    }
    std::cout<<std::endl;
    //std::cout<<a1.at(1000)<<std::endl;


    Vector <int> a2(a1);
    std::cout<<a2.size()<<std::endl;
    for ( int i = 0; i < 100; ++i )
    {
        std::cout<<a2[i]<<" ";
    }

    Vector <int> a3(10000);
    std::cout<<a3.size()<<std::endl;


    Vector <std::string> str;
    std::string s0;
    std::cout<<"Input the first string"<<std::endl;
    std::cin>>s0;
    str.push_back(s0);
    std::cout<<str.operator[](0)<<std::endl;
    std::cout<<"Input the Second string"<<std::endl;
    std::cin>>s0;
    str.push_back(s0);
    std::cout<<str.operator[](1)<<std::endl;

    a1.~Vector();
    a2.clear();
    str.clear();

    std::cout<<a1.size()<<std::endl;
    std::cout<<a2.size()<<std::endl;
    std::cout<<str.size()<<std::endl;
    return 0;
}