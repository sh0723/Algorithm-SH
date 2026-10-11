#include <bits/stdc++.h>
using namespace std;
int n;
string pattern;
vector<string> tokens;
vector<string> strs;
vector<int> result;
int check(string str){
    string prefix = tokens[0];
    string suffix = tokens[1];

    if (str.size() < prefix.size() + suffix.size()) {
        return 0;
    }

    if (str.find(prefix) != 0) {
        return 0;
    }

    if (str.rfind(tokens[1]) != (str.length() - suffix.size())) {
        return 0;
    }

    return 1;
}
void split(string s, string delimeter){
    auto start = 0;
    auto end = s.find(delimeter);

    while(end != string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + delimeter.length();
        end = s.find(delimeter, start);
    }

    tokens.push_back(s.substr(start));

}
int main(){

    cin >> n >> pattern;

    for (int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        strs.push_back(tmp);
    }

    split(pattern, "*");

    for (int i = 0; i < n; i++){
        if (check(strs[i])) {
            cout << "DA" << endl;
        } else {
            cout << "NE" << endl;
        }
    }

    return 0;

}