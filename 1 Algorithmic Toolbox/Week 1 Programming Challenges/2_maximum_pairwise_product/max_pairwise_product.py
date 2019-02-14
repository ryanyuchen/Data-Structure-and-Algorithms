# -*- coding: utf-8 -*-
"""
Created on Wed Feb 13 11:25:44 2019

@author: Yu Chen
"""

# python3

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
    index1 = 0
    for i in range(1, n):
        if (numbers[i] > numbers[index1]):
            index1 = i
    index2 = 0
    for i in range(1, n):
        if ((i != index1) & (numbers[i] > numbers[index2])):
            index2 = i

    return numbers[index1] * numbers[index2]

if __name__ == '__main__':
    input_n = int(input())
    input_numbers = [int(x) for x in input().split()]
    print(max_pairwise_product_naive(input_numbers))
    print(max_pairwise_product_fast(input_numbers))
