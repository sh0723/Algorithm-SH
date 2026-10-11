#include <bits/stdc++.h>
using namespace std;
int main() {

    int n;
    cin >> n;
    int arr[100000];

    for (int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n);
    int target;
    cin >> target;
    int st=0, ed=n-1, ret=0;
    while(st < ed) {
        if (arr[st] + arr[ed] < target) {
            st++;
        } else if (arr[st] + arr[ed] > target) {
            ed--;
        } else {
            ret++;
            st++;
            ed--;
        }
    }

    cout << ret;

    return 0;
}