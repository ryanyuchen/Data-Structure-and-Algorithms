#include <iostream>
#include <vector>

using namespace std;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    // write your code here
    if (n <= 1){
        return n;
    }
    else{
        vector<int> res(n+1);
        res[0] = 0;
        res[1] = 1;
        for (int i=2; i<n+1; i++){
            res[i] = (res[i-1] % 10) + (res[i-2] % 10);
        }
        return res[n];
    }

}

int main() {
    int n;
    cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    cout << c << '\n';
    int res2 = get_fibonacci_last_digit_fast(n);
    cout << res2 << '\n';
    }
