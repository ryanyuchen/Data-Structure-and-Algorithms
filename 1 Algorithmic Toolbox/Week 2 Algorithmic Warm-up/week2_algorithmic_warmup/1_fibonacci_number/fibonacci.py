# Uses python3
import random

def calc_fib(n):
    if (n <= 1):
        return n

    return calc_fib(n - 1) + calc_fib(n - 2)

def calc_fib_fast(n):
    if (n <= 1):
        return n
    else:
        res = [None] * (n+1)
        res[0] = 0
        res[1] = 1
        for i in range(2,n+1):
            res[i] = res[i-1] + res[i-2]
        return res[n]

def stress_test(m):
    k = 0
    while (k < 100):
        n = random.randint(1, m)
        res1 = calc_fib(n)
        res2 = calc_fib_fast(n)
        print("\n")
        if (res1 != res2):
            print("Wrong Answer: ", res1, " ", res2, "\n")
            k = k + 1
            break
        else:
            print("OK\n")
            k = k + 1
        
    
stress_test(40)    
    
    
n = int(input())
print(calc_fib(n))
print(calc_fib_fast(n))
