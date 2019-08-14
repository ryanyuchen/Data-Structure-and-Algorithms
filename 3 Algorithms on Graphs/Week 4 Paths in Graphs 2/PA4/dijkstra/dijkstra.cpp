#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::numeric_limits;

struct Node {
  int index, distance;
  Node(int index = 0, int distance = 0): index(index), distance(distance) {}
};

struct cmp {
	bool operator()(Node first, Node second){
		return (first.distance > second.distance) - (first.distance < second.distance);
	}
};

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code here
  vector<int> dist(adj.size(), numeric_limits<int>::max());
  dist[s] = 0;
  
  priority_queue<Node, vector<Node>, cmp> H;
  
  H.push(Node(s, dist[s]));
  while(!H.empty()) {
	Node u = H.top();
	H.pop();
	int u_index = u.index;

    for (int i = 0; i < adj[u_index].size(); i++) {
	  int v = adj[u_index][i];
	  if(dist[v] > dist[u_index] + cost[u_index][i]) {
	    dist[v] = dist[u_index] + cost[u_index][i];
        H.push(Node(v, dist[v])); 
	  }
	}	
  }
  
  if(dist[t] == numeric_limits<int>::max())
    return -1;
    
  return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
