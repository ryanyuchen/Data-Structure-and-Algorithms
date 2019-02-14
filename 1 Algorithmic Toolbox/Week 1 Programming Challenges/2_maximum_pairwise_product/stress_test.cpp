#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::vector;
using std::cin;
using std::cout;
using std::max;

// slow but correct algorithm
long long MaxPairwiseProductNaive(const vector<long long>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const vector<long long>& numbers) {
    int n = numbers.size();
    int index1 = -1;
    int index2 = -1;

    for (int i = 0; i < n; ++i) {
        if ((index1 == -1) || (numbers[i] > numbers[index1])){
            index1 = i;
        }
    }
    
    for (int j = 0; j < n; ++j) {
        if ((j != index1) && ((index2 == -1) || (numbers[j] > numbers[index2]))){
            index2 = j;
        }
    }
    
    //cout << index1 << ' ' << index2;

    return ((long long) (numbers[index1])) * numbers[index2];
}

int main() {
    int N = 10;
    int M = 100000;
    while (true){
        int n = rand() % N + 2;
        cout << n << "\n";
        vector<long long> test;
        for (int i = 0; i < n; ++i){
            test.push_back(rand() % M);
        }
        for (int i = 0; i < n; ++i){
            cout << test[i] << ' ';
        }
        cout << "\n";
        long long res1 = MaxPairwiseProductNaive(test);
        long long res2 = MaxPairwiseProductFast(test);
        if (res1 != res2){
            cout << "Wrong Answer: " << res1 << ' ' << res2 << "\n";
            break;
        }
        else{
            cout << "OK\n";
        }
    }
}
