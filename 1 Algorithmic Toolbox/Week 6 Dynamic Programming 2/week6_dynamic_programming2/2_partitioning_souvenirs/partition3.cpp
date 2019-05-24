#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;

int partition3(vector<int> &A) {
    //write your code here
    int sum = std::accumulate(A.begin() , A.end() , 0);
    if (A.size() < 3 || !(sum % 3))
        return 0;

    int target = std::floor(sum / 3);
    vector<vector<int> > T (A.size() + 1 , vector<int>(target + 1 , 0));

    for (int i = 1; i <= target; ++i)
    {
        for (int j = 1; j <= A.size(); ++j)
        {
            int diff = i - A.at(j - 1);
            if (A.at(j - 1) == i || (diff > 0 && T.at(k).at(j - 1) > 0))
                if (T.at(i).at(j - 1) == 0)
                    T.at(i).at(j) = 1;
                else
                    T.at(i).at(j) = 2;
            else
                T.at(i).at(j) = T.at(i).at(j - 1);
        }
    }

    if (T.at(part).at(A.size()) == 2)
        return true;
    else return false;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> A(n);
    for (size_t i = 0; i < A.size(); ++i) {
        std::cin >> A[i];
    }
    std::cout << partition3(A) << '\n';
}