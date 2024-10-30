//problem "week5-1"
//created in 10:18:33 - Mon 21/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, d[N];
vector < int > a[N];

void dfs(int i) {
    cout << i << " ";
    d[i] = 1;
    for (int j : a[i]) {
        if (!d[j]) {
            dfs(j);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        sort(a[i].begin(), a[i].end());
    }
    for (int i = 1; i <= n; i++) {
        if (!d[i]) {
            dfs(i);
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