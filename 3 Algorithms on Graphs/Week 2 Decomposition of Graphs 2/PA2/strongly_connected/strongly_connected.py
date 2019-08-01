#Uses python3

import sys

sys.setrecursionlimit(200000)

def dfs(adj, visited, order, x):
    #write your code here
    visited[x] = 1
    # Recur for all the vertices adjacent to this vertex
    for i in range(len(adj[x])):
        if not visited[adj[x][i]]:
            visited[adj[x][i]] = 1
            dfs(adj, visited, order, adj[x][i])
    # All vertices reachable from x are processed by now, push x to Stack
    order.append(x)

def reverseGraph(adj):
    '''
    https://stackoverflow.com/questions/40378152/inverse-of-adjacency-list-in-ov-e
    Runtime O(|V| + |E|)
    '''
    r_adj = [[] for _ in range(len(adj))]
    for i in range(len(adj)):
        for j in range(len(adj[i])):
            r_adj[adj[i][j]].append(i)
    return r_adj

def number_of_strongly_connected_components(adj):
    result = 0
    #write your code here
    visited = [0] * len(adj)
    order = []
    
    # Fill vertices in stack according to their postvisit number
    for i in range(len(adj)):
        if not visited[i]:
            dfs(adj, visited, order, i)
    
    # Get the reversed adj list
    r_adj = reverseGraph(adj)
    visited = [0] * len(r_adj)
    
    while order:
        x = order.pop()
        if not visited[x]:
            dfs(r_adj, visited, [], x)
            result += 1
    
    return result

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
    print(number_of_strongly_connected_components(adj))
