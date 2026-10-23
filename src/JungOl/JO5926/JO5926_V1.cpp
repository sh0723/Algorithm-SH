#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> inp(N);
    map<int,int> availiable;

    for (int i=0; i<N; i++) {
        cin >> inp[i].first >> inp[i].second;
    }

    sort(inp.begin(), inp.end());

    int count = 0;
    int max_defense = 0;

    for (int i = N - 1; i >= 0; i--) {
        int defense = inp[i].second;

        if (defense > max_defense) {
            count++;
            max_defense = defense;
        }
    }

    cout << count;
    
    return 0;
}