#include <bits/stdc++.h>
using namespace std;
vector<queue<int>> q_vector;
vector<int> inp;
bool connected[101];
int connected_cnt;
int N,K;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    cin >> K;
    q_vector.resize(K+1,queue<int>());
    for (int i=0; i<K; i++) {
        int temp;
        cin >> temp;
        inp.push_back(temp);
        q_vector[temp].push(i);
    }
    int ret = 0;
    for (int i=0; i<K; i++) {
        q_vector[inp[i]].pop();
        if (connected_cnt == N) {
            if (connected[inp[i]]) continue;
            else {
                int max_val = 0;
                int max_index = K+1;
                for (int j=1; j<K+1; j++) {
                    if (connected[j] && q_vector[j].empty()) {
                        max_index = j;
                        break;
                    } else if (connected[j] && q_vector[j].size()) {
                        if (max_val < q_vector[j].front()) {
                            max_val = q_vector[j].front();
                            max_index = j;
                        }
                    }
                }
                ret++;
                connected[max_index] = false;
                connected[inp[i]] = true;
            }
        } else {
            if (connected[inp[i]]) continue;
            else {
                connected_cnt++;
                connected[inp[i]] = true;
            }
        }
    }

    cout << ret;
    return 0;
}