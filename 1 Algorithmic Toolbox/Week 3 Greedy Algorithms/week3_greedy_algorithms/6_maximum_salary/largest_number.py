#Uses python3

import sys

def largest_number(a):
    #write your code here
    nums = map(str, a)
    nums.sort()
    
    return nums

if __name__ == '__main__':
    input = sys.stdin.read()
    data = input.split()
    a = data[1:]
    print(largest_number(a))
    
