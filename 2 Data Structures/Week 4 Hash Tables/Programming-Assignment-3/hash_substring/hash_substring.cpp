#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

ull PolyHash(string S, ull p, ull x){
    ull hash = 0;
    for (char s: S){
        hash = ((hash * x + (int)s) % p + p) % p;
    }
    return hash;
}

vector<ull> PreComputeHashes(string T, int lp, ull p, ull x){
    int lt = T.length();
    vector<ull> H(lt - lp + 1);
    string S = T.substr(lt - lp, lt);
    H[lt - lp] = PolyHash(S, p, x);
    ull y = 1;
    for (int i = 0; i < lp; i++){
        y = (y * x) % p;
    }
    for (int i = lt - lp - 1; i > -1; i--){
        char cb = T[i];
        char ce = T[i+lp];
        H[i] = (x * H[i+1] + (int)cb - y * (int)ce) % p;
    }
    return H;
}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    int lp = s.length();
    int lt = t.length();
    ull p = 1000000007;
    ull x = rand() % (p - 1) + 1;
    ull pHash = PolyHash(s, p, x);
    vector<ull> H = PreComputeHashes(t, lp, p, x);
    for (int i=0; i < lt-lp+1; i++){
        if (H[i] != pHash){
            continue;
        }
        if (t.substr(i,i+lp) == s){
            ans.push_back(i);
        }
    }
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
