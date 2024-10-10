//problem "week1-2"
//created in 23:01:27 - Mon 23/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], f[N][22];

void solve() {
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        f[i][0] = a[i];
    }
    int ma = a[1], mi = a[1];
    for (int i = 1; i <= n; i++) {
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
    }
    for (int i = 1; i <= log2(n); i++) {
        for (int j = 1; j <= n - (1 << i) + 1; j++) {
            f[j][i] = max(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
        }
    }
    while (1) {
        string s;
        cin >> s;
        if (s == "*") {
            continue;
        }
        if (s == "***") {
            break;
        }
        if (s == "find-max") {
            cout << ma << "\n";
        }
        if (s == "find-min") {
            cout << mi << "\n";
        }
        if (s == "find-max-segment") {
            int x, y;
            cin >> x >> y;
            int o = log2(y - x + 1);
            cout << max(f[x][o], f[y - (1 << o) + 1][o]) << "\n";
        }
        if (s == "sum") {
            cout << sum << "\n";
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