#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N,M;
    cin >> N >> M;

    vector<string> desert(N);
    for (int i=0; i<N; i++) {
        cin >> desert[i];
    }

    vector<int> smallerI(M,0);
    long long int ret=0;

    for (int i=N-1; i>=0; i--) {
        int biggerJ = 0;
        for (int j=M-1; j>=0; j--) {
            if (desert[i][j] == 'J') {
                ret += (biggerJ * smallerI[j]);
            } else if (desert[i][j] == 'O') {
                biggerJ++;
            } else {
                smallerI[j]++;
            }
        }
    }

    cout << ret;
    return 0;
}