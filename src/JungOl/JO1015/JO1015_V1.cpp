#include <bits/stdc++.h>
using namespace std;
void stack_clear(stack<string> &stk) {
    while(!stk.empty()) stk.pop();
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<string> ret;
    stack<string> back, forward;

    string curr = "http://www.acm.org/";

    while(true) {
        string inp;
        cin >> inp;

        if (inp == "VISIT") {
            string next;
            cin >> next;
            stack_clear(forward);
            back.push(curr);
            curr = next;
            ret.push_back(curr);
        } else if (inp == "BACK") {
            if (back.empty()) {
                ret.push_back("Ignored");
            } else {
                forward.push(curr);
                curr = back.top();
                back.pop();
                ret.push_back(curr);
            }
        } else if (inp == "FORWARD") {
            if (forward.empty()) {
                ret.push_back("Ignored");
            } else {
                back.push(curr);
                curr= forward.top();
                forward.pop();
                ret.push_back(curr);
            }
        } else {
            break;
        }
    }

    for (int i=0; i<ret.size(); i++) {
        cout << ret[i] << '\n';
    }

    return 0;
}