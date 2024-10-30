//problem "week6-1"
//created in 14:32:46 - Wed 30/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, m, o = 0, l[N], c[N][N], f[N][N], d[N];
vector < int > a[N];

bool find(int s, int t) {
    queue < int > qu;
    qu.push(s);
    for (int i = 1; i <= n; i++) {
        d[i] = 0;
    }
    d[s] = 1;
    while (qu.size()) {
        int x = qu.front();
        qu.pop();
        if (x == t) {
            return true;
        }
        for (int j : a[x]) {
            if (f[x][j] < c[x][j] && !d[j]) {
                d[j] = d[x] + 1;
                qu.push(j);
            }
        }
    }
    return false;
}

int inc(int x, int t, int mi) {
    if (x == t) {
        return mi;
    }
    if (l[x] == o) {
        return 0;
    }
    l[x] = o;
    for (int j : a[x]) {
        if (d[j] == d[x] + 1 && f[x][j] < c[x][j]) {
            int y = inc(j, t, min(mi, c[x][j] - f[x][j]));
            if (y != 0) {
                f[x][j] += y;
                f[j][x] -= y;
                return y;
            }
        }
    }
    return 0;
}

void solve() {
    int s, t;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back(y);
        a[y].push_back(x);
        c[x][y] += z;
    }
    long long ans = 0;
    while (find(s, t)) {
        o++;
        while (1) {
            int x = inc(s, t, 1e9);
            ans += x;
            if (x == 0) {
                break;
            }
            o++;
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