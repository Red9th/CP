#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;
using TUP = array<int, 3>;

const int N = 5010;
int n, r;
vector<PII> g[N];
vector<int> dis1(N, INT_MAX);
vector<int> dis2(N, INT_MAX);
priority_queue<PII, vector<PII>, greater<PII>> q;

void solve() {
    cin >> n >> r;
    for(int i = 0; i < r; i ++) {
        int u, v, d;
        cin >> u >> v >> d;
        g[u].push_back({v, d});
        g[v].push_back({u, d});
    }

    dis1[1] = 0;
    q.push({0, 1});
    while(q.size()) {
        auto [d, u] = q.top();
        q.pop();
        if(d > dis2[u]) continue;

        for(auto [v, w] : g[u]) {
            int nd = d + w;
            if(dis1[v] > nd) {
                swap(nd, dis1[v]);
                q.push({dis1[v], v});
            }
            if(dis1[v] < nd && nd < dis2[v]) {
                dis2[v] = nd;
                q.push({dis2[v], v});
            }
        }
    }
    cout << dis2[n];
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