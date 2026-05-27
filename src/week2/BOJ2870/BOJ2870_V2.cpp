#include <bits/stdc++.h>
using namespace std;
int N;
vector<string> output;
string s, ret;
void run() {
    while(true) {
        if(ret.size() && ret.front() == '0') {
            ret.erase(ret.begin());
        } else {
            break;
        }
    }

    if(ret.size() == 0)
        ret="0";

    output.push_back(ret);
    ret = "";
}

bool cmp(string a, string b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s;
        ret = "";
        for (int j=0; j<s.length(); j++) {
            if (s[j] >= '0' && s[j] <= '9') {
                ret += s[j];
            } else if (ret.size()){
                run();
            }
        }
        if (ret.size())
            run();

    }

    sort(output.begin(), output.end(), cmp);

    for (string s : output) {
        cout << s << "\n";
    }
    return 0;
}