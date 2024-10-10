//problem "week1-6"
//created in 23:16:13 - Sat 28/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], n, k;
long long s[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s[i] = s[i - 1] + x;
    }
    int ans = 0;
    for (int i = k; i <= n; i++) {
        ans += ((s[i] - s[i - k]) % 2 == 0);
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