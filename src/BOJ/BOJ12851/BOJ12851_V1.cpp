#include <bits/stdc++.h>
using namespace std;
int brother, subin;
int ret = INT_MAX;
int ret_cnt;
int visited[100001];
void solve(int idx, int level) {
    if (idx > 100000 || idx < 0) {
        return;
    }
    if (visited[idx]) return;
    if (level > ret) return;
    if (level == ret && idx == brother) {
        ret_cnt++;
        return;
    }
    if (idx == brother && level < ret) {
        ret = level;
        ret_cnt = 1;
        return;
    }
    
    visited[idx] = 1;
    solve(idx-1, level+1);
    solve(idx+1, level+1);
    solve(idx*2, level+1);
    visited[idx] = 0;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> subin >> brother;

    solve(subin, 0);

    cout << ret << '\n' << ret_cnt << '\n';


    return 0;
}