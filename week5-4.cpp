//problem "week5-4"
//created in 10:39:41 - Mon 21/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, d[N], ans = 0;
vector < int > a[N];

void dfs(int i, int k) {
    if (k == n) {
        int ok = 0;
        for (int j : a[i]) {
            if (j == 1) {
                ok = 1;
                break;
            }
        }
        ans |= ok;
        return;
    }
    for (int j : a[i]) {
        if (!d[j]) {
            d[j] = 1;
            dfs(j, k + 1);
            d[j] = 0;
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        a[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    d[1] = 1;
    dfs(1, 1);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #define task "test"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
}