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
        int ret_num=0;
        for (int j=0; j<N; j++) {
            auto pos = lower_bound(B.begin(), B.end(), A[j]);
            ret_num += (int)(pos-B.begin());
        }
        ret.push_back(ret_num);
    }


    for (int ret_num : ret) {
        cout << ret_num << '\n';
    }



    return 0;
}