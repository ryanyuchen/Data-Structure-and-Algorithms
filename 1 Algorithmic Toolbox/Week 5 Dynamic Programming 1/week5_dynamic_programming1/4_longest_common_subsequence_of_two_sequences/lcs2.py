#Uses python3
import numpy as np
import sys

def lcs2(a, b):
    #write your code here
    T = np.zeros(shape=(len(a)+1, len(b)+1), dtype=int)
    
    for i in range(1, len(a)+1):
        for j in range(1, len(b)+1):
            if a[i-1] == b[j-1]:
                T[i, j] = T[i-1, j-1] + 1
            else:
                T[i, j] = max(T[i-1, j], T[i, j-1])
    
    return T[len(a), len(b)]

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))

    n = data[0]
    data = data[1:]
    a = data[:n]

    data = data[n:]
    m = data[0]
    data = data[1:]
    b = data[:m]

    print(lcs2(a, b))
