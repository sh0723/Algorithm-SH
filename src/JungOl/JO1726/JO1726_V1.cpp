#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<int> arr;
vector<pair<int, int>> tar;
vector<int> tree;
vector<int> ret;
int fill_tree(int st, int ed, int idx) {
    if (st == ed) {
        tree[idx] = arr[st];
        return tree[idx];
    }

    if (ed == st + 1) {
        tree[idx] = max(fill_tree(st,st,idx*2), fill_tree(ed,ed,idx*2+1));
    } else {
        int mid = (st + ed) / 2;
        tree[idx] = max(fill_tree(st,mid,idx*2), fill_tree(mid+1, ed,idx*2+1));
    }

    return tree[idx];
}
int solve(int st, int ed, int tree_idx, int tar_idx) {
    auto[tar_st, tar_ed] = tar[tar_idx];

    if (st > tar_ed || ed < tar_st) return 0;

    if (st >= tar_st && ed <= tar_ed) return tree[tree_idx];

    int mid = (st+ed)/2;

    return max(solve(st,mid,tree_idx*2, tar_idx), solve(mid+1, ed, tree_idx*2+1, tar_idx));
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    arr.resize(N+1);
    tree.resize(N*4, 0);
    tar.resize(M);
    int max_val = 0;
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<M; i++) {
        cin >> tar[i].first >> tar[i].second;
    }

    fill_tree(1, N, 1);

    for (int i=0; i<M; i++) {
        cout << solve(1,N,1,i) << '\n';
    }

    return 0;
}