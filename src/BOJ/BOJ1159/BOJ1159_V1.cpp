#include <bits/stdc++.h>
using namespace std;
vector<char> result;
int cnt[26];
int solve(){
   for(int i = 0; i < 26; i++){
       if (cnt[i] >= 5) {
           result.push_back('a' + i);
       }
   }
   if (result.size() != 0)
       return 1;

   return 0;
}
int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        cnt[temp[0] - 'a']++;
    }

    if (solve()) {
        for (char c : result){
            cout << c;
        }
    } else {
        cout << "PREDAJA";
    }

    return 0;
}