#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        //==========================================================================================================
        long long a = (long long)A;
        cout << setiosflags(ios::showbase) << resetiosflags(ios::uppercase) << setw(0);
        cout << fixed << hex << a << dec << endl;
        string b = to_string((long long)B);
        cout << setfill('_') << setprecision(2) << setw(12-b.size()) << right << (B>0 ? '+' : '-')<< B << endl;
        cout << setiosflags(ios::uppercase)<< scientific << setprecision(9) << C << endl;
        //==========================================================================================================
	}
	return 0;

}