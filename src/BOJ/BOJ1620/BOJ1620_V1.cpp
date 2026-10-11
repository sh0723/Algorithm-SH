#include <bits/stdc++.h>
using namespace std;
int N,n;
map<string, vector<int>> result_map;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> n;

    for (int i=1; i<=N; i++) {
        string poketmon;
        cin >> poketmon;
        if (result_map.find(poketmon) != result_map.end()) {
            result_map[poketmon].push_back(i);
        } else {
            vector<int> temp;
            temp.push_back(i);
            result_map[poketmon] = temp;
        }
    }

    for (int i=1; i<=n; i++) {
        string input;
        cin >> input;
        int num;
        try {
            num = stoi(input);
            for (auto [key,value] : result_map) {
                if (find(value.begin(),value.end(), num) != value.end()) {
                    cout << key << "\n";
                    break;
                }

            }
        } catch (invalid_argument& e) {
            for (int num : result_map[input]) {
                cout << num << "\n";
            }
        }

    }

}