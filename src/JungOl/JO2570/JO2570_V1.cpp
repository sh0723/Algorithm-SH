#include <bits/stdc++.h>
using namespace std;
int n;
bool used[10];
vector<int> biggest;
vector<int> smallest;
vector<char> inp;
bool biggest_flag, smallest_flag;
void solve(int cur, int idx, bool isBig) {
    if (isBig)
        biggest.push_back(cur);
    else
        smallest.push_back(cur);

    if (idx == n+1) {
        if (isBig)
            biggest_flag = true;
        else
            smallest_flag = true;

        return;
    }
    used[cur] = true;

    if (isBig) {
        for (int i=9; i>=0; i--) {
            if (used[i] || biggest_flag) continue;
            if (inp[idx-1] == '>') {
                if (cur <= i) continue;
            } else {
                if (cur >= i) continue;
            }
            solve(i,idx+1,isBig);
        }
    } else {
        for (int i=0; i<10; i++) {
            if (used[i] || smallest_flag) continue;
            if (inp[idx-1] == '>') {
                if (cur <= i) continue;
            } else {
                if (cur >= i) continue;
            }
            solve(i,idx+1,isBig);
        }
    }

    used[cur] = false;

    if (isBig) {
        if (!biggest_flag)
            biggest.pop_back();
    } else {
        if (!smallest_flag)
            smallest.pop_back();
    }

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i=0; i<n; i++) {
        char c;
        cin >> c;
        inp.push_back(c);
    }

    for (int i=9; i>=0; i--) {
        solve(i,1,true);
        if (biggest_flag) break;
    }

    memset(used, false, sizeof(used));

    for (int i=0; i<10; i++) {
        solve(i,1,false);
        if (smallest_flag) break;
    }

    for (int i=0; i<biggest.size(); i++) {
        cout << biggest[i];
    }

    cout << '\n';

    for (int i=0; i<smallest.size(); i++) {
        cout << smallest[i];
    }

    return 0;
}