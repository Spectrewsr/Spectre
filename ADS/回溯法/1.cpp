#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

bool solutions;
std::vector<int> sol;
std::vector<int> players;
int hang, wol, liers;

bool check_true()
{
    int wo_li, num_of_lier;
    wo_li = 0;
    std::vector<int>solution (hang+1, 1);
    std::vector<int>lier;

    for ( int i = 0; i < sol.size(); ++i)
    {
        solution[sol[i]] = 0;
    }

    //printf("check\n");
    for ( int i = 1; i <= hang; ++i )
    {
        if (solution[i] == 1)
        {
            if( players[i-1] >0 && solution[abs(players[i-1])] == 0)
            {
                lier.push_back(i);
            }
            else if(players[i-1] < 0 && solution[abs(players[i-1])] == 1)
            {
                lier.push_back(i);
            }
        }

        else if (solution[i] == 0)
        {
            if( players[i-1] >0 && solution[abs(players[i-1])] == 0)
            {
                lier.push_back(i);
                wo_li++;
            }
            else if(players[i-1] < 0 && solution[abs(players[i-1])] == 1)
            {
                lier.push_back(i);
                wo_li++;
            }
        }
    }

    // for ( int i = 0; i < lier.size(); ++i)
    // {
    //     printf("%d   ", lier[i]);
    // }
    // printf(" \n%d        %d\n", wo_li, lier.size());
    if (wo_li == wol || wo_li == 0 || lier.size() != liers)
    {
        return false;
    }
    return true;
}

bool dfs( std::vector<int>& players, int ha, int li, int wo, int *visited)
{
    if (sol.size() == wo)
    {
        //printf("Go check\n");
        if (check_true())
        {
            //printf("Go check true\n");
            return true;
        }
        //printf("Go check false\n");
        return false;
    }
    
    for (; ha > 0; --ha)
    {
        //printf("%d\n",i);
        sol.push_back(ha);
        if(dfs(players, ha-1, li, wo, visited))
        {
            return true;
        }
        else
        {
            sol.pop_back();
        }
    }
    return false;
}

int main()
{

    std::cin >> hang >> wol >> liers;

    int visited[hang+1];
    memset(visited, -1, sizeof(int)*(hang+1));//0表示狼， 1表示人
    int num;
    
    for ( int i = 1; i <= hang; ++i )
    {
        std::cin>>num;
        players.push_back(num);
    }
    solutions = dfs( players, hang, 0, wol, visited);

    if(sol.size() == 0 || !solutions)
    {
        printf("No Solution\n");
    }
    else
    {
        for ( int i = 0; i < sol.size(); ++i )
        {
            if(!i)
            {
                printf("%d",sol[i]);
            }
            else
            {
                printf(" %d", sol[i]);
            }
        }
    }
    return 0;
}
