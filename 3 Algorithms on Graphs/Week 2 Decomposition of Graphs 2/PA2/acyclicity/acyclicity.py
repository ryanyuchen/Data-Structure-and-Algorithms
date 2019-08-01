#Uses python3

import sys

def dfs(adj, x, visited, stack):
    visited[x] = 1
    stack[x] = 1 ## Preorder Processing
    for i in range(len(adj[x])):
        if not visited[adj[x][i]] and dfs(adj, adj[x][i], visited, stack):
            return 1
        elif stack[adj[x][i]]:
            return 1
    stack[x] = 0 ## Postorder Processing
    return 0
    
    
def acyclic(adj):
    visited = [0 for _ in range(len(adj))]
    stack = [0 for _ in range(len(adj))]
    
    for i in range(len(adj)):
        if not visited[i]:
            if dfs(adj, i, visited, stack):
                return 1
    return 0

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
    print(acyclic(adj))
