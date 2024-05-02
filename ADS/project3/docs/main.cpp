#include <bits/stdc++.h>
using namespace std;
#define N 105
int numTips, numFruit;
bool deficiency[N][N]; // deficiency[i][j]=false 表示 i 和 j 不能一起吃。deficiency[i][j]=true 表示 i 和 j 可以一起吃。
int price[N];
int fruit[N]; // fruit[] 记录当前选择的水果的状态。sum 记录已选择的水果数量。
int ansFruit[N], ansNum = -1, ansMoney = 0; // ansFruit 记录最大水果集合，ansNum 记录最大数量的水果。ansMoney 记录最小金额。

int sumFruit[N]; // sumFruit[i]：如果我只从 'i 到 numFruit' 选择水果，我能选择的最大水果数。

void DFS(int pos, int sum, int money) // pos: 现在我选择了水果'pos'，已经选择了 'sum' 数量的水果。money：当前花费的总金额。
{
    //if(now == numFruit) { CHECK(); return; }
    for(int i = pos + 1; i <= numFruit; ++i)
    {
        // 如果现在选择的水果数量加上从 i 到 numFruit 可以选择的最大水果数仍然小于 ansNum，我们可以忽略剩余的情况。
        if(sumFruit[i] + sum < ansNum) return;
        // 如果这个水果不能和已经选择的水果一起吃，则跳过。
        if(deficiency[i][pos] == false) continue;
        bool flag = true;
        for(int j = 0; j < sum; ++j) if(deficiency[fruit[j]][i] == false) { flag = false; break; }
        if(flag == false) continue;
        // 将这个水果添加到我们当前的选择中
        fruit[sum] = i;
        DFS(i, sum + 1, money + price[i]);
    }
    if(sum > ansNum) // 记录最大数量的水果和详细信息
    {
        ansNum = sum;
        for(int i = 0; i < sum; ++i) ansFruit[i] = fruit[i];
        ansMoney = money;
    }
    else if(sum == ansNum && money < ansMoney) // 检查这种选择是否可以用更少的钱
    {
        for(int i = 0; i < sum; ++i) ansFruit[i] = fruit[i];
        ansMoney = money;
    }
    return;
}

int main()
{
    memset(deficiency, 1, sizeof(deficiency));
    scanf("%d%d", &numTips, &numFruit);
    for(int i = 0, x, y; i < numTips; ++i)
    {
        scanf("%d%d", &x, &y);
        deficiency[x][y] = deficiency[y][x] = 0;
    }
    for(int i = 0, x, y; i < numFruit; ++i)
    {
        scanf("%d%d", &x, &y);
        price[x] = y;
    }
    
    for(int i = numFruit; i > 0; --i)
    {
        fruit[0] = i;
        DFS(i, 1, price[i]);
        sumFruit[i] = ansNum;
    }

    printf("%d\n", ansNum);
    printf("%03d", ansFruit[0]);
    for(int i = 1; i < ansNum; ++i) printf(" %03d", ansFruit[i]);
    printf("\n%d\n", ansMoney);
    return 0;
}
