//problem "week1-8"
//created in 23:21:05 - Sat 28/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

void solve() {
    string p1, p2, s;
    getline(cin, p1);
    getline(cin, p2);
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s.substr(i, p1.size()) == p1) {
            cout << p2;
            i = i + p1.size() - 1;
        }
        else {
            cout << s[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #define task "test"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test = 1;
    while (test--) {
        solve();
    }
}