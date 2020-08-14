#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int num;
    cin >> num;
    map<string,int> m;
    for (int i = 0; i < num; ++i) {
        int Q, Y;
        string X;
        cin >> Q >> X;
        map<string,int>::iterator it = m.find(X);
        if (Q == 1) {
            cin >> Y;
            if (it == m.end())
                m.insert({X,Y});
            else m[X] += Y;
        } else if (Q==2) {
            if (it != m.end())
                m.erase(X);
        } else {
            if (it == m.end()) 
                cout << 0 << endl;
            else cout << m[X] << endl;
        }
    }  
    return 0;
}
