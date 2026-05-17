#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> arr;
int main() {

    cin >> N;
    double avg = 0;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
        avg += arr[i];
    }

    sort(arr.begin(), arr.end());
    for (int tmp : arr){
        cout << tmp << " ";
    }
    cout << endl;
    avg /= N;

    cout << avg << endl;
    return 0;
}
