#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.
string UniqueChar(const string& S){
    sort(S.begin(), S.end());
    string result = S.substr(0);
    for (int i = 1; i < S.size(); i++){
        if (S.substr(i) != S.substr(i - 1)){
            result = result + S.substr(i);
        }
    }
    return result;
}

vector<int> SortCharacters(const string& S){
    vector<int> order(S.size(), 0);
    string Sigma = UniqueChar(S);
    vector<int> count(Sigma.size(), 0);
    
    for (int i = 0; i < S.size(); i++){
        size_t idx = Sigma.find(S.substr(i));
        count[idx] = count[idx] + 1;
    }
    for (int j = 1; j < Sigma.size(); j++){
        count[j] = count[j] + count[j - 1];
    }
    for (int i = S.size() - 1; i > -1; i--){
        string c = S.substr(i);
        size_t idx = Sigma.find(c);
        count[idx] = count[idx] - 1;
        order[count[idx]] = i;
    }
    return order;
}

vector<int> ComputeCharClasses(const string& S, vector<int>& order){
    vector<int> clss(S.size(), 0);
    for (int i = 1; i < S.size(); i++){
        if (S[order[i]] != S[order[i - 1]]){
            clss[order[i]] = clss[order[i - 1]] + 1;
        }
        else{
            clss[order[i]] = clss[order[i - 1]];
        }
    }
    return clss;
}

vector<int> SortDoubled(const string& S, int L, vector<int>& order, vector<int>& clss){
    vector<int> count(S.size(), 0);
    vector<int> newOrder(S.size(), 0);
    
    for (int i = 0; i < S.size(); i++){
        count[clss[i]] = count[clss[i]] + 1;
    }
    for (int j = 1; j < S.size(); j++){
        count[j] = count[j] + count[j - 1];
    }
    for (int i = S.size() - 1; i > -1; i--){
        int start = (order[i] - L + S.size()) % S.size();
        int cl = clss[start];
        count[cl] = count[cl] - 1;
        newOrder[count[cl]] = start;
    }
    return newOrder;
}

vector<int> UpdateClasses(vector<int>& newOrder, vector<int>& clss, int L){
    int n = newOrder.size();
    vector<int> newClass(n, 0);
    
    for (int i = 0; i < n; i++){
        int cur = newOrder[i];
        int prev = newOrder[i - 1];
        int mid = (cur + L);
        int midPrev = (prev + L) % n;
        if (clss[cur] != clss[prev] || clss[mid] != clss[midPrev]){
            newClass[cur] = newClass[prev] + 1;
        }
        else{
            newClass[cur] = newClass[prev];
        }
    }
    return newClass;
}

vector<int> BuildSuffixArray(const string& text) {
  vector<int> order = SortCharacters(text);
  vector<int> clss = ComputeCharClasses(text, order);
  int L = 1;
  while (L < text.size()){
      order = SortDoubled(text, L, order, clss);
      clss = UpdateClasses(order, clss, L);
      L = 2 * L;
  }
  return order;
}

int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
