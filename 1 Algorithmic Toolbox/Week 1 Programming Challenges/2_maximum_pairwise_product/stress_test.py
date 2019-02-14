# -*- coding: utf-8 -*-
"""
Created on Wed Feb 13 11:25:44 2019

@author: Yu Chen
"""

# python3
import random

# slow but correct algorithm
def max_pairwise_product_naive(numbers):
    n = len(numbers)
    max_product = 0
    for first in range(n):
        for second in range(first + 1, n):
            max_product = max(max_product,
                              numbers[first] * numbers[second])

    return max_product

def max_pairwise_product_fast(numbers):
    n = len(numbers)
    index1 = -1
    for i in range(n):
        if ((index1 == -1) | (numbers[i] > numbers[index1])):
            index1 = i
    index2 = -1
    for j in range(n):
        if ((j != index1) & ((index2 == -1) | (numbers[j] > numbers[index2]))):
            index2 = j

    return numbers[index1] * numbers[index2]

if __name__ == '__main__':
    N = 10
    M = 100000
    while(True):
        num = random.randint(2, N)
        print("\n")
        test = []
        for i in range(num):
            test.append(random.randit(M))
        for i in range(num):
            print(test[i], end=" ")
        print("\n")
        res1 = max_pairwise_product_naive(test)
        res2 = max_pairwise_product_fast(test)
        if (res1 != res2):
            print("Wrong Answer: ", res1, " ", res2, "\n")
        else:
            print("OK\n")
    
