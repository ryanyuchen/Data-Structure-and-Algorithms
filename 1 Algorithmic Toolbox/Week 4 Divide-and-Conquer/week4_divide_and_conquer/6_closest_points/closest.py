#Uses python3
import sys
from math import sqrt

def check_middle_line(points, d):
    min_dist = d
    N = len(points)
    points = sorted(points, key=lambda x: x[1])
    for i in range(N-1):
        p1 = points[i]
        for j in range(i+1, min(i+9, N)):
            p2 = points[j]
            dist = sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

            if dist < min_dist:
                min_dist = dist
    return min_dist


def minimum_distance_bruteforce(x, y):
    points = list(zip(x, y))

    min_dist = 10**18

    for i in range(len(points)-1):
        p1 = points[i]
        for j in range(i+1, len(points)):
            p2 = points[j]
            dist = sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

            if dist < min_dist:
                min_dist = dist
    return min_dist

def minimum_distance(x, y):
    #write your code here
    points = list(zip(x, y))
    points = sorted(points, key=lambda x:x[0]) # sort the points based on x
    
    N = len(points)
    if N <=3:
        x, y = [list(t) for t in zip(*points)]
        return minimum_distance_bruteforce(x, y)
    
    mid = N // 2
    
    xleft, yleft = [list(t) for t in zip(*points[:mid])]
    dleft = minimum_distance(xleft, yleft)
    xright, yright = [list(t) for t in zip(*points[mid:])]
    dright = minimum_distance(xright, yright)
    dmin = min(dleft, dright)
    
    points_mid = [p for p in points if abs(points[mid][0] - p[0]) < dmin]
    mind = check_middle_line(points_mid, dmin)
    
    return mind

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    x = data[1::2]
    y = data[2::2]
    print("{0:.9f}".format(minimum_distance(x, y)))
