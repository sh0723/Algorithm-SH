#include <bits/stdc++.h>
using namespace std;
bool visited[100001];
int inp[100001];
long long cnt;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int st=0;
    for (int i=0; i<N; i++) {
        cin >> inp[i];
    }

    for (int ed=0; ed<N; ed++){
        while(visited[inp[ed]]) {
            visited[inp[st]] = false;
            st++;
        }

        visited[inp[ed]] = true;
        cnt += (ed - st + 1);
    }

    cout << cnt;

    return 0;
}