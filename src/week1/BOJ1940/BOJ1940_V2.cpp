#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> choose;
int cnt;
int N;
int n;
void solve(int start){
    if (choose.size() == 2) {
        if (choose[0] + choose[1] == n)
            cnt++;
        return;
    }

    for (int i=start; i<N; i++) {
        choose.push_back(v[i]);
        solve(i+1);
        choose.pop_back();
    }
}
int main() {
    cin >> N;

    cin >> n;

    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    solve(0);

    cout << cnt << "\n";
    return 0;
}
