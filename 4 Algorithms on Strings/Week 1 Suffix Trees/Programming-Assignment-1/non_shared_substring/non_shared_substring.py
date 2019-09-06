# python3
import sys

def build_trie(patterns):
    tree = dict()
    # write your code here  
    tree[0] = {}
    index = 1
    
    for pattern in patterns:
        current = tree[0]
        '''
        In Python, = is the shallow copy.
        https://realpython.com/copying-python-objects/
        '''
        for c in pattern:
            if c in current.keys():
                current = tree[current[c]]
            else:
                current[c] = index
                tree[index] = {}
                current = tree[index]
                index = index + 1
        current['$'] = {}    
    return tree


def solve (p, q):
    patterns = [p, q]
    for i in range(1, len(p)):
        patterns.append(p[i:])
        patterns.append(q[i:])
        
    trie = build_trie(patterns)
    
    current = trie[0]
    substring = ""
    
    while '$' not in current or current == trie[0]:
        for child in current:
            substring += child
            if child not in q:
                return substring
            else:
                current = trie[current[child]]
                substring = substring[:-1]
                
    return p

p = sys.stdin.readline ().strip ()
q = sys.stdin.readline ().strip ()

ans = solve (p, q)

sys.stdout.write (ans + '\n')
