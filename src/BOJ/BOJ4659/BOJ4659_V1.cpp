#include <bits/stdc++.h>
using namespace std;
unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
bool check(string s) {
    int vowels_cnt = 0;
    int consonant_cnt = 0;
    bool flag = true;
    if (vowels.find(s[0]) != vowels.end() && s.size() == 1) {
        return true;
    }

    if (vowels.find(s[0]) != vowels.end()) {
        vowels_cnt++;
        flag = false;
    } else {
        consonant_cnt++;
    }
    char before_c = s[0];
    for (int i = 1; i < s.length(); i++) {
        if (before_c == s[i] && !(s[i] == 'e' || s[i] == 'o')) return false;

        if (vowels.find(s[i]) == vowels.end()) {
            consonant_cnt++;
            if (consonant_cnt == 3) return false;
            vowels_cnt = 0;
        } else {
            vowels_cnt++;
            if (vowels_cnt == 3) return false;
            consonant_cnt = 0;
            flag = false;
        }
        before_c = s[i];
    }

    if (flag) return false;

    return true;
}
int main() {
    ios_base::sync_with_stdio(false);



    while(true) {
        string s;
        cin >> s;
        if (s == "end") break;
        if (check(s)) {
            cout << "<" << s << "> " << "is acceptable.\n";
        } else {
            cout << "<" << s << "> " << "is not acceptable.\n";
        }
    }


    return 0;
}