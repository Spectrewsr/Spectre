from operator import sub, mul

fact = lambda n: 1 if n == 1 else mul(n, fact(sub(n, 1)))
print(fact(5))
print( sub(5, 1))