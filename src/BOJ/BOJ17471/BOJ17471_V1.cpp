#include <bits/stdc++.h>
using namespace std;
int N;
int ret = INT_MAX;
vector<vector<int>> ll;
int person[11];
int visited[11];
bool selected[11];
void traversal(int i, bool group) {
    for (int next : ll[i]) {
        if (visited[next] || selected[next] != group) continue;
        visited[next] = 1;
        traversal(next, group);
    }
}
bool isConnected(bool group) {
    memset(visited, 0, sizeof(visited));
    int start = -1;
    for (int i = 1; i <= N; i++) {
        if (selected[i] == group) {
            start = i;
            break;
        }
    }
    if (start == -1) return false;
    visited[start] = 1;
    traversal(start, group);

    for (int i = 1; i <= N; i++) {
        if (selected[i] == group && !visited[i]) return false;
    }

    return true;
}
int calculate(int bit_num) {
    memset(selected, false, sizeof(selected));
    int diff = -1;
    int a_sum = 0;
    int b_sum = 0;
    for (int j = 0; j < N; j++) {
        if (bit_num & (1 << j)) {
            selected[j+1] = true;
        }
    }

    if (!isConnected(true)) return -1;
    if (!isConnected(false)) return -1;

    for (int i = 1; i <= N; i++) {
        if (selected[i]) a_sum += person[i];
        else b_sum += person[i];
    }

    return abs(a_sum - b_sum);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    ll.resize(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> person[i];
    }

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int temp;
            cin >> temp;
            ll[i].push_back(temp);
        }
    }

    for (int i=1; i<(1 << N); i++) {

        int diff = calculate(i);
        if (diff != -1) {
            ret = min(ret, diff);
        }
    }

    if (ret == INT_MAX) {
        cout << -1 << '\n';
    } else
        cout << ret << '\n';

    return 0;
}