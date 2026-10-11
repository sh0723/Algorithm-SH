#include <bits/stdc++.h>
using namespace std;
int target;
int N;
vector<vector<int>> tree;
int dfs(int num) {
    int ret = 0;
    int child = 0;
    for (int i : tree[num]) {
        if (i == target) continue;
        ret += dfs(i);
        child++;
    }

    if (child == 0)
        return 1;

    return ret;
}

int main() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        tree.push_back(vector<int>());
        int num;
        cin >> num;
        if (num == -1) continue;
        tree[num].push_back(i);
    }

    cin >> target;
    if (target == 0) {
        cout << 0;
        return 0;
    }


    cout << dfs(0);

    return 0;
}
