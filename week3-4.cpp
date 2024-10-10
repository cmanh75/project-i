//problem "week3-4"
//created in 19:58:25 - Thu 10/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

void solve() {
    string s;
    queue < int > qu;
    while (cin >> s) {
        if (s == "#") {
            break;
        }
        if (s == "PUSH") {
            int x;
            cin >> x;
            qu.push(x);
        }
        else {
            if (!qu.size()) {
                cout << "NULL" << "\n";
                continue;
            }
            cout << qu.front() << "\n";
            qu.pop();
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