# python3
import sys

NA = -1

class Node:
	def __init__ (self):
		self.next = [NA] * 4

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
    
    return tree

def PrefixTrieMatching(text, trie):
    index = 0
    symbol = text[index]
    current = trie[0]
    
    while True:
        if not current:
            return True
        elif symbol in current.keys():
            current = trie[current[symbol]]
            index += 1
            if index < len(text):
                symbol = text[index]
            else:
                symbol = '@'
        else:
            return False
    
def solve (text, n, patterns):
    result = []
    trie = build_trie(patterns)
    n = len(text)
    
    for i in range(n):
        if PrefixTrieMatching(text[i:], trie):
            result.append(i)
            
    return result

if __name__ == "__main__":
    text = sys.stdin.readline().strip()
    n = int(sys.stdin.readline().strip())
    patterns = []
    for i in range(n):
        patterns += [sys.stdin.readline().strip()]

    ans = solve(text, n, patterns)
    sys.stdout.write(' '.join(map(str, ans)) + '\n')