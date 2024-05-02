#include "Diary.hpp"

int main()
{
    Diary mydiary;
    std::cout<<"the date you want to remove"<<std::endl;
    std::string date;
    std::cin>>date;
    mydiary.remove(date);
    return 0;
}