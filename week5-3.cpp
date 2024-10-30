//problem "week5-3"
//created in 10:32:51 - Mon 21/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, lab[N];
pair < int, pair < int, int > > a[N];

int rt(int x) {
    return (lab[x] < 0 ? x : lab[x] = rt(lab[x]));
}

bool join(int x, int y) {
    int u = rt(x);
    int v = rt(y);
    if (u == v) {
        return false;
    } 
    if (lab[u] < lab[v]) {
        swap(lab[u], lab[v]);
    }
    lab[u] += lab[v];
    lab[v] = u;
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        lab[i] = -1;
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i].second.first >> a[i].second.second >> a[i].first;
    }
    sort(a + 1, a + m + 1);
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        if (join(a[i].second.first, a[i].second.second)) {
            ans += a[i].first;
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