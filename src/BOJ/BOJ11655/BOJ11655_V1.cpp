#include <bits/stdc++.h>
using namespace std;
int check_alphabet(char c){
    if (c >= 'A' && c <= 'Z'){
        return 1;
    } else if (c >= 'a' && c <= 'z'){
        return 2;
    }

    return 0;
}
int main(){

    string input;
    string output = "";
    getline(cin, input);

    for(char c : input) {
        int tmp;
        int check = check_alphabet(c);
        if (check){
            tmp = c + 13;
            if (check == 1 && tmp > 'Z'){
                tmp = tmp - 'Z' + 'A' - 1;
            } else if (check == 2 && tmp > 'z') {
                tmp = tmp - 'z' + 'a' - 1;
            }
        } else {
            tmp = c;
        }
        output += (char)tmp;
    }

    cout << output;
    return 0;
}