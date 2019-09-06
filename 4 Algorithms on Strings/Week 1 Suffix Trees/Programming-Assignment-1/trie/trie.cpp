#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <utility>

using std::map;
using std::vector;
using std::string;
using std::pair;

// map insert: http://www.cplusplus.com/reference/map/map/insert/
typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t(100);
  // write your code here
  int index = 1;
  for (int i = 0; i < patterns.size(); i++){
      int tindex = 0;
      for (int j = 0; j < patterns[i].size(); j++){
          bool match = false;
          if (tindex < t.size()){
              for (const auto & k : t[tindex]){
                  if (k.first == patterns[i][j]){
                      tindex = k.second;
                      match = true;
                      break;
                  }
              }
              if (!match){
                  t[tindex].insert(pair<char, int> (patterns[i][j], index));
                  tindex = index;
                  index += 1;                 
              }
          }
          else{
              t[tindex].insert(pair<char, int> (patterns[i][j], index));
              tindex = index;
              index += 1;              
          }          
      }
  }
  
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}