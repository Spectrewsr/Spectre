def count_partitions(n, m):
    if n == 0:
        return 1
    elif n < 0:
        return 0
    elif m == 0:
        return 0
    else:
        with_m = count_partitions(n - m, m)
        without_m = count_partitions(n, m - 1)
        return with_m + without_m

# 示例：计算正整数 5 的划分，使用部分不超过大小 3
result = count_partitions(6, 4)
print("划分数量:", result)