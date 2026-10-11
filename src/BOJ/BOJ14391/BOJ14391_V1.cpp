#include <bits/stdc++.h>
using namespace std;
int N,M;
bool selected[16];
int arr[4][4];
int ret = INT_MIN;
int calculate() {
    int sum = 0;
    for (int i=0; i<N; i++) {
        string s = "";
        for (int j=0; j<M; j++) {
            if (selected[i*M + j]) {
                if (s == "") continue;
                else {
                    sum += stoi(s);
                    s = "";
                    continue;
                }
            }
            s += to_string(arr[i][j]);
        }
        if (s == "") continue;
        sum += stoi(s);
    }

    for (int j = 0; j < M; j++) {
        string s = "";
        for (int i = 0; i < N; i++) {
            if (!selected[i*M + j]) {
                if (s == "") continue;
                else {
                    sum += stoi(s);
                    s = "";
                    continue;
                }
            }
            s += to_string(arr[i][j]);
        }
        if (s == "") continue;
        sum += stoi(s);
    }

    return sum;
}
void dfs(int num) {
    if (num == N * M) {
        ret = max(ret, calculate());
        return;
    }
    dfs(num+1);
    selected[num] = true;
    dfs(num+1);
    selected[num] = false;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    dfs(0);

    cout << ret << '\n';
    return 0;
}