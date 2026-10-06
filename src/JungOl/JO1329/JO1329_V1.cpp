#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    if (N%2 == 0 || N > 100) {
        cout << "INPUT ERROR!";
        return 0;
    }
    for (int i=0; i<=N/2; i++) {
        for (int j=0; j<i; j++) cout << ' ';
        for (int j=0; j<2*i+1; j++) {
            cout << '*';
        }
        cout << '\n';
    }

    for (int i=N/2-1; i>=0; i--) {
        for (int j=0; j<i; j++) cout << ' ';
        for (int j=0; j<2*i+1; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}