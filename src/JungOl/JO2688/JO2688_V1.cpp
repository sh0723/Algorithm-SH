#include <bits/stdc++.h>
using namespace std;
int N, tree_cnt;
vector<int> trees;
vector<vector<int>>ret;
void solve(int root_num, int level) {

    ret[level].push_back(root_num);

    if (level == N-1) return;

    solve(root_num-(1<<(N-2-level)), level+1);
    solve(root_num+(1<<(N-2-level)), level+1);
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    ret.resize(N,vector<int>());
    tree_cnt = (1 << N)-1;
    for (int i=0; i<tree_cnt; i++) {
        int num;
        cin >> num;
        trees.push_back(num);
    }

    solve(tree_cnt/2, 0);

    for (int i=0; i<N; i++) {
        for (int j=0; j<ret[i].size(); j++) {
            cout << trees[ret[i][j]] << ' ';
        }
        cout << '\n';
    }



    return 0;
}