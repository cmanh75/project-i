//problem "week1-13"
//created in 23:51:54 - Sat 28/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

void solve() {
    string s;
    cin >> s;
    int ok = 1;
    if (s.size() != 8) {
        ok = 0;
    }
    ok &= (s[2] == ':' && s[5] == ':');
    for (int i = 0; i < s.size(); i++) {
        if (i != 2 && i != 5) {
            ok &= (s[i] >= '0' && s[i] <= '9');
        }
    }
    if (!ok) {
        cout << "INCORRECT";
        return;
    }
    int hh = (s[0] - '0') * 10 + s[1] - '0'; 
    int mm = (s[3] - '0') * 10 + s[4] - '0'; 
    int ss = (s[6] - '0') * 10 + s[7] - '0'; 
    ok &= (hh <= 23 && mm <= 59 && ss <= 59);
    if (!ok) {
        cout << "INCORRECT";
    }
    else {
        cout << hh * 3600 + mm * 60 + ss;
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