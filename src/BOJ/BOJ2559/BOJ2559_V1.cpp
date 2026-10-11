#include <bits/stdc++.h>
using namespace std;
int N;
int conti;
vector<int> arr;
int max_val = INT_MIN;
void solve(){
    for(int i=0; i<N-conti+1; i++){
        int sum = 0;
        for(int j=i; j<i+conti; j++){
            sum += arr[j];
        }
        if (sum > max_val)
            max_val = sum;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> conti;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    solve();

    cout << max_val << endl;
    return 0;
}