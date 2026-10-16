#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> inj(N+1);

    for (int i=0; i<N-1; i++) {
        int w1, w2;
        cin >> w1 >> w2;
        inj[w1].push_back(w2);
        inj[w2].push_back(w1);
    }

    int max_weed = -1;
    for (int i=1; i<=N; i++) {
        int connected = inj[i].size() + 1;
        max_weed = max(max_weed,connected);
    }

    cout << max_weed;


    return 0;
}