#include <iostream>
#include <vector>
#include <algorithm>

// slow but correct algorithm
long long MaxPairwiseProductNaive(const std::vector<long long>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<long long>& numbers) {
    int n = numbers.size();
    int index1 = 0;
    int index2 = 0;

    for (int i = 0; i < n; ++i) {
        if (numbers[i] > numbers[index1]){
            index1 = i;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if ((i != index1) && (numbers[i] > numbers[index2])){
            index2 = i;
        }
    }

    return numbers[index1] * numbers[index2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    long long resultnaive = MaxPairwiseProductNaive(numbers);
    std::cout << resultnaive << "\n";
    long long resultfast = MaxPairwiseProductFast(numbers);
    std::cout << resultfast << "\n";
    return 0;
}
