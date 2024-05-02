def a(s):
    if s:
        for x in a(s[1:]):
            yield x
        #yield s
            
result = list(a('dogs'))

print(result)