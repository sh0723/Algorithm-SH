#include <bits/stdc++.h>
using namespace std;
int target;
int N;
vector<vector<int>> tree;
int cnt = 0;
void dfs(int num) {
    if (tree[num].size() == 0) {
        cnt++;
        return;
    }

    for (int i : tree[num]) {
        dfs(i);
    }
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

    tree[target].clear();
    int num = 0;
    int flag = true;
    while(flag) {
        if (num == tree.size())
            break;
        for (int i=0; i<tree[num].size(); i++) {
            if (tree[num][i] == target) {
                flag = false;
                tree[num].erase(tree[num].begin() + i);
                break;
            }
        }
        num++;
    }

    dfs(0);
    cout << cnt;

    return 0;
}