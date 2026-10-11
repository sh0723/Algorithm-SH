#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int> > bitmap;

int check_same(int y, int x, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (bitmap[y][x] != bitmap[y+i][x+j]) {
                return 0;
            }
        }
    }
    return 1;
}

void solve(int y, int x, int size) {
    int half_size = size / 2;

    if (!check_same(y, x, size)) {
        cout << "(";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                solve(half_size*i + y, half_size*j + x, half_size);
            }
        }
        cout << ")";
        return;
    }
    cout << bitmap[y][x];


}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;


    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        bitmap.push_back(vector<int>());
        for (int j = 0; j < N; j++) {
            bitmap[i].push_back(s[j] - '0');
        }
    }

    solve(0,0,N);

    return 0;
}