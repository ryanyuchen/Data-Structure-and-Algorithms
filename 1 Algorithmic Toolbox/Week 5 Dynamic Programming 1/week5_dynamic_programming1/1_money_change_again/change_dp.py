# Uses python3
import sys
from math import inf

def get_change(m):
    #write your code here
    coins = [1, 3, 4]
    MinNumCoins = [0] * (m + 1)
    
    for i in range(1, m+1):
        MinNumCoins[i] = inf
        for coin in coins:
            if i >= coin:
                NumCoins = MinNumCoins[i-coin] + 1
                if NumCoins < MinNumCoins[i]:
                    MinNumCoins[i] = NumCoins
     
    return MinNumCoins[m]

if __name__ == '__main__':
    m = int(sys.stdin.read())
    print(get_change(m))
