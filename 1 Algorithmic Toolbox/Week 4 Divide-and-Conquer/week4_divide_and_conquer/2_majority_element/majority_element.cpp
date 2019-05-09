#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  
  int leftmajority = get_majority_element(a, left, int((left+right-1)/2+1));
  int rightmajority = get_majority_element(a, int((left+right-1)/2+1), right);
  
  int leftcount = 0;
    for (int i = left; i < right; i++) {
        if (a[i] == leftmajority) leftcount += 1;
    }
    if (leftcount > (right - left) / 2) return leftcount;

    int rightcount = 0;
    for (int i = left; i < right; i++) {
        if (a[i] == rightmajority) rightcount += 1;
    }
    if (rightcount > (right - left) / 2) return rightcount;
    
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
