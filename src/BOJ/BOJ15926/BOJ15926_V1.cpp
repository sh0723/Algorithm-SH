#include <bits/stdc++.h>
using namespace std;
bool flag[200000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    int n;
    cin >> n >> s;
    stack<int> stk;
    for (int i=0; i<n; i++) {
        if (s[i] == '(') stk.push(i);
        else if (s[i] == ')') {
            if (!stk.empty()) {
                flag[stk.top()] = true;
                flag[i] = true;
                stk.pop();
            }
        }
    }

    int ret=0, cnt=0;
    for (int i=0; i<n; i++) {
        if (flag[i]){
            cnt++;
            ret = max(ret, cnt);
        }
        else cnt =0;
    }

    cout << ret << '\n';

    return 0;
}