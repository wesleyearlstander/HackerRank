#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int sum = 0;
    int val = 0;
    for (int i = 0; i < 3; ++i) {
        cin >> val;
        sum += val;
    }
    cout << sum <<endl;
    return 0;
}

