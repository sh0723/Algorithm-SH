#include <bits/stdc++.h>
using namespace std;
string s;
int alphabet[26] = {0};
void solve(){
    for (char c : s) {
        alphabet[c-'a']++;
    }
}
int main() {
    cin >> s;

    solve();

    for (int i=0; i<26; i++) {
        cout << alphabet[i] << " ";
    }
}
