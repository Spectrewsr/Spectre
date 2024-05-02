item, n = [], 2

class Airpods:
    cost, k = 200, 0
    f = lambda self: print(self)
    
    def __init__(self):
        Airpods.k += 1
        Airpods.f(self)
        item.extend([self])
        
    def __repr__(self):
        return (Airpods.k < 2 and 'lonely') or "pair"
    
class TwoAirpods(Airpods):
    
    def __init__(self):
        self.k = 2
        Airpods.__init__(self)
        Airpods.__init__(self)
        
lost = Airpods()
print("\n")
print(str(lost))
print("\n")
print(Airpods.k)
willbelost = TwoAirpods()
print(Airpods.k)
print("\n")
print(str(lost))