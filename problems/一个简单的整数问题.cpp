#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
struct node {
    int l, r, sum, lazy;
} tr[N * 4];

int n, m, a[N];

void maintain(int u) {
    tr[u].sum = tr[u * 2].sum + tr[u * 2 + 1].sum;
}

void build(int u, int l, int r) {
    tr[u] = {l, r};
    tr[u].lazy = 0;
    if(l == r) {
        tr[u].sum = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(u * 2, l, m);
    build(u * 2 + 1, m + 1, r);
    maintain(u);
}

// 将懒标记作用到节点 u
void apply(int u, int upd) {
    tr[u].sum += upd * (tr[u].r - tr[u].l + 1);
    tr[u].lazy += upd;
}

// 将节点 u 的懒标记下传给左右子节点
void spread(int u) {
    int upd = tr[u].lazy;
    if(upd == 0) return;
    apply(u * 2, upd);
    apply(u * 2 + 1, upd);
    tr[u].lazy = 0;
}

// 给区间 [l, r] 加上 upd
void update(int u, int l, int r, int upd) {
    if(l <= tr[u].l && tr[u].r <= r) {
        apply(u, upd);
        return;
    }
    spread(u);
    int m = (tr[u].l + tr[u].r) / 2;
    if(l <= m) update(u * 2, l, r, upd);
    if(r > m) update(u * 2 + 1, l, r, upd);
    maintain(u);
}

// 查询区间 [l, r] 的前缀和
int query(int u, int l, int r) {
    if(l <= tr[u].l && tr[u].r <= r) {
        return tr[u].sum;
    }
    spread(u);
    int m = (tr[u].l + tr[u].r) / 2;
    int sum = 0;
    if(l <= m) sum += query(u * 2, l, r);
    if(r > m) sum += query(u * 2 + 1, l, r);
    return sum;
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    build(1, 1, n);
    while(m --) {
        char op;
        int l, r, d, x;
        cin >> op;
        if(op == 'C') {
            cin >> l >> r >> d;
            update(1, l, r, d);
        } else {
            cin >> x;
            cout << query(1, x, x);
        }
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}