#include "Diary.hpp"

int main()
{
    std::string start, end;
    std::cout << "select the begin date and the end date"<<std::endl;
    std::cin>>start; std::cin>>end;
    Diary mydiary;
    mydiary.list(start,end);
    return 0;
}