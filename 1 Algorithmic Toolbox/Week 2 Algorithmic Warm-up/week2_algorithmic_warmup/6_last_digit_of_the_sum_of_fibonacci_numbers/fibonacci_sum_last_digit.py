# Uses python3
import sys

'''
Sum of nth Fibonacci series = F(n+2) -1
Then pisano period of module 10 = let n+2 mod (60) = m then find F(m) mod(10)-1
'''

def fibonacci_sum_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    sum      = 1

    for _ in range(n - 1):
        previous, current = current, previous + current
        sum += current

    return sum % 10

def pisano(modulo):
    previous = 1
    current = 1
 
    result = 1
    while not (previous == 0 and current == 1):  # 1
        buffer = (previous + current) % modulo  # 2
        previous = current
        current = buffer
 
        result += 1
 
    return result

def fibonacci_sum_fast(n):
    period = pisano(10)
    #print(period)
    num = (n + 2) % period
    fib = [0] * (num + 1)
    fib[0] = 0
    fib[1] = 1
    for i in range(2, num+1):
        fib[i] = (fib[i-1] % 10 + fib[i-2] % 10) % 10
    #print(fib)
    if (fib[num] == 0):
        return 9
    else:
        return (fib[num] % 10 - 1)
    

if __name__ == '__main__':
    input = sys.stdin.read()
    n = int(input)
    print(fibonacci_sum_fast(n))
