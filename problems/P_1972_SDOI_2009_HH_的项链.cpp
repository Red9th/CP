#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;
struct node {
    int l, r, sum;
} tr[N * 4];

int n, m, a[N];

struct query_node {
    int l, r, idx;
} q[N];

void maintain(int u) {
    tr[u].sum = tr[u * 2].sum + tr[u * 2 + 1].sum;
}

void build(int u, int l, int r) {
    tr[u] = {l, r, 0};
    if(l == r) return;
    int m = (l + r) / 2;
    build(u * 2, l, m);
    build(u * 2 + 1, m + 1, r);
    maintain(u);
}

void update(int u, int x, int upd) {
    if(tr[u].l == tr[u].r) {
        tr[u].sum += upd;
        return;
    }
    int m = (tr[u].l + tr[u].r) / 2;
    if(x <= m) update(u * 2, x, upd);
    else update(u * 2 + 1, x, upd);
    maintain(u);
}

int query(int u, int l, int r) {
    if(l <= tr[u].l && tr[u].r <= r) {
        return tr[u].sum;
    }
    int m = (tr[u].l + tr[u].r) / 2;
    int sum = 0;
    if(l <= m) sum += query(u * 2, l, r);
    if(r > m) sum += query(u * 2 + 1, l, r);
    return sum;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    build(1, 1, n);

    cin >> m;
    for(int i = 0; i < m; i ++) {
        cin >> q[i].l >> q[i].r;
        q[i].idx = i;
    }
    sort(q, q + m, [](query_node& a, query_node& b) {
        return a.r < b.r;
    });

    int vis[N]{};
    vector<PII> qs[N];
    vector<int> ans(m, 0);
    for(int i = 0; i < m; i ++) {
        qs[q[i].r].push_back({q[i].l, q[i].idx});
    }

    for(int i = 1; i <= n; i ++) {
        int x = a[i];
        if(vis[x]) {
            update(1, vis[x], -1);
        }
        update(1, i, 1);
        for(int j = 0; j < qs[i].size(); j ++) {
            int k = qs[i][j].first, idx = qs[i][j].second;
            ans[idx] = query(1, k, i);
        }
        vis[x] = i;
    }

    for(int i = 0; i < m; i ++) {
        cout << ans[i] << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}