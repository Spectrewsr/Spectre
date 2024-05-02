def every_m_ints_to(n, m):
     i = 0
     while (i <= n):
         yield i
         i += m
         
def every_3_ints_to_10():
    for item in every_m_ints_to(10, 3):
        yield item

            
def make_generators_generator(g):
    
    def gen(i):
        for entry in g():
            if i < 1:
                break
            i -= 1
            yield entry
    i = 1
    for e in g():
        yield gen(i)
        i += 1
        
for gen in make_generators_generator(every_3_ints_to_10):
        print("Next Generator:")
        for item in gen:
            print(item)