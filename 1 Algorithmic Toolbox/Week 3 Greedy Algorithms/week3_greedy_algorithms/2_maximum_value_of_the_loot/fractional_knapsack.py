# Uses python3
import sys

def get_optimal_value(capacity, weights, values):
    value = 0.
    # write your code here
    Items = []
    for i in range(len(values)):
        Items.append((values[i] / weights[i], values[i], weights[i]))
        
    Items.sort(key=lambda x:x[0])
    while (capacity > 0 and len(Items) != 0):
        item = Items.pop()
        weight = min(item[2], capacity)
        value += weight * item[0]
        capacity -= weight
        
    return value


if __name__ == "__main__":
    data = list(map(int, sys.stdin.read().split()))
    n, capacity = data[0:2]
    values = data[2:(2 * n + 2):2]
    weights = data[3:(2 * n + 2):2]
    opt_value = get_optimal_value(capacity, weights, values)
    print("{:.10f}".format(opt_value))
