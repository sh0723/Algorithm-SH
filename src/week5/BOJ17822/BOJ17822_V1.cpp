#include <bits/stdc++.h>
using namespace std;
int N,M,T;
int circle[51][51];
bool find_target[51][51];
void rotate_circle(int idx, int how,  int dir) {
    int temp[51];
    if (dir == 0) {
        for (int i=0; i<M; i++) {
            temp[(i+how)%M] = circle[idx][i];
        }
    } else {
        for (int i=0; i<M; i++) {
            temp[i] = circle[idx][(i+how)%M];
        }
    }
    memcpy(circle[idx], temp, sizeof(int) * M);
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> T;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> circle[i][j];
        }
    }


    for (int i=0; i<T; i++) {
        int x,d,k;
        cin >> x >> d >> k;
        for (int j=1; j<=N; j++) {
            if (j%x == 0)
                rotate_circle(j-1,k,d);
        }

        bool is_find = false;

        for (int j=1; j<N; j++) {
            for (int l=0; l<M; l++) {
                if (circle[j][l] == 0) continue;
                if (circle[j][l] == circle[j-1][l] ) {
                    find_target[j][l] = true;
                    find_target[j-1][l] = true;
                    is_find = true;
                }
            }
        }
        for (int j=0; j<N; j++) {
            for (int l=0; l<M; l++) {
                if (circle[j][l] == 0) continue;
                if (l != M-1) {
                    if (circle[j][l] == circle[j][l+1]) {
                        find_target[j][l] = true;
                        find_target[j][l+1] = true;
                        is_find = true;
                    }
                } else {
                    if (circle[j][M-1] == circle[j][0]) {
                        find_target[j][M-1] = true;
                        find_target[j][0] = true;
                        is_find = true;
                    }
                }
            }
        }

        if (!is_find) {
            long long sum=0;
            int cnt=0;
            for (int j=0; j<N; j++) {
                for (int l=0; l<M; l++) {
                    if (circle[j][l] == 0) continue;
                    cnt++;
                    sum += circle[j][l];
                }
            }

            for (int j=0; j<N; j++) {
                for (int l=0; l<M; l++) {
                    if (circle[j][l] == 0) continue;
                    if (sum > circle[j][l] * cnt) {
                        circle[j][l] += 1;
                    } else if (sum < circle[j][l] * cnt) {
                        circle[j][l] -= 1;
                    }
                }
            }
        } else {
            for (int j=0; j<N; j++) {
                for (int l=0; l<M; l++) {
                    if (find_target[j][l])
                        circle[j][l] = 0;
                }
            }
        }
        memset(find_target, false, sizeof(find_target));
    }

    int sum=0;
    for (int i=0; i<N; i++) {
        for (int j=0;j<M; j++) {
            sum += circle[i][j];
        }
    }

    cout << sum;
    return 0;
}