//problem "week1-9"
//created in 23:59:14 - Sat 28/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

void solve() {
    double a, b, c;
    cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0) {
            if (c != 0) {
                cout << "NO SOLUTION";
            }
        }
        else {
            cout << fixed << setprecision(2) << -c / b;
        }
    }
    else {
        double delta = b * b - a * c * 4;
        if (delta < 0) {
            cout << "NO SOLUTION";
        }
        else {
            double x1 = (-b - sqrt(delta)) / 2 / a;
            double x2 = (-b + sqrt(delta)) / 2 / a;
            if (delta == 0) {
                cout << fixed << setprecision(2) << x1;
            }
            else {
                cout << fixed << setprecision(2) << x1 << " " << x2;
            }
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