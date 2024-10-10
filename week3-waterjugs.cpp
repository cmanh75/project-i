//problem "waterjugs"
//created in 14:32:43 - Thu 10/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int d[N][N];
queue < pair < int, int > > qu;

void new_state(int x, int y, int z) {
    if (x >= 0 && y >= 0 && !d[x][y]) {
        d[x][y] = z + 1;
        qu.push({x, y});
    }
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    qu.push({0, 0});
    while (qu.size()) {
        pair < int, int > x = qu.front();
        qu.pop();
        int r = d[x.first][x.second];
        if (x.first == c || x.second == c) {
            cout << d[x.first][x.second];
            return;
        }
        new_state(a, x.second, r);
        new_state(x.first, b, r);
        new_state(0, x.second, r);
        new_state(x.first, 0, r);
        int z = min(a - x.first, x.second);
        new_state(x.first + z, x.second - z, r);
        z = min(b - x.second, x.first);
        new_state(x.first - z, x.second + z, r);
    }
    cout << -1;
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