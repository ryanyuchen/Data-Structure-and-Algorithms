# Uses python3
import sys

def partition3(A):
    total = sum(A)
    if len(A) < 3 or total % 3:
        return 0
    target = total // 3
    T = [[0] * (len(A) + 1) for _ in range(target + 1)]

    for i in range(1, target + 1):
        for j in range(1, len(A) + 1):
            diff = i - A[j - 1]
            if A[j - 1] == i or (diff > 0 and T[diff][j - 1]):
                T[i][j] = 1 if T[i][j - 1] == 0 else 2
            else:
                T[i][j] = T[i][j - 1]

    return 1 if T[-1][-1] == 2 else 0

    return 0

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *A = list(map(int, input.split()))
    print(partition3(A))

