#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::istringstream;
using std::map;
using std::string;
using std::vector;
using std::cout;
using std::endl;
using namespace std;

// Preprocess the Burrows-Wheeler Transform bwt of some text
// and compute as a result:
//   * starts - for each character C in bwt, starts[C] is the first position 
//       of this character in the sorted array of 
//       all characters of the text.
//   * occ_count_before - for each character C in bwt and each position P in bwt,
//       occ_count_before[C][P] is the number of occurrences of character C in bwt
//       from position 0 to position P inclusive.
void PreprocessBWT(const string& bwt, 
                   map<char, int>& starts, 
                   map<char, vector<int> >& occ_count_before) {
  // Implement this function yourself
  string LastCol = bwt;
  string FirstCol = bwt;
  sort(FirstCol.begin(), FirstCol.end());
  vector<int> counter(bwt.size(), 0);
  
  for (int i = 0; i < bwt.size(); i++){
      starts[bwt[i]]++;
      occ_count_before[bwt[i]] = counter;
  }
  for (auto& pair: starts){
      pair.second = FirstCol.find(pair.first);
      for (int i = 1; i < bwt.size() + 1; i++){
          if (bwt[i - 1] == pair.first){
              occ_count_before[pair.first][i] = occ_count_before[pair.first][i - 1] + 1;
          }
          else{
              occ_count_before[pair.first][i] = occ_count_before[pair.first][i - 1];
          }
      }
  }
}

// Compute the number of occurrences of string pattern in the text
// given only Burrows-Wheeler Transform bwt of the text and additional
// information we get from the preprocessing stage - starts and occ_counts_before.
int CountOccurrences(const string& pattern, 
                     const string& bwt, 
                     const map<char, int>& starts, 
                     const map<char, vector<int> >& occ_count_before) {
  // Implement this function yourself
  string pattern_cp = pattern;
  int top = 0;
  int bottom = bwt.size() - 1;
  while (top <= bottom) {
    if (!pattern_cp.empty()) {
      char symbol = pattern_cp.back();
      pattern_cp.pop_back();
      if (occ_count_before.find(symbol)->second[bottom + 1] > occ_count_before.find(symbol)->second[top]) {
        top = starts.find(symbol)->second + occ_count_before.find(symbol)->second[top];
        bottom = starts.find(symbol)->second + occ_count_before.find(symbol)->second[bottom + 1] - 1;
      } 
      else {
        return 0;
      }
    } 
    else {
      return bottom - top + 1;
    }
  }
}
     

int main() {
  string bwt;
  cin >> bwt;
  int pattern_count;
  cin >> pattern_count;
  // Start of each character in the sorted list of characters of bwt,
  // see the description in the comment about function PreprocessBWT
  map<char, int> starts;
  // Occurrence counts for each character and each position in bwt,
  // see the description in the comment about function PreprocessBWT
  map<char, vector<int> > occ_count_before;
  // Preprocess the BWT once to get starts and occ_count_before.
  // For each pattern, we will then use these precomputed values and
  // spend only O(|pattern|) to find all occurrences of the pattern
  // in the text instead of O(|pattern| + |text|).
  PreprocessBWT(bwt, starts, occ_count_before);
  for (int pi = 0; pi < pattern_count; ++pi) {
    string pattern;
    cin >> pattern;
    int occ_count = CountOccurrences(pattern, bwt, starts, occ_count_before);
    printf("%d ", occ_count);
  }
  printf("\n");
  return 0;
}
