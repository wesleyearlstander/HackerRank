#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int num;
    cin >> num;
    set<int> s;
    for (int i = 0; i < num; ++i) {
        int x, y;
        cin >> x >> y;
        if (x == 1) {
            s.insert(y);
        } else if (x == 2) {
            s.erase(y);
        } else {
            cout << (s.find(y) != s.end() ? "Yes" : "No") << endl;
        }
    }   
    return 0;
}



