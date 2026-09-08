#include <bits/stdc++.h>
using namespace std;
int used[501];
vector<vector<int>> friends(501, vector<int>());
int cnt = 0;

void dfs(int n, int level) {
    for (int num : friends[n]) {
        if (level < 3 && num != 1 && used[num] == 0) {
            cnt ++;
            used[num] = 1;
            dfs(num, level+1);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N,M;
    cin >> N >> M;


    for (int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    dfs(1,1);

    cout << cnt;
    return 0;
}