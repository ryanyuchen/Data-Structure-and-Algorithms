#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int dfs(vector<vector<int> > &adj, int x, vector<int> &visited, vector<int> &stack){
    visited[x] = 1;
    stack[x] = 1;
    
    for (vector<int>::const_iterator it = adj[x].begin(); it != adj[x].end(); ++it){
        if (!visited[*it] && dfs(adj, *it, visited, stack)) return 1;
        else if (stack[*it]) return 1;
    }
    stack[x] = 0;
    return 0;
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
  vector<int> visited(adj.size());
  vector<int> stack(adj.size());
  
  for (int i = 0; i < adj.size(); i++){
      if (!visited[i]){
          if (dfs(adj, i, visited, stack)) return 1;
      }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
