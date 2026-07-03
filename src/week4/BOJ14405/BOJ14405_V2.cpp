#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    bool ret_flag = true;
    for (int i = 0; i < s.length(); i++) {
        if (i < s.length()-1 && (s.substr(i,2) == "pi" || s.substr(i,2) == "ka")) i++;
        else if (i < s.length()-2 && s.substr(i,3) == "chu") i+=2;
        else ret_flag = false;
    }

    if (ret_flag) cout << "YES\n";
    else cout << "NO\n";



    return 0;
}