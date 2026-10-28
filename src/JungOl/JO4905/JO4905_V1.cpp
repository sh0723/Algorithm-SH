#include <bits/stdc++.h>
using namespace std;
struct patient {
    string name;
    int age;
    float bld;
};

struct Compare{
    bool operator()(patient a, patient b){
        if (b.bld == a.bld) return a.age < b.age;

        return a.bld < b.bld;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    priority_queue<patient, vector<patient>,Compare> pq;

    while(N--) {
        string s;
        cin >> s;
        if (s == "pop") {
            if (!pq.empty()) {
                cout << pq.top().name << '\n';
                pq.pop();
            }
        } else if (s == "push") {
            string name;
            int age;
            float bld;
            cin >> name >> age >> bld;
            pq.push({name,age,bld});
        }
    }

    return 0;
}