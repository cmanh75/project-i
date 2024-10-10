//problem "week2-4"
//created in 10:31:22 - Mon 30/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int r[10][10], c[10][10], a[10][10], ans = 0;

void cal(int x, int y) {
    if (x == 9) {
        int ok = 0;
        for (int i = 2; i < 9; i += 3) {
            for (int j = 2; j < 9; j += 3) {
                vector < int > l(10, 0);
                for (int k = i - 2; k <= i; k++) {
                    for (int h = j - 2; h <= j; h++) {
                        if (l[a[k][h]]) {
                            ok = 1;
                        } 
                        l[a[k][h]] = 1;
                    }
                }
            }
        }
        ans += (!ok);
        return;
    }
    if (a[x][y]) {
        cal(x + (y + 1) / 9, (y + 1) % 9);
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (!r[x][i] && !c[y][i]) {
            r[x][i] = 1;
            c[y][i] = 1;
            a[x][y] = i;
            cal(x + (y + 1) / 9, (y + 1) % 9);
            a[x][y] = 0;
            r[x][i] = 0;
            c[y][i] = 0;
        }
    }
}

void solve() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int x;
            cin >> x;
            a[i][j] = x;
            if (x != 0) {
                r[i][x] = 1;
                c[j][x] = 1;
            }
        }
    }
    cal(0, 0);
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