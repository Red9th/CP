#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
int n, m;
vector<int> g[N];
vector<int> vis(N, 0);
vector<int> ans(N, 0);
vector<int> f(N, 0);
queue<array<int, 3>> q;

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    string s;
    cin >> s;
    for(int i = 1; i <= n; i ++) {
        if(s[i - 1] == 'S') {
            f[i] = i;
            vis[i] = 1;
            q.push({i, 0, i});
        }
    }

    while(q.size()) {
        auto [u, dis, from] = q.front();
        q.pop();
        for(int v : g[u]) {
            if(vis[v] < 2 && f[v] != from) {
                vis[v] ++;
                ans[v] += dis + 1;
                f[v] = from;
                q.push({v, dis + 1, from});
            }
        }
    }

    for(int i = 1; i <= n; i ++) {
        if(s[i - 1] == 'D') {
            cout << ans[i] << endl;
        }
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