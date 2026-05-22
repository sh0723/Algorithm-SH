#include <bits/stdc++.h>
using namespace std;
int cnt[26];
string input;
int odd_num = -1;
int odd_count;
int main() {

    cin >> input;

    for (int i=0; i<input.length(); i++) {
        cnt[input[i]-'A']++;
    }

    for (int i=0; i<26; i++) {
        if (cnt[i]%2==1) {
            odd_count++;
            odd_num = i;
        }
    }

    string result = "";
    if (odd_count > 1) {
        cout << "I'm Sorry Hansoo";
    } else if (odd_count == 1) {
        result += (char)(odd_num + 'A');
    }

    for (int i=25; i>=0; i--) {
        for (int j=0; j<(cnt[i]/2); j++) {
            result = result + (char)(i+'A');
            result = (char)(i+'A') + result;
        }
    }

    cout << result << "\n";
    return 0;
}