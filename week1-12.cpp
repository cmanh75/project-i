//problem "week1-12"
//created in 23:49:41 - Sat 28/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    int d = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        d += (x & 1);
    }
    cout << d << " " << n - d;
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