# Uses python3
import sys

def get_fibonacci_huge_naive(n, m):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % m

def get_pisano_period(m):
    a = 0 
    b = 1
    c = a + b
    for i in range(m*m):
        c = (a + b) % m
        a = b
        b = c
        if (a == 0 & b == 1):
            return i + 1
        
def get_fibonacci_huge_fast(n, m):
    remainder = n % get_pisano_period(m)
    first = 0
    second = 1
    res = remainder
    for i in range(1, remainder):
        res = (first + second) % m
        first = second
        second = res
    return res % m
    
    
    
if __name__ == '__main__':
    input = sys.stdin.read();
    n, m = map(int, input.split())
    print(get_fibonacci_huge_naive(n, m))
