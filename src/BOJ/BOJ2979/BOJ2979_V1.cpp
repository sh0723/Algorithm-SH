#include <bits/stdc++.h>
using namespace std;
int A,B,C;
int cnt[101];
int truck[3][2];
int calculate(){
    int sum = 0;
    for (int i=0; i<101; i++){
        if (cnt[i] == 1) {
            sum += A;
        } else if (cnt[i] == 2) {
            sum += (2 * B);
        } else if (cnt[i] == 3) {
            sum += (3 * C);
        }
    }
    return sum;
}
int solve(){
    for (int i=0; i<3; i++) {
        int st = truck[i][0];
        int end = truck[i][1];

        for (int i=st+1; i<=end; i++) {
            cnt[i]++;
        }
    }
    return calculate();

}
int main(){
    cin >> A >> B >> C;
    for (int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            cin >> truck[i][j];
        }
    }
    int result = solve();
    cout << result << endl;
    return 0;
}