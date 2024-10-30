//problem "week5-2"
//created in 10:28:03 - Mon 21/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, d[N];
vector < int > a[N];

void solve() {
    int n, m;
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
    queue < int > qu;
    for (int i = 1; i <= n; i++) {
        if (d[i]) {
            continue;
        }
        d[i] = 1;
        qu.push(i);
        while (qu.size()) {
            int x = qu.front();
            cout << x << " ";
            qu.pop();
            for (int j : a[x]) {
                if (!d[j]) {
                    qu.push(j);
                    d[j] = 1;
                }
            }
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