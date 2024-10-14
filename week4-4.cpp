//problem "week4-4"
//created in 22:21:47 - Sun 13/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
map < int, bool > d;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (d.count(x)) {
            cout << 1;
        }
        else {
            cout << 0;
        }
        cout << "\n";
        d[x] = 1;
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