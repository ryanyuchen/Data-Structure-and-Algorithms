#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  vector<int> color(adj.size(), -1);
  color[0] = 1;
  
  queue<int> Q;
  Q.push(0);
  
  while (!Q.empty()){
      int u = Q.front();
      Q.pop();
      
      for (int i = 0; i < adj[u].size(); i++){
          int v = adj[u][i];
          if (color[v] == -1){
              Q.push(v);
              color[v] = 1 - color[u];
          }
          else if (color[u] == color[v]) return 0;
      }
      
  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
