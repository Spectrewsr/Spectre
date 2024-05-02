#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // 设置玩家总数N，狼人数量M，撒谎者数量L（全是狼人）
    int N = 5; // 玩家总数
    int M = 2; // 狼人数量
    int L = 2; // 撒谎者数量

    // 创建玩家数组，用正数表示人类，用负数表示狼人
    std::vector<int> players(N);
    for (int i = 0; i < N; ++i) {
        players[i] = (i < M) ? -(i+1) : (i+1); // 前M个玩家是狼人
    }

    // 打乱数组，随机分配狼人和人类
    std::random_shuffle(players.begin(), players.end());

    // 选择L个狼人来撒谎（我们知道数组的前M个是狼人）
    for (int i = 0; i < L; ++i) {
        // 选择一个人类并错误地声明他们的身份
        int human_index;
        do {
            human_index = rand() % N;
        } while (players[human_index] < 0); // 确保选择的是人类

        players[i] = -players[human_index]; // 狼人错误地声明人类的身份
    }

    // 输出玩家陈述
    for (int i = 0; i < N; ++i) {
        std::cout << "Player #" << (i+1) << " said: Player #" << abs(players[i])
                  << " is a " << ((players[i] > 0) ? "human" : "werewolf") << ".\n";
    }

    return 0;
}
