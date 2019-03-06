# Uses python3
import sys

def get_change(m):
    #write your code here
    result = 0
    coins = [10, 5, 1]
    while m != 0:
        for coin in coins:
            result += m // coin
            m = m % coin
    
    return result

if __name__ == '__main__':
    m = int(sys.stdin.read())
    print(get_change(m))
