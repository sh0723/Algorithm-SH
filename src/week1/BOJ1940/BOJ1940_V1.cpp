#include <bits/stdc++.h>
using namespace std;
int main() {

    int N;
    cin >> N;

    int n;
    cin >> n;

    vector<int> v;
    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int cnt = 0;
    for (int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            if (v[i] + v[j] == n) {
                cnt++;
            }
        }
    }


    cout << cnt << "\n";
    return 0;
}