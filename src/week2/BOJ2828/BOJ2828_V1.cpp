#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int j;
    cin >> j;
    int cur_pos = 1;
    int dist_cnt = 0;
    for (int i = 1; i <= j; i++) {
        int position;
        cin >> position;
        if (position >= cur_pos && position <= cur_pos + M - 1)
            continue;

        if (position < cur_pos) {
            dist_cnt += (cur_pos - position);
            cur_pos = position;
        } else {
            dist_cnt += (position - cur_pos - M + 1);
            cur_pos = (position - M + 1);
        }
    }

    cout << dist_cnt << endl;
}