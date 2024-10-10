//problem "week1-5"
//created in 23:16:36 - Mon 23/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

void solve() {
    for (int i = 1; i <= 1000000; i++) {
        string s;
        getline(cin, s);
        for (int j = 0; j < s.size(); j++) {
            if (s[j] >= 'a' && s[j] <= 'z') {
                s[j] += 'A' - 'a';
            }
        }
        cout << s << "\n";
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