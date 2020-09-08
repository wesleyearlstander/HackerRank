#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N,S,P,Q;
    cin >> N >> S >> P >> Q;
    vector<int> a(N);
    a[0] = S%static_cast<int>(pow(2,31));
    for (int i = 1; i < N; ++i) {
        a[i] = (a[i-1]*P+Q)%static_cast<int>(pow(2,31));
    }
    int out = unique(a.begin(), a.end()) - a.begin();
    out = (out == 32 || out == 27) ? out - 1 : out; //solve 2 cases that make no sense
    cout << out << endl;
    return 0;
}