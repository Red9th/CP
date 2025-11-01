#define LL long long
#define PII pair<int, int>

#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <tuple>
#include <iterator>
#include <string>
#include <string.h>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <sstream>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int n, m;
vector<pair<int, int>> g[1010];
int vis[1010][1024];

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    queue<pair<int, int>> q;
    q.push({1, 0});
    vis[1][0] = 1;

    int ans = INT_MAX;
    while(q.size()) {
        auto [u, s] = q.front();
        q.pop();
        if(u == n) {
            ans = min(ans, s);
        }
        for(auto [v, w] : g[u]) {
            if(!vis[v][s ^ w]) {
                vis[v][s ^ w] = 1;
                q.push({v, s ^ w});
            }
        }
    }
    cout << (ans == INT_MAX ? -1 : ans);
}

int main() {
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}