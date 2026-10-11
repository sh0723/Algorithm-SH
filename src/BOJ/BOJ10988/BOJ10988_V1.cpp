#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;
    string compare = s;
    reverse(s.begin(), s.end());
    if (compare == s) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }


    return 0;
}