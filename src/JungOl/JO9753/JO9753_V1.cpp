#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N,M,K;
    cin >> N >> M >> K;

    vector<string> inp(N);

    for (int i=0; i<N; i++) {
        cin >> inp[i];
    }

    vector<vector<char>> t(K,vector<char>(K));

    for (int y=0; y<K; y++) {
        for (int x=0; x<K; x++) {
            map<char,int> m;
            for (int i=0; i<N/K; i++) {
                for (int j=0; j<M/K; j++) {
                    m[inp[y + i*K][x + j*K]]++;
                }
            }
            char final;
            int max_val = 0;
            for (auto [tar_char, cnt] : m) {
                if (max_val < cnt) {
                    max_val = cnt;
                    final = tar_char;
                }
            }
            t[y][x] = final;
        }
    }

    int ret = 0;
    for (int y=0; y<K; y++) {
        for (int x=0; x<K; x++) {
            for (int i=0; i<N/K; i++) {
                for (int j=0; j<M/K; j++) {
                    if (inp[y + i*K][x + j*K] != t[y][x]) {
                        ret++;
                        inp[y + i*K][x + j*K] = t[y][x];
                    }
                }
            }
        }
    }

    cout << ret << '\n';
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) cout << inp[i][j];
        cout << '\n';
    }
    return 0;
}