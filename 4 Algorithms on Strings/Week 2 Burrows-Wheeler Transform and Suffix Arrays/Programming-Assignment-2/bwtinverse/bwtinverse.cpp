#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::make_pair;

string InverseBWT(const string& bwt) {
  string text = "";

  // write your code here
  vector<pair<char, int>> first(bwt.size());
  for (int i = 0; i < bwt.size(); i++){
      first[i] = make_pair(bwt[i], i);
  }
  sort(first.begin(), first.end());
  
  pair<char, int> elem = first[0];
  for (int i = 0; i < bwt.size(); i++) {
  	elem = first[elem.second];
  	text += elem.first;
  }

  return text;
}

int main() {
  string bwt;
  cin >> bwt;
  cout << InverseBWT(bwt) << endl;
  return 0;
}
