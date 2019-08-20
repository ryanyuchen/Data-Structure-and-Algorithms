#Uses python3
import sys
import math

class Node:
    def __init__(self, a, b, p):
        self.x = a
        self.y = b
        self.parent = p
        self.rank = 0

class Edge:
    def __init__(self, a, b, w):
        self.u = a
        self.v = b
        self.weight = w
        
def MakeSet(i, nodes, x, y):
    nodes.append(Node(x[i], y[i], i))
    
def weight(x1, y1, x2, y2):
  return math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
    
def Find(i, nodes):
    if i != nodes[i].parent:
        nodes[i].parent = Find(nodes[i].parent, nodes)
    return nodes[i].parent

def Union(u, v, nodes):
    ru = Find(u, nodes)
    rv = Find(v, nodes)
    if (ru != rv):
        if nodes[ru].rank > nodes[rv].rank:
            nodes[rv].parent = ru
        else:
            nodes[ru].parent = rv
            if nodes[ru].rank == nodes[rv].rank:
                nodes[rv].rank += 1
 
def clustering(x, y, k):
    #write your code here
    n = len(x)
    nodes = []
    for i in range(n):
        MakeSet(i, nodes, x, y)
    edges = []
    for i in range(n):
        for j in range(i+1, n):
            edges.append(Edge(i, j, weight(x[i], y[i], x[j], y[j])))
    edges = sorted(edges, key=lambda x: x.weight)
    union_num = 0
    for edge in edges:
        if Find(edge.u, nodes) != Find(edge.v, nodes):
            union_num += 1
            Union(edge.u, edge.v, nodes)
        if union_num > n - k:
            return edge.weight       
    return -1.


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    data = data[1:]
    x = data[0:2 * n:2]
    y = data[1:2 * n:2]
    data = data[2 * n:]
    k = data[0]
    print("{0:.9f}".format(clustering(x, y, k)))
