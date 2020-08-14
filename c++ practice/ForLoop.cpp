#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int start;
    int end;
    cin >> start >> end;
    if (start > end) {
        int temp = start;
        start = end;
        end = temp;
    }
    vector<string> names {"odd","one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "even"};
    for (int i = start; i <= end; i++) {
        if (i < 10 && i > 0) cout << names[i] << endl;
        else if (i > 9) {
            if (i%2) cout << names[0] << endl;
            else cout << names[10] << endl;
        }
    }
    return 0;
}
