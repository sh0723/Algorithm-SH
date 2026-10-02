#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N,Q;
    cin >> N >> Q;

    vector<int> stu;
    for (int i=0; i<N; i++) {
        int score;
        cin >> score;
        stu.push_back(score);
    }

    for (int i=0; i<Q; i++) {
        int num;
        cin >> num;
        int x,y;
        if (num == 1) {
            cin >> x;
        } else {
            cin >> x >> y;
        }

        if (num == 1) {
            int cnt = 0;
            for (int j=0; j<N; j++) {
                if (stu[j] > stu[x-1]) cnt++;
            }
            cout << cnt + 1 << '\n';
        } else {
            stu[x-1] = y;
        }
    }





    return 0;
}