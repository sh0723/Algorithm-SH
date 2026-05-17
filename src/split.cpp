#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string& input, const string& delimiter) {
    vector<string> output;
    size_t start = 0;
    size_t end = input.find(delimiter);

    while (end != string::npos) { // npos는 "찾지 못함"을 뜻하는 string의 특수값
        output.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }

    output.push_back(input.substr(start));
    return output;
}

int main() {
    string str = "apple,banana,mango";
    vector<string> output = split(str, ",");

    for (const string& fruit : output) {
        cout << fruit << "\n";
    }

    return 0;
}
