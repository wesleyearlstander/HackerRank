#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<string> names {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "Greater than 9"};
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (n > 9 || n < 1) cout << names[10];
    else cout << names[n];

    return 0;
}