//problem "week4-3"
//created in 22:15:50 - Sun 13/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, f[N];

void solve() {
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        f[i] = 1ll * f[i - 1] * 256 % m;
    }
    for (int j = 1; j <= n; j++) {
        string s;
        cin >> s;
        int hash = 0;
        for (int i = 0; i < s.size(); i++) {
            hash = (hash + 1ll * f[s.size() - 1 - i] * s[i] % m) % m;
        }
        cout << hash << "\n";
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