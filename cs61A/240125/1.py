def repeat(k):
    return detector(is_false)(k)

def detector(f):
    def g(i):
        if f(i):
            print(i)
        return detector(equal_to_i_or_f(i))
    
    def equal_to_i_or_f(i):
        def inner(j):
            return j == i or f(j)
        return inner

    return g

def is_false(j):
    return False

repeat(1)(7)(1)
