#include<bits/stdc++.h>
using namespace std;
struct cmanh{
    int val;
    cmanh *le,*ri;
}*l,*r;
int n;
string s;
bool check(int k) {
    cmanh *i;
    i=l;
    do {
        i=i->ri;
        if (i->val==k) {
            return true;
        }
    } while (i!=r);
    return false;
}
void add(int x,cmanh *pre,cmanh *r) {
    cmanh *tmp;
    tmp=new cmanh();
    tmp->val=x;
    tmp->ri=r;
    tmp->le=pre;
    r->le=tmp;
    pre->ri=tmp;
}
void output() {
    cmanh *c;
    c=l->ri;
    do {
        cout<<c->val<<" ";
        c=c->ri;
    } while (c!=r);
}
void addlast(int x) {
    if (!check(x)) {
        add(x,r->le,r);
    }
}
void addfirst(int x) {
    if (!check(x)) {
        add(x,l,l->ri);
    }
}
void rev() {
    cmanh *i,*j;
    i=l;
    j=r;
    do {
        i=i->ri;
        j=j->le;
        swap(i->val,j->val);
    } while (i!=j&&i->ri!=j);
}
void remov(int k) {
    cmanh *i;
    i=l;
    do {
        i=i->ri;
        if (i->val==k) {
            (i->le)->ri=i->ri;
            (i->ri)->le=i->le;
            return;
        }
    } while (i!=r);
}
void addafter(int u,int v) {
    if (check(u)) {
        return;
    }
    cmanh *i;
    i=l;
    do {
        i=i->ri;
        if (i->val==v) {
            add(u,i,i->ri);
            return;
        }
    } while (i!=r);
}
void addbefore(int u,int v) {
    if (check(u)) {
        return;
    }
    cmanh *i;
    i=l;
    do {
        i=i->ri;
        if (i->val==v) {
            add(u,i->le,i);
            return;
        }
    } while (i!=r);
}
void solve() {
    l=new cmanh;
    r=new cmanh;
    l->ri=r;
    r->le=l;
    cin>>n;
    for (int i=1;i<=n;i++) {
        int x;
        cin>>x;
        addlast(x);
    }
    while (cin>>s) {
        if (s=="#") {
            break;
        }
        if (s=="addlast") {
            int x;
            cin>>x;
            addlast(x);
        }
        if (s=="addfirst") {
            int x;
            cin>>x;
            addfirst(x);
        }
        if (s=="addbefore") {
            int u,v;
            cin>>u>>v;
            addbefore(u,v);
        }
        if (s=="addafter") {
            int u,v;
            cin>>u>>v;
            addafter(u,v);
        }
        if (s=="remove") {
            int x;
            cin>>x;
            remov(x);
        }
        if (s=="reverse") {
            rev();
        }
    }
    output();
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int test=1;
    while(test--) {
        solve();
    }
}
