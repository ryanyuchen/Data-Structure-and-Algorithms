# Uses python3
import sys

def fibonacci_partial_sum_naive(from_, to):
    sum = 0

    current = 0
    next  = 1

    for i in range(to + 1):
        if i >= from_:
            sum += current

        current, next = next, current + next

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

def fibonacci_partial_sum_fast(from_, to_):
    period = pisano(10)
    numfrom = (from_ + 1) % period
    numto = (to_ + 2) % period
    fib = [0] * (numto + 1)
    fib[0] = 0
    fib[1] = 1
    for i in range(2, numto+1):
        fib[i] = (fib[i-1] % 10 + fib[i-2] % 10) % 10
    #print(fib)
    if ((fib[numto] - fib[numfrom]) == 0):
        return 9
    else:
        return (fib[numto] - fib[numfrom]) % 10

if __name__ == '__main__':
    input = sys.stdin.read();
    from_, to = map(int, input.split())
    print(fibonacci_partial_sum_fast(from_, to))