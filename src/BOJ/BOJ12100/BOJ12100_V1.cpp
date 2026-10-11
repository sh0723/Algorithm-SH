#include <bits/stdc++.h>
using namespace std;
int N;
int ret = INT_MIN;
vector<vector<int>> inp;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
void check() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            ret = max(ret, inp[i][j]);
        }
    }
}
void move(int y, int x) {
    if (y == 0) {
        if (x == -1) { // 0,-1 왼쪽 방향
            for (int i=0; i<N; i++) {
                queue<int> q;
                for (int j=0; j<N; j++) {
                    if (inp[i][j] == 0) continue;
                    q.push(inp[i][j]);
                }
                int index=0;
                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();

                    if (!q.empty() && cur == q.front()) {
                        cur *= 2;
                        q.pop();
                    }

                    inp[i][index++] = cur;
                }
                for (int j=index; j<N; j++) {
                    inp[i][j] = 0;
                }
            }
        } else { // 0,1 오른쪽 방향
            for (int i=0; i<N; i++) {
                queue<int> q;
                for (int j=N-1; j>=0; j--) {
                    if (inp[i][j] == 0) continue;
                    q.push(inp[i][j]);
                }
                int index=N-1;
                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();

                    if (!q.empty() && cur == q.front()) {
                        cur *= 2;
                        q.pop();
                    }

                    inp[i][index--] = cur;
                }
                for (int j=index; j>=0; j--) {
                    inp[i][j] = 0;
                }
            }
        }
    } else {
        if (y == -1) { // -1,0 위 방향
            for (int i=0; i<N; i++) {
                queue<int> q;
                for (int j=0; j<N; j++) {
                    if (inp[j][i] == 0) continue;
                    q.push(inp[j][i]);
                }
                int index=0;
                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();

                    if (!q.empty() && cur == q.front()) {
                        cur *= 2;
                        q.pop();
                    }

                    inp[index++][i] = cur;
                }
                for (int j=index; j<N; j++) {
                    inp[j][i] = 0;
                }
            }
        } else { // 1,0 아래 방향
            for (int i=0; i<N; i++) {
                queue<int> q;
                for (int j=N-1; j>=0; j--) {
                    if (inp[j][i] == 0) continue;
                    q.push(inp[j][i]);
                }
                int index=N-1;
                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();

                    if (!q.empty() && cur == q.front()) {
                        cur *= 2;
                        q.pop();
                    }

                    inp[index--][i] = cur;
                }
                for (int j=index; j>=0; j--) {
                    inp[j][i] = 0;
                }
            }
        }
    }
}
void solve(int y, int x, int cnt) {
    check();
    if (cnt == 6) {
        return;
    }

    move(y,x);

    vector<vector<int>> tmp;
    tmp.resize(N, vector<int>(N));
    for (int i=0; i<4; i++) {
        tmp = inp;
        solve(dy[i],dx[i],cnt+1);
        inp = tmp;
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    inp.resize(N, vector<int>(N));
    for(int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> inp[i][j];
        }
    }

    if (N == 1) {
        cout << inp[0][0];
        return 0;
    }

    vector<vector<int>> tmp;
    tmp.resize(N, vector<int>(N));
    for (int i=0; i<4; i++) {
        tmp = inp;
        solve(dy[i], dx[i], 1);
        inp = tmp;
    }

    cout << ret;

    return 0;
}