#include <bits/stdc++.h>
using namespace std;
int N,K;
int inp_arr[26];
int ret = 0;
int learned_setting(int num){
    num |= (1 << ('a'-'a'));
    num |= (1 << ('n'-'a'));
    num |= (1 << ('t'-'a'));
    num |= (1 << ('i'-'a'));
    num |= (1 << ('c'-'a'));
    return num;
}
void solve(int learned){
    int tmp = 0;
    for (int i=0; i<N; i++) {
        if ((learned & inp_arr[i]) == inp_arr[i])
            tmp++;
    }

    ret = max(ret, tmp);
}
void combi(int learned, int cnt, int n) {
    if (cnt == K) {
        solve(learned);
        return;
    }
    for (int i=n; i<26; i++) {
        if (learned & (1 << i)) continue;
        combi(learned | (1 << i), cnt+1, i+1);
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        for (int j=0; j<s.length(); j++) {
           inp_arr[i] |= (1 << (int)(s[j] - 'a'));
        }
    }

    if (K < 5) {
        cout << 0 << '\n';
        return 0;
    }

    int learned = learned_setting(0);

    combi(learned,5,0);

    cout << ret << '\n';
    return 0;
}