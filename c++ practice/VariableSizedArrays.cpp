#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int num, numQ;
    cin >> num >> numQ;
    vector<vector<int>> arrays (num);
    for (int i = 0; i < num; ++i) {
        int size;
        cin >> size;
        arrays[i] = vector<int>(size);
        for (int j = 0; j < size; ++j) {
            cin >> arrays[i][j];
        }
    }
    for (int i = 0; i < numQ; ++i) {
        int x, y;
        cin >> x >> y;
        cout << arrays[x][y] << endl;
    }
    return 0;
}