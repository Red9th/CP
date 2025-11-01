#define ll long long
#define pii pair<int, int>

#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <cmath>
#include <climits>
#include <unordered_map>
using namespace std;

int n, m;
vector<tuple<int, int, int>> edges;
vector<int> g[200010];

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int lim = (1 << 30) - 1;
    int ans = lim;
    for(int bit = 29; bit >= 0; bit --) {
        // bfs，且路径上的or值不能让前面已经确定的0变成 1，也就是根据之前已经确定的 0 删掉不能用的w，再bfs，看能否到达终点
        for(int i = 1; i <= n; i ++) g[i].clear();
        int x = ans - (1 << bit);
        int cur = x ^ lim;
        for(auto [u, v, w] : edges) {
            if((w & cur) == 0) {
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }

        queue<int> q;
        int vis[n + 1] = {0};
        q.push(1);
        vis[1] = 1;
        while(q.size()) {
            int t = q.front();
            q.pop();
            for(auto to : g[t]) {
                if(!vis[to]) {
                    vis[to] = 1;
                    q.push(to);
                }
            }
        }
        if(vis[n]) {
            ans -= (1 << bit);
        }
    }
    cout << ans;
    return 0;
}