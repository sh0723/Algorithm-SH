#include <bits/stdc++.h>
using namespace std;
int N;
int inp[25][25];
int used[25][25];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int cnt;
void dfs(int y, int x) {
    int ret = 0;
    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= N || nx >= N || ny < 0 || nx < 0 || used[ny][nx] == 1 || inp[ny][nx] == 0) continue;
        used[ny][nx] = 1;
        cnt++;
        dfs(ny,nx);
    }

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        for (int j=0; j<N; j++) {
            if (s[j] == '1') inp[i][j] = 1;
            else inp[i][j] = 0;
        }
    }

    vector<int> comp;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (used[i][j] == 0 && inp[i][j] == 1) {
                cnt = 0;
                dfs(i,j);
                if (cnt == 0) cnt =1;
                comp.push_back(cnt);
            }
        }
    }


    cout << comp.size() << '\n';
    sort(comp.begin(), comp.end());
    for (int i=0; i<comp.size(); i++) {
        cout << comp[i] << '\n';
    }

    return 0;
}