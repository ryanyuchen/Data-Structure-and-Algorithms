#include <iostream>
using namespace std;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
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

int fibonacci_sum_fast(long long n) {
    cout << pisano(10) << "\n";
    int num = (n + 2) % pisano(10);
    int fib[n+1];
    fib[0]=0;
    fib[1]=1;
    for(int i = 2; i <= num; i++){
        fib[i] = (fib[i-1] % 10 + fib[i-2] % 10) % 10;
    }
    if(fib[num] == 0){
        return 9;
    }
    return (fib[num]%10-1);
}


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
