//problem "week2-5"
//created in 11:05:52 - Mon 30/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, x[40];

void cal(int i) {
    if (i == n) {
        for (int j = 0; j < n; j++) {
            cout << x[j];
        }
        cout << "\n";
        return;
    }
    x[i] = 0;
    cal(i + 1);
    x[i] = 1;
    cal(i + 1);
}

void solve() {
    cin >> n;
    cal(0);
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