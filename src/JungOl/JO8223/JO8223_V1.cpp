#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int arr[10];
    vector<int> ret;
    cin >> n >> arr[0];
    for (int i=1; i<n; i++) {
        cin >> arr[i];
        ret.push_back(arr[i]+ arr[i-1]);
    }

    while(true) {
        if (ret.empty()) break;
        for (int i=0; i<ret.size(); i++) cout << ret[i] << ' ';
        cout << '\n';
        vector<int> temp;
        for (int i=1; i<ret.size(); i++) temp.push_back(ret[i] + ret[i-1]);
        ret.clear();
        ret = temp;
    }


    return 0;
}