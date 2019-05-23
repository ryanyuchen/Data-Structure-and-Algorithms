#include <iostream>
#include <limits>
#include <vector>

using namespace std;
int INF = numeric_limits<int>::max();

int get_change(int m) {
  //write your code here
  vector<int> coins = {1, 3, 4};
  
  vector<int> MinNumCoins(m+1);
  
  for (int i = 1; i < m+1; i++){
      MinNumCoins[i] = INF;
      for (int j = 0; j < coins.size(); j++){
          if (i >= coins[j]){
              int NumCoins = MinNumCoins[i-coins[j]] + 1;
              if (NumCoins < MinNumCoins[i]){
                  MinNumCoins[i] = NumCoins;
              }
          }
      }
  
  }
  
  return MinNumCoins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
