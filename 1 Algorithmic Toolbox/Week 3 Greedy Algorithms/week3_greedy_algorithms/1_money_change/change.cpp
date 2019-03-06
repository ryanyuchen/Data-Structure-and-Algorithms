#include <iostream>

int get_change(int m) {
  //write your code here
  int result = 0;
  int coins[3] = {10, 5, 1};
  
  while (m != 0){
      for (int i=0; i<3; i++){
          result += m / coins[i];
          m = m % coins[i];
          }
  }
  return result;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
