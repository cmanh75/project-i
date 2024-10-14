//problem "week4-1"
//created in 21:57:20 - Sun 13/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, a[N], d[N], m;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    int k = unique(a + 1, a + n + 1) - a - 1;
    int j = k;
    long long ans = 0;
    for (int i = 1; i <= j; i++) {
        while (j > i && a[i] + a[j] > m) {
            j--;
        }
        if (a[i] + a[j] == m) {
            if (i < j) {
                ans += 1ll * d[a[i]] * d[a[j]];
            }
            if (i == j) {
                ans += 1ll * (d[a[i]] - 1) * d[a[i]] / 2;
            }
        }
    }
    cout << ans;
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