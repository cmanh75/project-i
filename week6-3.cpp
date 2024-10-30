//problem "week6-3"
//created in 14:56:46 - Wed 30/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector < pair < int, int > > a[N];
int n, m;
long long d[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back(make_pair(y, z));
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            d[i] = 1e18;
        }
        d[j] = 0;
        priority_queue < pair < long long, int >, vector < pair < long long, int > >, greater < pair < long long, int > > > pq;
        pq.push(make_pair(0, j));
        while (pq.size()) {
            pair < long long, int > x = pq.top();
            pq.pop();
            if (x.first != d[x.second]) {
                continue;
            }
            for (pair < long long, int > j : a[x.second]) {
                if (d[j.first] > x.first + j.second) {
                    d[j.first] = x.first + j.second;
                    pq.push(make_pair(d[j.first], j.first));
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << d[i] << " ";
        }
        cout << "\n";
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