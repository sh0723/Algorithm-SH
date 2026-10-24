#include <bits/stdc++.h>
using namespace std;
bool isExist[5001][5001];
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> inp(N);

    for (int i=0; i<N; i++) {
        cin >> inp[i].first >> inp[i].second;
        isExist[inp[i].first][inp[i].second] = true;
    }

    int ret = 0;
    for (int i=0; i<N; i++) {
        for (int j=1; j<N; j++) {
            auto [f_y, f_x] = inp[i];
            auto [s_y, s_x] = inp[j];

            int diff_y = inp[i].first - inp[j].first;
            int diff_x = inp[i].second - inp[j].second;

            int dy[2], dx[2];
            dy[0] = -diff_x;
            dx[0] = diff_y;
            dy[1] = diff_x;
            dx[1] = -diff_y;

            for (int k=0; k<2; k++) {
                int nf_y = f_y + dy[k];
                int nf_x = f_x + dx[k];
                int ns_y = s_y + dy[k];
                int ns_x = s_x + dx[k];

                bool flag = true;
                if (nf_y < 0 || nf_x < 0 || ns_y < 0 || ns_x < 0) continue;
                if (nf_y > 5000 || nf_x > 5000 || ns_y > 5000 || ns_x > 5000) continue;
                if (!isExist[nf_y][nf_x] || !isExist[ns_y][ns_x]) flag = false;
                if (flag) {
                    ret = max(ret, diff_y*diff_y + diff_x*diff_x);
                }
            }
        }
    }

    cout << ret;


    return 0;
}