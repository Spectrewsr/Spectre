from lab09 import *

def pluck(pine):
    
    def plucker(k):
        
        def pluck_one_leaf(cyprus):
            
            if cyprus.label == k:
                return 'Hey, nor valid'
            plucked_branches = []
            for b in cyprus.braches:
                skip_this_leaf = b.is_leaf() and b.label == k
                if not skip_this_leaf:
                    plucked_branch_or_error = pluck_one_leaf(b)
                    if isinstance( plucked_branch_or_error, str):
                        return plucked_branch_or_error
                    else:
                        plucked_branches.append(plucked_branch_or_error)_
                        
            return Tree( cyprus, plucked_branches)