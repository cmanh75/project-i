//problem "week1-10"
//created in 23:30:04 - Sat 28/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
string t[5];
int f[5];

void solve() {
    string s;
    cin >> s;
    if (s.size() != 10) {
        cout << "INCORRECT";
        return;
    }
    t[0] = s.substr(0, 4);
    t[1] = s.substr(5, 2);
    t[2] = s.substr(8, 2);
    int ok = (s[4] == '-' && s[7] == '-');
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < t[i].size(); j++) {
            ok &= (t[i][j] >= '0' && t[i][j] <= '9');
            f[i] = f[i] * 10 + (t[i][j] - '0');
        }
    }
    ok &= (f[1] <= 12);
    if (f[1] == 1 && f[1] == 3 && f[1] == 5 && f[1] == 7 && f[1] == 8 && f[1] == 10 && f[1] == 12) {
        ok &= (f[2] <= 31);
    }
    else {
        if (f[1] == 2) {
            if (f[0] % 4 == 0 && f[0] % 100 != 0) {
                ok &= (f[2] <= 29);
            }
            else {
                ok &= (f[2] <= 28);
            }
        }
        else {
            ok &= (f[2] <= 30);
        }
    }
    if (!ok) {
        cout << "INCORRECT";
    }
    else {
        cout << f[0] << " " << f[1] << " " << f[2];
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