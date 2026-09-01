#include <bits/stdc++.h>
using namespace std;
int T;
vector<int> ret;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;

    for (int i=0; i<T; i++) {
        int N,M;
        cin >> N >> M;
        vector<int> A,B;
        for (int j=0; j<N; j++) {
            int temp;
            cin >> temp;
            A.push_back(temp);
        }
        for (int j=0; j<M; j++) {
            int temp;
            cin >> temp;
            B.push_back(temp);
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int prev_high=0;
        int cnt=0;
        for (int j=0; j<N; j++) {
            int curr=M;
            for (int k=prev_high; k<M; k++) {
                if (A[j] <= B[k]) {
                    curr = k;
                    prev_high = k;
                    break;
                }
            }

            cnt += curr;
        }
        ret.push_back(cnt);
    }


    for (int ret_num : ret) {
        cout << ret_num << '\n';
    }



    return 0;
}