#include <bits/stdc++.h>
using namespace std;
map<string, int> array_to_int;
vector<string> int_to_array;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, n;
    cin >> N >> n;

    for (int i=1; i<=N; i++) {
        string input;
        cin >> input;
        array_to_int[input] = i;
        int_to_array.push_back(input);
    }

    for (int i=1; i<=n; i++) {
        string input;
        cin >> input;
        int num = atoi(input.c_str());
        if (num == 0) {
            cout << array_to_int[input] << "\n";
        } else {
            cout << int_to_array[num-1] << "\n";
        }
    }

}