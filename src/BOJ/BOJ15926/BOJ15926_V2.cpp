#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    stack<int> stk;
    stk.push(-1);
    int ret = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == '(')
            stk.push(i);
        else {
            stk.pop();
            if (stk.size()) {
                ret = max(ret, i - stk.top());
            } else {
                stk.push(i);
            }
        }
    }

    cout << ret << '\n';
    return 0;
}