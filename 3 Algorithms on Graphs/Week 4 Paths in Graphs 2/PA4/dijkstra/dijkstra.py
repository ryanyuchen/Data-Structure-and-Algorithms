#Uses python3

import sys
import queue

class Node(object):
    def __init__(self, index, distance):
        self.index = index
        self.distance = distance
        
    def __gt__(self, other):
        return self.distance > other.distance
    
    def __lt__(self, other):
        return self.distance < other.distance
    
    def __eq__(self, other):
        return self.distance == other.distance
        
def distance(adj, cost, s, t):
    #write your code here
    dist = [float('inf')] * len(adj)
    dist[s] = 0
    
    H = queue.PriorityQueue()
    H.put(Node(s, dist[s]))
    while not H.empty():
        u = H.get()
        u_index = u.index
        for v in adj[u_index]:
            v_index = adj[u_index].index(v)
            if dist[v] > dist[u_index] + cost[u_index][v_index]:
                dist[v] = dist[u_index] + cost[u_index][v_index]
                H.put(Node(v, dist[v]))
    
    if dist[t] == float('inf'):
        return -1
    
    return dist[t]


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(zip(data[0:(3 * m):3], data[1:(3 * m):3]), data[2:(3 * m):3]))
    data = data[3 * m:]
    adj = [[] for _ in range(n)]
    cost = [[] for _ in range(n)]
    for ((a, b), w) in edges:
        adj[a - 1].append(b - 1)
        cost[a - 1].append(w)
    s, t = data[0] - 1, data[1] - 1
    print(distance(adj, cost, s, t))
