#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    // for (int i = 0; i < s2.length(); ++i) {   //slower
    //     if (s1.find(s2[i])!=string::npos) {
    //         return "YES";
    //     }
    // }
    // return "NO";
    unordered_set<char> s;
    for (int i = 0; i < s1.length(); ++i) {
        s.insert(s1[i]);
    }
    for (int i = 0; i < s2.length(); ++i) {
        if (s.find(s2[i]) != s.end()) {
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
