#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N];
struct node {
    int l, r, sum;
} tr[N * 4];

void pushup(int u) {
    tr[u].sum = tr[u * 2].sum + tr[u * 2 + 1].sum;
}

void build(int u, int l, int r) {
    if(l == r) {
        tr[u] = {l, r, a[l]};
        return;
    }
    int m = (l + r) / 2;
    build(u * 2, l, m);
    build(u * 2 + 1, m + 1, r);
    tr[u].l = l, tr[u].r = r;
    pushup(u);
}

// 第 a 个数加上 b
void modify(int u, int a, int b) {
    if(tr[u].l == tr[u].r) {
        tr[u].sum += b;
        return;
    }
    int m = (tr[u].l + tr[u].r) / 2;
    if(a <= m) modify(u * 2, a, b);
    else modify(u * 2 + 1, a, b);
    pushup(u);
}

// 节点 u 维护的区间 [tr[u].l, tr[u].r] 与 [l, r] 的交集部分的和
int query(int u, int l, int r) {
    if(l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
    int m = (tr[u].l + tr[u].r) / 2;
    int sum = 0;
    if(l <= m) sum += query(u * 2, l, r);
    if(r > m) sum += query(u * 2 + 1, l, r);
    return sum;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    build(1, 1, n);

    while(m --) {
        int k, a, b;
        cin >> k >> a >> b;
        if(k == 0) {
            cout << query(1, a, b) << endl;
        } else {
            modify(1, a, b);
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