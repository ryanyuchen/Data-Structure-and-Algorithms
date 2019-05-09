# Uses python3
import sys

def get_majority_element(a, left, right):
    if left == right:
        return -1
    if left + 1 == right:
        return a[left]
    #write your code here
    
    leftmajority = get_majority_element(a, left, (left + right - 1) // 2 + 1)
    rightmajority = get_majority_element(a, (left + right - 1) // 2 + 1, right)
    
    leftcount = 0
    for i in range(left, right):
        if a[i] == leftmajority:
            leftcount += 1
    if leftcount > (right - left) / 2:
        return leftcount
    
    rightcount = 0
    for i in range(left, right):
        if a[i] == rightmajority:
            rightcount += 1
    if rightcount > (right - left) / 2:
        return rightcount
    
    return -1

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    if get_majority_element(a, 0, n) != -1:
        print(1)
    else:
        print(0)
