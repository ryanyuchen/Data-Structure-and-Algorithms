# python3
import sys

NA = -1

class Node:
	def __init__ (self):
		self.next = [NA] * 4
		self.patternEnd = False

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

def PrefixTrieMatching(text, trie, externalIndex):
    index = 0
    symbol = text[index]
    current = trie[0]
    result = -1
    
    while True:
        if not current:
            return result
        
        if '$' in current:
            return result
        
        if symbol in current.keys():
            current = trie[current[symbol]]
            index += 1
            result = externalIndex
            if index < len(text):
                symbol = text[index]
            elif '$' in current:
                return result
            else:
                symbol = '@'
                result = -1
        else:
            return result if '$' in current else -1
        
def solve (text, n, patterns):
    result = []
    trie = build_trie(patterns)
    #write your code here
    for i in range(len(text)):
        found = PrefixTrieMatching(text[i:], trie, i)
        if found != -1:
            result.append(found)
    return result

text = sys.stdin.readline ().strip ()
n = int (sys.stdin.readline ().strip ())
patterns = []
for i in range (n):
	patterns += [sys.stdin.readline ().strip ()]

ans = solve (text, n, patterns)

sys.stdout.write (' '.join (map (str, ans)) + '\n')
