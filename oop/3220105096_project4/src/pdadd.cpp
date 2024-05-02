#include "Diary.hpp"


int main()
{
    std::string date;
    std::cout << "select a date"<<std::endl;
    std::cin>>date;
    Diary mydiary;
    mydiary.add(date);
    return 0;
}