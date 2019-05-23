#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
int INF = numeric_limits<int>::max();

vector<int> optimal_sequence(int n) {
  vector<int> operation(n+1, 0);
  for (int i = 2; i < n+1; i++){
      int min1 = operation[i-1];
      int min2 = INF;
      int min3 = INF;
      if (i % 2 == 0) {min2 = operation[int(i/2)];}
      if (i % 3 == 0) {min3 = operation[int(i/3)];}
      int minOp = min(min1, min2, min3);
      operation[i] = minOp + 1;
  }
  
  vector<int> sequence;
  while (n > 0){
      if (n % 2 != 0 and n % 3 != 0){
          n = n - 1;
      }
      else if (n % 2 == 0 and n % 3 == 0){
          n = n / 3;
      }
      else if (n % 2 == 0){
          if (operation[n-1] < operation[n/2]) {n = n - 1;}
          else {n = n / 2;}
      }
      else if (n % 3 == 0){
          if (operation[n-1] < operation[n/3]) {n = n - 1;}
          else {n = n / 3;}
      }
  }
  
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
