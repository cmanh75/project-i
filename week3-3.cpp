//problem "week3-3"
//created in 19:44:30 - Thu 10/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector < int > a[N];

void PreOrder(int i) {
    cout << i << " ";
    for (int j : a[i]) {
        PreOrder(j);
    }
}

void InOrder(int i) {
    if (a[i].size()) {
        InOrder(a[i][0]);
    }
    cout << i << " ";
    for (int j = 1; j < a[i].size(); j++) {
        InOrder(a[i][j]);
    }
}

void PostOrder(int i) {
    for (int j : a[i]) {
        PostOrder(j);
    }
    cout << i << " ";
}

void solve() {
    string s;
    int root;
    while (cin >> s) {
        int x, y;
        if (s == "MakeRoot") {
            cin >> x;
            root = x;
            continue;
        }
        if (s == "Insert") {
            cin >> x >> y;
            a[y].push_back(x);
            continue;
        }
        if (s == "InOrder") {
            InOrder(root);
        }
        if (s == "PreOrder") {
            PreOrder(root);
        }
        if (s == "PostOrder") {
            PostOrder(root);
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