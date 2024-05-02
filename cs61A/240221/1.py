
def close(n, smallest=10, d=10):
    # 递归结束条件：当 n 等于 0 时，返回 0
    if n == 0:
        return 0
    
    no = close(n // 10, smallest, d)
    
    if smallest > n % 10:
        
        yes = close(n // 10, min(smallest, d), n % 10) * 10 + n % 10
    
        return max(yes, no)
    
    return no