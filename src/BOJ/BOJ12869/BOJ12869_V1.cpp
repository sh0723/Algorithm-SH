#include <bits/stdc++.h>
using namespace std;
int n;
int min_val = INT_MAX;
int health[3];
int attack[6][3] = {
    {9,3,1},
    {9,1,3},
    {3,9,1},
    {3,1,9},
    {1,3,9},
    {1,9,3}
};
int visited[64][64][64];
struct st{
    int a,b,c;
};
queue<struct st> q;
int bfs(int a, int b, int c) {
    visited[a][b][c] = 1;
    q.push({a,b,c});

    while(!q.empty()) {
        struct st temp = q.front();
        int a = temp.a;
        int b = temp.b;
        int c = temp.c;

        q.pop();

        if (visited[0][0][0]) continue;
        for (int i = 0; i < 6; i++) {
            int na = max(0, a - attack[i][0]);
            int nb = max(0, b - attack[i][1]);
            int nc = max(0, c - attack[i][2]);

            if (visited[na][nb][nc]) continue;
            q.push({na,nb,nc});
            visited[na][nb][nc] = visited[a][b][c] + 1;
        }
    }

    return visited[0][0][0] - 1;
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> health[i];
    }

    cout << bfs(health[0], health[1], health[2]);

    return 0;
}