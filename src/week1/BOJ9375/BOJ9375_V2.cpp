#include <bits/stdc++.h>
using namespace std;
map<string, int> clothes_map;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;

        for (int j = 1; j <= n; j++) {
            string a,b;
            cin >> a >> b;
            clothes_map[b]++;
        }
        int sum = 1;
        for (auto [key, value] : clothes_map) {
            sum = sum * (value + 1);
        }
        sum -= 1;

        cout << sum << "\n";
        clothes_map.clear();
    }



    return 0;
}