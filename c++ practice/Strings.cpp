#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
    getline(cin,a);
    getline(cin,b);
    cout << a.size() << ' ' << b.size() << endl;
    cout << a+b << endl;
    string a_prime = a, b_prime = b;
    a_prime[0] = b[0];
    b_prime[0] = a[0];
    cout << a_prime << ' ' << b_prime << endl;
    return 0;
}
