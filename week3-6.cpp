//problem "week3-6"
//created in 20:42:21 - Thu 10/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int height = 0;
vector < string > r;
map < string, int> c, d, w;
map < string, vector < string > > a;

void dfs(string i) {
    c[i] = 1;
    for (string j : a[i]) {
        d[j] = d[i] + 1;
        height = max(height, d[j]);
        dfs(j);
        c[i] += c[j];
    }
}

void solve() {
    string x, y, rt;
    while (cin >> x) {
        if (x == "***") {
            break;
        }
        cin >> y;
        r.push_back(y);
        w[x] = 1;
        a[y].push_back(x);
    }
    for (string j : r) {
        if (w.count(j) == 0) {
            rt = j;
        }
    }
    dfs(rt);
    while (cin >> x) {
        if (x == "***") {
            break;
        }
        cin >> y;
        if (x == "descendants") {
            cout << c[y] - 1 << "\n";
        }
        else {
            cout << height - d[y] << "\n";
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