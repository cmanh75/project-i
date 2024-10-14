//problem "week3-5"
//created in 20:04:58 - Thu 10/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int rt, num = 1, d[N];

struct node {
    int left, right, value;
    node() {
        left = 0;
        right = 0;
        value = -1;
    }
} tree[N];

void insert(int i, int x) {
    if (tree[i].value == -1) {
        tree[i].value = x;
        return;
    }
    if (x > tree[i].value) {
        if (tree[i].right == 0) {
            tree[i].right = ++num;
        }
        insert(tree[i].right, x);
    }
    else {
        if (tree[i].left == 0) {
            tree[i].left = ++num;
        }
        insert(tree[i].left, x);
    }
}

void PreOrder(int i) {
    cout << tree[i].value << " ";
    if (tree[i].left) {
        PreOrder(tree[i].left);
    }
    if (tree[i].right) {
        PreOrder(tree[i].right);
    }
}

void solve() {
    string s;
    while (cin >> s) {
        if (s == "#") {
            break;
        }
        if (s == "insert") {
            int x;
            cin >> x;
            if (d[x]) {
                continue;
            }
            d[x] = 1;
            insert(1, x);
        }
    }
    PreOrder(1);
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