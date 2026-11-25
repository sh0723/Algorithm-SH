#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int N,M;
    cin >> N >> M;

    vector<int> inp(M);
    for (int i=0; i<M; i++) {
        cin >> inp[i];
    }

    int q_size = N;
    int ret = 0;
    for (int i=0; i<M; i++) {
        int tar = inp[i];
        if (tar - 1 <= q_size - tar) {
            ret += (tar - 1);
            for (int j=i+1; j<M; j++) {
                if (inp[j] - tar > 0) {
                    inp[j] -= tar;
                } else {
                    inp[j] = q_size + (inp[j] - tar);
                }
            }
            q_size--;
        } else {
            ret += (q_size - tar + 1);
            for (int j=i+1; j<M; j++) {
                inp[j] = (inp[j] + q_size - tar) % q_size;
            }
            q_size--;
        }
    }

    cout << ret;

    return 0;
}