#include <bits/stdc++.h>
using namespace std;
int W, coin[6];
int cost[6] = {500, 100, 50, 10, 5, 1};
bool find_ret;
vector<int> ret;
void solve(int coin_idx, int cur_w) {
    if (find_ret) return;
    if (cur_w == 0) {
        find_ret = true;
        return;
    }
    if (coin_idx > 5) return;
    if (cur_w < cost[coin_idx]) {
        ret.push_back(0);
        solve(coin_idx+1, cur_w);
        if (find_ret) return;
        ret.pop_back();
    }

    int max_cnt = (cur_w / cost[coin_idx]);
    if (max_cnt > coin[coin_idx]) max_cnt = coin[coin_idx];

    for (int use_cnt = max_cnt; use_cnt >= 0; use_cnt--) {
        ret.push_back(use_cnt);
        solve(coin_idx+1, cur_w - use_cnt * cost[coin_idx]);
        if (find_ret) return;
        ret.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> W;
    int max_cost = 0;
    int all_cnt = 0;
    for (int i=0; i<6; i++) {
        cin >> coin[i];
        max_cost += coin[i] * cost[i];
        all_cnt += coin[i];
    }
    solve(0,max_cost-W);

    int size = ret.size();
    int sum = 0;
    for (int i=0; i<size; i++) sum += ret[i];

    cout << all_cnt - sum << '\n';

    int ret_size = ret.size();
    for (int i=ret_size; i<6; i++) ret.push_back(0);

    for (int i=0; i<6; i++) {
        cout << coin[i] - ret[i] << ' ';
    }


    return 0;
}