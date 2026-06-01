#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> ret;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        stack<char> stk;
        bool flag = true;
        for (int j=0; j<s.length(); j++) {
            if (stk.empty()) {
                if (s[j] != '(') {
                    flag = false;
                    break;
                }
                stk.push(s[j]);
            } else {
                if (s[j] == ')') {
                    stk.pop();
                } else {
                    stk.push(s[j]);
                }
            }
        }

        if (!stk.empty())
            flag = false;

        if (flag)
            ret.push_back(1);
        else
            ret.push_back(0);
    }

    for (int i = 0; i < ret.size(); i++) {
        if (ret[i])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}