#include <bits/stdc++.h>
using namespace std;
map<string, int> clothes_map;
vector<string> split(string str, string delimeter){
    auto begin = 0;
    auto end = str.find(delimeter);
    vector<string> tokens;
    while(end != string::npos){
        tokens.push_back(str.substr(begin, end-begin));
        begin = end + 1;
        end = str.find(delimeter, begin);
    }
    tokens.push_back(str.substr(begin));
    return tokens;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        cin.ignore();
        for (int j = 1; j <= n; j++) {
            string cloth;
            getline(cin, cloth);
            vector<string> clothes = split(cloth, " ");
            clothes_map[clothes[1]]++;
        }
        int sum = 1;
        for (auto [key, value] : clothes_map) {
            sum = sum * (value + 1);
        }
        sum -= 1;

        cout << sum << "\n";
        clothes_map.clear();
    }



    return 0;
}