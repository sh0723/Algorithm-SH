#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;

    vector<int> arr(N);
    vector<pair<int, int>> ret(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    ret[N-1] = {arr[N-1],-1};
    for (int i=N-2; i>=0; i--) {
        if (arr[i] < arr[i+1]) {
            ret[i].first = arr[i+1];
            ret[i].second = i+1;
        } else if (ret[i+1].second == -1) {
            ret[i].first = arr[i];
            ret[i].second = -1;
        } else {
            int temp_num = i+1;
            while(true) {
                if (temp_num == -1) {
                    ret[i].first = arr[i];
                    ret[i].second = temp_num;
                    break;
                }

                if (ret[temp_num].first > arr[i]) {
                    ret[i].first = ret[temp_num].first;
                    ret[i].second = ret[temp_num].second;
                    break;
                } else {
                    temp_num = ret[temp_num].second;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (ret[i].second == -1) {
            cout << -1 << " ";
        } else {
            cout << ret[i].first << " ";
        }
    }


    return 0;
}