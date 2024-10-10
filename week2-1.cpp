//problem "week2-1"
//created in 10:12:34 - Mon 30/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int g[N];

int power(int x, int y) {
    if (!y) {
        return 1;
    }
    int t = power(x, y / 2);
    if (y & 1) {
        return 1ll * t * t % mod * x % mod; 
    }
    return 1ll * t * t % mod;
}

void solve() {
    int n, k;
    cin >> k >> n;
    g[0] = 1;
    for (int i = 1; i <= n; i++) {
        g[i] = 1ll * g[i - 1] * i % mod;
    }
    cout << 1ll * g[n] * power(g[k], mod - 2) % mod * power(g[n - k], mod - 2) % mod;
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