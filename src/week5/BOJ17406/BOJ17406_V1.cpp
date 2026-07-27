#include <bits/stdc++.h>
using namespace std;
int A[101][101];
int N,M,C;
int rotate_input[6][3];
int ret = INT_MAX;

void run_rotate(int y, int x, int n){
    int temp1[101][101];
    for (int i=1; i<=n; i++) {
        memcpy(temp1, A, sizeof(A));
        int top = y-i;
        int bot = y+i;
        int left = x-i;
        int right = x+i;
        vector<pair<int, int>> idx;
        for (int j=left; j<=right; j++)
            idx.push_back({top,j});
        for (int j=top+1; j<=bot; j++)
            idx.push_back({j,right});
        for (int j=right-1; j>=left; j--)
            idx.push_back({bot,j});
        for (int j=bot-1; j>top; j--)
            idx.push_back({j,left});

        int idx_size = idx.size();
        for (int j=0; j<idx_size; j++) {
            int cy = idx[j].first;
            int cx = idx[j].second;

            int ny = idx[(j+1)%idx_size].first;
            int nx = idx[(j+1)%idx_size].second;

            temp1[ny][nx] = A[cy][cx];
        }
    }
    memcpy(A, temp1, sizeof(A));
}
void get_min_val() {
    for (int i=1; i<=N; i++) {
        int sum=0;
        for (int j=1; j<=M; j++) {
            sum += A[i][j];
        }
        ret = min(ret, sum);
    }
}
void solve(vector<int> order) {
    int temp1[101][101];
    memcpy(temp1, A, sizeof(A));
    for (int i=0; i<order.size(); i++) {
        run_rotate(rotate_input[order[i]][0], rotate_input[order[i]][1],rotate_input[order[i]][2]);
    }
    get_min_val();
    memcpy(A, temp1, sizeof(A));
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> C;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> A[i][j];
        }
    }

    vector<int> permute_vec(C);
    for (int i=0; i<C; i++) {
        cin >> rotate_input[i][0];
        cin >> rotate_input[i][1];
        cin >> rotate_input[i][2];
        permute_vec[i] = i;
    }

    do {
        solve(permute_vec);
    } while(next_permutation(permute_vec.begin(), permute_vec.end()));

    cout << ret;
    return 0;
}