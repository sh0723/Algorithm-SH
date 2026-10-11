#include <bits/stdc++.h>
using namespace std;
int N;
int input_arr[20][20];
int ret = INT_MAX;
int check(int team_bit) {
    int a_sum=0;
    int b_sum=0;
    for (int i=0; i<N; i++) {
        if (team_bit & (1<<i)) {
            for (int j=0; j<N; j++) {
                if(team_bit & (1<<j)) a_sum += input_arr[i][j];
            }
        } else {
            for (int j=0; j<N; j++) {
                if(!(team_bit & (1<<j))) b_sum += input_arr[i][j];
            }
        }
    }

    return abs(b_sum - a_sum);
}
void combi(int st, vector<int> b) {
    if (b.size() == N/2) {
        int team_bit = 0;
        for (int num : b) {
            team_bit |= (1 << num);
        }

        int diff = check(team_bit);
        ret = min(ret, diff);

        return;
    }

    for (int i=st+1; i<N; i++) {
        b.push_back(i);
        combi(i,b);
        b.pop_back();
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> input_arr[i][j];
        }
    }
    vector<int> b;
    combi(-1,b);
    cout << ret;


    return 0;
}