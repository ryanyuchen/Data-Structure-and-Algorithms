#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>

using std::vector;
using std::pair;

struct Node{
  int x;
  int y;
  int parent;
  int rank;
  
  Node(int a, int b, int p=-1, int r=0){
      x = a;
      y = b;
      parent = p;
      rank = r;
  }
};

struct Edge{
    int u;
    int v;
    double weight;
    
    Edge(int a, int b, double w){
        u = a;
        v = b;
        weight = w;
    }
};

bool cmp(Edge a, Edge b) {
  return a.weight < b.weight;
}

void MakeSet(int i, vector<Node> &nodes, vector<int> &x, vector<int> &y) {
  nodes.push_back(Node(x[i], y[i], i));
}

double weight(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int Find(int i, vector<Node> &nodes){
    if (i != nodes[i].parent){
        nodes[i].parent = Find(nodes[i].parent, nodes);
    }
    return nodes[i].parent;
}

void Union(int u, int v, vector<Node> &nodes){
    int ru = Find(u, nodes);
    int rv = Find(v, nodes);
    
    if (ru != rv){
        if (nodes[ru].rank > nodes[rv].rank){
            nodes[rv].parent = ru;
        }
        else {
            nodes[ru].parent = rv;
            if (nodes[ru].rank == nodes[rv].rank) nodes[rv].rank += 1;
        }
    }
}

double clustering(vector<int> x, vector<int> y, int k) {
  //write your code here
  int n = x.size();
  vector<Node> nodes;
  for (int i = 0; i < n; i++){
      MakeSet(i, nodes, x, y);
  }
  
  vector<Edge> edges;
  for (int i = 0; i < n; i++){
      for (int j = i + 1; j < n; j++){
          edges.push_back(Edge(i, j, weight(x[i], y[i], x[j], y[j])));
      }
  }
  std::sort(edges.begin(), edges.end(), cmp);
  int union_num = 0;
  for (int i = 0; i < edges.size(); i++){
      Edge edge = edges[i];
      if (Find(edge.u, nodes) != Find(edge.v, nodes)){
          union_num += 1;
          Union(edge.u, edge.v, nodes);
      }
      if (union_num > n - k) return edge.weight;
  }
  return -1.;
} 

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}
