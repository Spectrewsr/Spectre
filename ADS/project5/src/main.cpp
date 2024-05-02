#include <map>
#include "heap.hpp"
#include <vector>

int main()
{
    int num_chars, num_cases;
    std::cin >> num_chars;

    // 数组存储每个字符和它的频率
    std::map<char, int> frequencies;
    std::vector<char> chars;

    char ch;
    int freq;
    hheap Minheap = Emptyheap(num_chars);
    for (int i = 0; i < num_chars; ++i)
    {
        
        std::cin >> ch >> freq;
        
        frequencies[ch] = freq;  // 正确添加到 map 中
        
        chars.push_back(ch);
        
        tnode node0 = new struct huffmanNode;
        node0->fre = freq;
        node0->left = node0->right = NULL;
        
        Insert(Minheap, node0);
        
    }

    huffmantree htree0 = construct(Minheap);
    //printf("ok\n");
    int WPL = calculateWPL(htree0, 0);
    std::cin >> num_cases;

    // 这里定义了一个map来存储字符和对应的字符串，可能需要更清晰的命名和用途描述
    std::map<char, std::string> test;
    std::string str;

    while (num_cases--)
    {
        int case_WPL = 0;

        for (int i = 0; i < num_chars; ++i)
        {
            std::cin >> ch >> str; // 假设这里是字符和频率的输入
            test[ch] = str; // 假设这里的目的是存储字符和频率的字符串表示
            case_WPL += str.length() * frequencies[ch];
        }

        bool check = true;
        if ( case_WPL == WPL )
        {
            for ( int i = 0; i < num_chars && check; ++i)
            {
                for ( int j = i+1; j < num_chars && check; ++j)
                {
                    check = Judge(test[chars[j]], test[chars[i]]);
                }
            }

            if (check)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}
