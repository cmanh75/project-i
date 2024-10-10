//problem "week3-1"
//created in 19:33:19 - Thu 10/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

void solve() {
    string s;
    stack < int > st;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(i);
        }
        else {
            if (st.empty()) {
                cout << 0;
                return;
            }
            else {
                if (s[i] == ')' && s[st.top()] == '(') {
                    st.pop();
                    continue;
                }
                if (s[i] == ']' && s[st.top()] == '[') {
                    st.pop();
                    continue;
                }
                if (s[i] == '}' && s[st.top()] == '{') {
                    st.pop();
                    continue;
                }
                cout << 0;
                return;
            }
        }
    }
    if (!st.empty()) {
        cout << 0;
        return;
    }
    cout << 1;
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