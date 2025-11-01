#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n, a, b, k[210];

void solve() {
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i ++) cin >> k[i];

    queue<int> q;
    vector<int> dis(n + 1, -1);
    q.push(a);
    dis[a] = 0;
    while(q.size()) {
        auto u = q.front();
        q.pop();
        
        int v = u + k[u];
        if(v >= 1 && v <= n && dis[v] == -1) {
            dis[v] = dis[u] + 1;
            q.push(v);
        }
        v = u - k[u];
        if(v >= 1 && v <= n && dis[v] == -1) {
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }
    cout << dis[b];
}

int main() {
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}