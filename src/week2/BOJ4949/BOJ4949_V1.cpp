#include <bits/stdc++.h>
using namespace std;
bool check(string s) {
    stack<char> stk;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[')
            stk.push(s[i]);
        else if (s[i] == ')') {
            if (stk.empty() || stk.top() != '(')
                return false;
            stk.pop();
        } else if (s[i] == ']') {
            if (stk.empty() || stk.top() != '[')
                return false;
            stk.pop();
        }
    }

    return stk.empty();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    vector<bool> ret;
    while(getline(cin, s)) {
        if (s == ".")
            break;
        ret.push_back(check(s));
    }

    for (int i = 0; i < ret.size(); i++) {
        if (ret[i])
            cout << "yes\n";
        else
            cout << "no\n";
    }
}