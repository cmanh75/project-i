//problem "week4-2"
//created in 22:10:21 - Sun 13/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

map < string, bool> dictionary;

void solve() {
    string s;
    while (cin >> s) {
        if (s == "*") {
            break;
        }
        dictionary[s] = 1;
    }
    while (cin >> s) {
        if (s == "***") {
            break;
        }
        if (s == "find") {
            string t;
            cin >> t;
            if (dictionary.count(t)) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
        else {
            string t;
            cin >> t;
            if (dictionary.count(t)) {
                cout << 0;
            }
            else {
                cout << 1;
                dictionary[t] = 1;
            }
        }
        cout << "\n";
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