#include "red_and_black.cpp"

#include <iostream>
#include <algorithm>

int main()
{
    int num, key;
    std::cin >> num;
    while ( num-- )
    {
        std::cin >>key;
        std::pair<int, bool> kv = std::make_pair(key, false);
        if(Insert(kv).second == false)
        {
            std::cerr << "错误：插入失败。" << std::endl; // 向标准错误输出错误信息
            return -1;
        }
        std::cout <<_root->_kv.first<<std::endl;
        if (_root->_kv.first == 38 )
        {
            std::cout <<_root->_left->_kv.first<<" "<<_root->_left->_col<<" "<<_root->_right->_kv.first<<" "<<_root->_right->_col<<std::endl;
        }
    }
     num =6;
    while (num--)
    {
        std::cin>>key;
        Erase(key);
        std::cout <<_root->_kv.first<<std::endl;
        
        std::cout <<_root->_left->_kv.first<<" "<<_root->_left->_col<<" "<<_root->_right->_kv.first<<" "<<_root->_right->_col<<std::endl;
        
    }
    return 0;
}