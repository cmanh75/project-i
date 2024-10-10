//problem "week1-14"
//created in 00:14:22 - Sun 29/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector < pair < int, double > > a = {{0, 0}, {50, 1.728}, {100, 1.786}, {200, 2.074}, {300, 2.612}, {400, 2.919}};
vector < pair < int, double > > b = {{0, 0}, {100, 1.728}, {200, 2.074}, {400, 2.612}, {700, 3.111}};

double cost(vector < pair < int, double > > a, int x, double last) {
    double sum = 0;
    for (int i = 1; i < a.size(); i++) {
        sum += ((min(a[i].first, x) - a[i - 1].first) * a[i].second);
        if (a[i].first > x) {
            break;
        }
    }
    if (x > a.back().first) {
        sum += (x - a.back().first) * last;
    }
    return sum;
}

void solve() {
    int x;
    cin >> x;
    double cc = cost(a, x, 3.015);
    double nc = cost(b, x, 3.457);
    cout << fixed << setprecision(2) << (nc - cc) * 1100;
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