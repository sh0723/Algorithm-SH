#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    for (int i=0; i<n-1; i++) {
        int min_num = arr[i];
        int min_index = i;
        for (int j=i+1; j<n; j++) {
            if (min_num > arr[j]) {
                min_num = arr[j];
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = min_num;
        arr[min_index] = temp;
        for (int j=0; j<n; j++) cout << arr[j] << ' ';
        cout << '\n';
    }

    return 0;
}