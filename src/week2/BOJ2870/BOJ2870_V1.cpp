#include <bits/stdc++.h>
using namespace std;
int N;
string extract_number_string(string s) {
    bool is_pre_degit = false;
    string ret = "";
    for (int i=0; i<s.length(); i++) {
        if (isdigit(s[i])) {
            if (is_pre_degit) {
                ret += s[i];
            } else {
                ret = ret + " " + s[i];
            }
            is_pre_degit = true;
        } else {
            is_pre_degit = false;
        }
    }
    return ret;
}

void split(string s, char delim, vector<string> &elems) {

    auto st = 0;
    auto end = s.find(delim);
    string temp;
    while (end != string::npos) {
        temp = s.substr(st, end - st);
        if (!temp.empty()) {
            elems.push_back(temp);
        }
        st = end + 1;
        end = s.find(delim, st);
    }

    temp = s.substr(st);
    if (!temp.empty())
        elems.push_back(temp);

}

bool cmp(string a, string b) {

    if (a.length() != b.length())
        return a.length() < b.length();

    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i])
            return a[i] < b[i];
    }

    return false;
}

void delete_zero(vector<string> &elems) {
    if (elems.empty())
        return;
    for (int i=0; i<elems.size(); i++) {
        while (elems[i].length() > 1 && elems[i][0] == '0') {
            elems[i].erase(0, 1);
        }
    }
}
int main() {

    ios_base::sync_with_stdio(false);

    cin >> N;
    vector<string> num_str;
    vector<string> ret;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        num_str.push_back(extract_number_string(s));
    }

    for (string s : num_str) {
        split(s, ' ', ret);
    }

    delete_zero(ret);

    sort(ret.begin(), ret.end(), cmp);

    for (string s : ret) {
        cout << s << endl;
    }

    return 0;
}