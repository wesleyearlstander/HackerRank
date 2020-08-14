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
    for (int i =0; i < num; ++i) {
        cin >> v[i]; 
    }
    int remove;
    cin >> remove;
    v.erase(v.begin()+remove-1);
    cin >> remove >> num;
    v.erase(v.begin()+remove-1,v.begin()+num-1);
    cout << v.size() << endl;
    for (int i = 0; i < v.size()-1; ++i) {
        cout << v[i] << ' ';
    }
    cout << v.back() << endl;
    return 0;
}
