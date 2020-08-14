#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    vector<string> sections(4,"");
    int count = 0;
    int sect = 0;
    while (count < s.size()) {
        if (s[count] == 'A' || s[count] == 'P') sect++;
        if (s[count] == ':') {
            count++;
            sect++;
            continue;
        }
        sections[sect].push_back(s[count]);
        count++;
    }
    int hour = stoi(sections[0]);
    if (sections[3] == "PM") {
        if (hour != 12) {
            hour += 12;
            sections[0] = to_string(hour);
        }
    } else {
        if (hour == 12) {
            sections[0] = "00";
        }
    }
    string out = sections[0];
    for (int i = 1; i < 3; ++i) {
        out.append(":");
        out.append(sections[i]);
    }
    return out;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
