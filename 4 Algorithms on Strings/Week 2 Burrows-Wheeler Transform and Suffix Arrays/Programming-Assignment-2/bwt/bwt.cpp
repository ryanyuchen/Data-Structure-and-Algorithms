#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string BWT(const string& text) {
  string result = "";
  vector<string> m(text.size());
  string newtext = text + text;
  
  for (int i = 0; i < m.size(); i++){
      m[i] = newtext.substr(i, i + text.size());
  }
  
  sort(m.begin(), m.end());
  
  for (int i = 0; i < m.size(); i++){
      result += m[i].substr(text.size() - 1 , 1);
  }

  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}