def f(x):
    x = 4
    print(x)
    def g(y):
        def h(z):
            nonlocal x
            x = x+1
            print(x)
            return x+y+z
        return h
    return g

a = f(1)
print("f")
b = a(2)
print("h")
t = b(3) + b(4)