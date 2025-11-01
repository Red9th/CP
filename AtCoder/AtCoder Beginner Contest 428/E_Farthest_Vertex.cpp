#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> g[500010];
int f[500010];

vector<int> bfs(int x) {
    vector<int> dis(n + 1);
    queue<int> q;
    q.push(x);
    dis[x] = 1;

    while(q.size()) {
        auto u = q.front();
        q.pop();
        for(auto v : g[u]) {
            if(!dis[v]) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto dis = bfs(1);
    int x = 1;
    for(int i = 1; i <= n; i ++) {
        if(dis[i] >= dis[x]) {
            x = i;
        }
    }
    auto dis_x = bfs(x);
    int y = 1;
    for(int i = 1; i <= n; i ++) {
        if(dis_x[i] >= dis_x[y]) {
            y = i;
        }
    }
    auto dis_y = bfs(y);
    for(int i = 1; i <= n; i ++) {
        if(dis_x[i] > dis_y[i]) {
            cout << x << endl;
        } else if(dis_x[i] < dis_y[i]) {
            cout << y << endl;
        } else {
            cout << max(x, y) << endl;
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