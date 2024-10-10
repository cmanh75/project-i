//problem "week2-2"
//created in 10:23:55 - Mon 30/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int d[N], x[N], n;

void per(int i) {
    if (i > n) {
        for (int j = 1; j <= n; j++) {
            cout << x[j] << " ";
        }
        cout << "\n";
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (!d[j]) {
            d[j] = 1;
            x[i] = j;
            per(i + 1);
            d[j] = 0;
        }
    }
}

void solve() {
    cin >> n;
    per(1);
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