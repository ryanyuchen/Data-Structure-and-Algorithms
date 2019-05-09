#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;

using namespace std;

class Point{
    public:
    int x, y;
};

int compareX(const void* a, const void* b){
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2 ->x);
}

int compareY(const void* a, const void* b){
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2 ->y);
}

float dist(Point p1, Point p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.x - p2.x) );
}

float bruteForce(Point P[], int n){
    float min_dist = FLT_MAX;
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j){
            if (dist(P[i], P[j]) < min_dist){
                min_dist = dist(P[i], P[j]);
            }
        }
    }
    return min_dist;
}

float min(float x, float y){  
    return (x < y)? x : y;  
}

float stripClosest(Point strip[], int size, float d){  
    float min = d;  
  
    qsort(strip, size, sizeof(Point), compareY);  
    for (int i = 0; i < size; ++i)  
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)  
            if (dist(strip[i],strip[j]) < min)  
                min = dist(strip[i], strip[j]);  
  
    return min;  
} 

float closestUtil(Point P[], int n)  
{  
    // If there are 2 or 3 points, then use brute force  
    if (n <= 3)  
        return bruteForce(P, n);  
   
    int mid = n/2;  
    Point midPoint = P[mid];  
   
    float dl = closestUtil(P, mid);  
    float dr = closestUtil(P + mid, n - mid);  
    float d = min(dl, dr);  
  
    Point strip[n];  
    int j = 0;  
    for (int i = 0; i < n; i++)  
        if (abs(P[i].x - midPoint.x) < d)  
            strip[j] = P[i], j++;  
            
    return min(d, stripClosest(strip, j, d) );  
} 

double minimal_distance(vector<int> x, vector<int> y) {
  //write your code here
  int N = x.size();
  Point P[];
  for (int i = 0; i < n; ++i){
      P[i].x = x[i];
      P[i].y = y[i];
  }
  
  return closestUtil(P, N);
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}


//https://www.geeksforgeeks.org/closest-pair-of-points-using-divide-and-conquer-algorithm/
