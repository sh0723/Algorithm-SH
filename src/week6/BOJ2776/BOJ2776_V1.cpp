#include <bits/stdc++.h>
using namespace std;
int T,N,M;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    vector<vector<int>> ret;
    for (int i=0; i<T; i++) {
        map<int, int> n1;
        cin >> N;
        for (int j=0; j<N; j++) {
            int num;
            cin >> num;
            n1[num] = 1;
        }
        ret.push_back(vector<int>());
        cin >> M;
        for (int j=0; j<M; j++) {
            int num;
            cin >> num;
            if (n1.find(num) != n1.end()) ret[i].push_back(1);
            else ret[i].push_back(0);
        }
    }

    for (int i=0; i<T; i++) {
        for (size_t j=0; j<ret[i].size(); j++) {
            cout << ret[i][j] << '\n';
        }
    }



    return 0;
}
