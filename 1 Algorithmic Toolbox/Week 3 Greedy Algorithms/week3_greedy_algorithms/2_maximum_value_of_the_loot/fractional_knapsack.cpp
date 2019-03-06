#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct Item{
    int value;
    int weight;
    double ratio;
};

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  // write your code here
  std::vector<Item> Items;
  Item tmp;
  for (int i=0; i<values.size(); i++){
      tmp.value = values[i];
      tmp.weight = weights[i];
      tmp.ratio = (double)(values[i]) / (double)(weights[i]);
      Items.push_back(tmp);
  }
  
  struct compareItem{
      bool operator()(Item x, Item y){return (x.ratio <= y.ratio);}
  }mycompare;
  std::sort(Items.begin(), Items.end(), mycompare);
  
  while (capacity > 0 && Items.size() != 0){
      Item tmpitem = Items.back();
      Items.pop_back();
      int tmpweight = std::min(tmpitem.weight, capacity);
      value += (double)(tmpweight) * tmpitem.ratio;
      capacity -= tmpweight;
  }
  
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
