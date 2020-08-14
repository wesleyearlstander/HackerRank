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
    for (int i = 0; i < num; i++) {
        cin >> v[i]; 
    }   
    sort(v.begin(), v.end());
    for (int i =0; i < num-1; ++i) {
        cout << v[i] << ' ';
    }
    cout << v.back() << endl;
    return 0;
}
