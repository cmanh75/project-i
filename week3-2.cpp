//problem "week3-2"
//created in 19:38:37 - Thu 10/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

void solve() {
    string s;
    stack < int > st;
    while (cin >> s) {
        if (s == "#") {
            break;
        }
        if (s == "PUSH") {
            int x;
            cin >> x;
            st.push(x);
        }
        else {
            if (st.size()) {
                cout << st.top() << "\n";
                st.pop();
            }
            else {
                cout << "NULL" << "\n";
            }
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