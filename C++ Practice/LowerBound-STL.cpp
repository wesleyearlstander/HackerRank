#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int num;
    cin >> num;
    vector<int> v(num);
    for (int i = 0; i < num; ++i) {
        cin >> v[i];
    }
    cin >> num;
    for (int i = 0; i < num; ++i) {
        int val;
        cin >> val;
        int low = lower_bound(v.begin(), v.end(), val)-v.begin()+1;
        bool found = binary_search(v.begin(), v.end(), val);
        cout << (found ? "Yes " : "No ") << low << endl;
    }
    return 0;
}
