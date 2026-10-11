#include <bits/stdc++.h>
using namespace std;
string s;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    bool ret_flag = true;
    if (s.length() == 1)
        ret_flag = false;
    for (int i=0; i<s.length()-1; i++) {
        if (s[i] == 'p') {
            if (s[i+1] == 'i' && i != s.length()-3) i++;
            else ret_flag = false;
        } else if (s[i] == 'k') {
            if (s[i+1] == 'a' && i != s.length()-3) i++;
            else ret_flag = false;
        } else if (s[i] == 'c') {
            if (i != s.length()-2 && s[i+1] == 'h' && s[i+2] == 'u') i += 2;
            else ret_flag = false;
        } else
            ret_flag = false;
    }

    if (ret_flag) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}