a = [1, 2, 3, 4, 5, 6]
x = [a[i//2] if i % 2 == 0 else a[i//2  + len(a)//2] for i in range(len(a))]
print(x)
