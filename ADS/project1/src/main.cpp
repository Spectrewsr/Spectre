#include "AVL.hpp"
#include "UBS.hpp"
#include <vector>
#include <iostream>
#include <vector>
#include <chrono>

#include <algorithm> // For std::shuffle
#include <random>    // For std::random_device and std::mt19937


using namespace std;

void test_AVL( int count, int count1, int count2, vector<int> random_list, vector<int> random_list1,vector<int> list1)
{
    
    AVL_TREE avlt;
    
    clock_t start_time=clock();//顺序插入并删除
    while ( count2-- )
    {
        avlt.root = avlt.insert( avlt.root, list1[count+1-count2]);   
    }

    while ( count1-- )
    {
        avlt.root = avlt.deletenode( list1[count+1-count1], avlt.root);
    }

    clock_t end_time=clock();
    cout << "The  AVL tree run time1 is: " <<(double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;

    count2 = count1 = count;

    start_time=clock();///顺序插入，逆序删除
    while ( count2-- )
    {
        avlt.root = avlt.insert( avlt.root, list1[count+1-count2]);      
    }
    
    while ( count1-- )
    {
        avlt.root = avlt.deletenode( list1[count1], avlt.root);
    }
    end_time=clock();
    cout << "The  AVL tree run time2 is: " <<(double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;
    
    count2 = count1 = count;
    start_time=clock();//随机插入，随机删除
    while ( count2-- )
    {
        avlt.root = avlt.insert( avlt.root, random_list[count+1-count2]);      
    }
    
    while ( count1-- )
    {
        avlt.root = avlt.deletenode( random_list1[count+1-count1], avlt.root);
    }
    end_time=clock();
    cout << "The  AVL tree run time3 is: " <<(double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;


}

void test_UBS( int count, int count1, int count2, vector<int> random_list, vector<int> random_list1, vector<int> list1)
{
    UBS_TREE ubst;
    

    clock_t start_time=clock();//顺序插入并删除
    while ( count2-- )
    {
        ubst.root = ubst.insert( ubst.root, list1[count+1-count2]);   
    }
    
    while ( count1-- )
    {
        ubst.root = ubst.deletenode( ubst.root, list1[count+1-count1]);
    }

    clock_t end_time=clock();
    cout << "The unbalanced binary search tree run time1 is: " <<(double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;

    count2 = count1 = count;

    start_time=clock();///顺序插入，逆序删除
    while ( count2-- )
    {
        ubst.root = ubst.insert( ubst.root, list1[count+1-count2]);      
    }
    
    while ( count1-- )
    {
        ubst.root = ubst.deletenode( ubst.root, list1[count1]);
    }
    end_time=clock();
    cout << "The unbalanced binary search tree run time2 is: " <<(double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;
    
    count2 = count1 = count;
    start_time=clock();//随机插入，随机删除
    while ( count2-- )
    {
        ubst.root = ubst.insert( ubst.root, random_list[count+1-count2]);      
    }
    
    
    while ( count1-- )
    {
        ubst.root = ubst.deletenode( ubst.root,random_list1[count+1-count1]);
    }
    end_time=clock();
    cout << "The unbalanced binary search tree run time3 is: " <<(double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;

}

int main ()
{
    int count;
    cout <<"输入数据大小：";
    cin>>count;// 0到count   count+1个数
    std::vector<int> random_list(count+1), list1(count+1), random_list1(count+1); // 生成包含0到3000的向量
    int count1 = count, count2 = count;
    for (int i = 0; i <= count; ++i) {
        random_list1[i] = list1[i] = random_list[i] = i;
    }
    // 使用随机数引擎和随机设备初始化洗牌器
    std::random_device rd;
    std::mt19937 g(rd());
    
    // 使用洗牌算法对向量进行洗牌
    std::shuffle(random_list.begin(), random_list.end(), g);
    std::random_device rd1;
    std::mt19937 g1(rd1());
    std::shuffle(random_list1.begin(), random_list1.end(), g1);

    test_UBS( count, count1, count2, random_list, random_list1, list1);
    test_AVL( count, count1, count2, random_list, random_list1, list1);

    return 0;
}