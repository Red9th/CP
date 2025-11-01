#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
unordered_map<int, int> vis;
unordered_map<int, vector<int>> g;

void dfs(int u) {
    if(vis[u]) return;
    ans = max(ans, u);
    vis[u] = 1;
    for(auto v : g[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    cout << ans;
}

int main() {
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}