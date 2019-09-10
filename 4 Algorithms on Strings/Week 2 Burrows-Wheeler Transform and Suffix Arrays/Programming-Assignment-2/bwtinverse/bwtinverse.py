# python3
import sys

def InverseBWT(bwt):
    # write your code here
    result = ""
    n = len(bwt)
    last = [(char, index) for (index, char) in enumerate(bwt)]
    first = sorted(last)
    
    elem = first[0]
    for i in range(n):
        elem = first[elem[1]]
        result += elem[0]
    
    return result


if __name__ == '__main__':
    bwt = sys.stdin.readline().strip()
    print(InverseBWT(bwt))