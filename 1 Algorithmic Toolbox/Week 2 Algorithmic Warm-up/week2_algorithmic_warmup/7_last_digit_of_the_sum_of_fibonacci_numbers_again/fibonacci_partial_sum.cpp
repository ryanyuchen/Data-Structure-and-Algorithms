#include <iostream>
#include <vector>
using std::vector;
using namespace std;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int pisano(int modulo){
    int previous = 1;
    int current = 1;
    int result = 1;
    while (not (previous == 0 && current == 1)){
    int buffer = (previous + current) % modulo;
    previous = current;
    current = buffer;
    result += 1;
    }
    return result;
}

int get_fibonacci_partial_sum_fast(long long from, long long to) {
    int numfrom = (from + 1) % pisano(10);
    int numto = (to + 2) % pisano(10);
    int fib[numto+1];
    fib[0]=0;
    fib[1]=1;
    for(int i = 2; i <= numto; i++){
        fib[i] = (fib[i-1] % 10 + fib[i-2] % 10) % 10;
    }
    if((fib[numfrom] - fib[numto]) == 0){
        return 9;
    }
    return (fib[numfrom] - fib[numto]) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
