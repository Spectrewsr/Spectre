#include "Diary.hpp"

int main()
{
    std::string date;
    std::cout<<"the date you want to show"<<std::endl;
    std::cin>>date;

    Diary mydiary;
    mydiary.show(date);
    return 0;
}