#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

int max_of_four(int a, int b, int c, int d) {
    vector<int> values {a,b,c,d};
    return *max_element(values.begin(), values.end());
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
