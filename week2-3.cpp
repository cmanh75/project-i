//problem "week2-3"
//created in 10:26:32 - Mon 30/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    long long pre = 0, cur = 1;
    for (int i = 2; i <= n; i++) {
        long long temp = cur;
        cur += pre;
        pre = temp;
    }
    cout << pre;
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