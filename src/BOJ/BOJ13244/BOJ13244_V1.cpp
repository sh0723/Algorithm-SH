#include <bits/stdc++.h>
using namespace std;
int visited[10][1001];
vector<vector<vector<int>>> injs;
vector<bool> isTree;
int N;
bool dfs(int here, int num, int prev) {
    visited[num][here] = 1;
    for (int next : injs[num][here]) {
        if (next == prev) continue;
        if (visited[num][next]) return false;
        if (!dfs(next, num, here)) return false;
    }

    return true;
}
int main() {

    cin >> N;
    injs.resize(N,vector<vector<int>>());
    isTree.resize(N);
    for (int i = 0; i < N; i++) {
        int nodes;
        int inp_num;
        bool tree_flag = true;
        cin >> nodes;
        cin >> inp_num;
        injs[i].resize(nodes+1);
        if (inp_num != nodes-1)
            tree_flag = false;
       for (int j=0; j<inp_num; j++) {
           int a,b;
           cin >> a >> b;
           injs[i][a].push_back(b);
           injs[i][b].push_back(a);
       }
       if (tree_flag && !dfs(1, i, 0))
           tree_flag = false;


       for (int j=1; j<=nodes; j++) {
           if (!visited[i][j]) {
               tree_flag = false;
               break;
           }
       }

       isTree[i] = tree_flag;
    }


    for (int i = 0; i < N; i++) {
        if (isTree[i])
            cout << "tree" << '\n';
        else
            cout << "graph" << '\n';
    }
    return 0;
}