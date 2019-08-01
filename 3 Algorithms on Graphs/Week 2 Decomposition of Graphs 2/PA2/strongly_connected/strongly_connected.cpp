#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::pair;
using std::stack;

vector<vector<int>> reverseGraph(vector<vector<int>> &adj){
    vector<vector<int>> r_adj(adj.size(), vector<int>());
    for (int i = 0; i < adj.size(); i++){
        for (int j = 0; j < adj[i].size(); j++){
            r_adj[adj[i][j]].push_back(i);
        }
    }
    return r_adj;
}

vector<int> dfs(vector<vector<int>> &adj, vector<int> &visited, stack<int> &order, int x){
    visited[x] = 1;
    for (int i = 0; i < adj[x].size(); i++){
        if (!visited[i]){
            visited[adj[x][i]] = 1;
            dfs(adj, visited, order, adj[x][i]);
        }
    }
    order.push(x);
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  //write your code here
  vector<int> visited(adj.size(), 0);
  stack<int> order;
  
  for (int i = 0; i < adj.size(); i++){
      if (!visited[i]){
          dfs(adj, visited, order, i);
      }
  }
  
  vector<vector<int>> r_adj = reverseGraph(adj);
  vector<int> r_visited(r_adj.size(), 0);
  stack<int> r_order;
  
  while(!order.empty()){
      int x = order.top();
      if (!visited[x]){
          dfs(adj, r_visited, r_order, x);
          result += 1;
      }
  }
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
