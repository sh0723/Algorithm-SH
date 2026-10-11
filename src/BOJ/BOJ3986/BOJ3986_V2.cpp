#include <bits/stdc++.h>
using namespace std;
int n;
int cnt;

int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        stack<char> stk;
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            if (stk.size() != 0 && stk.top() == s[j]) {
                stk.pop();
            } else {
                stk.push(s[j]);
            }
        }

        if (stk.size() == 0) {
            cnt++;
        }

    }

    cout << cnt << "\n";

    return 0;
}
