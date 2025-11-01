#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int m;
vector<vector<int>> g(310, vector<int>(310, INT_MAX));
int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve() {
    cin >> m;
    for(int i = 0; i < m; i ++) {
        int x, y, t;
        cin >> x >> y >> t;
        for(int j = 0; j < 5; j ++) {
            int nx = x + dir[j][0], ny = y + dir[j][1];
            if(nx < 0 || ny < 0) continue;
            g[nx][ny] = min(g[nx][ny], t);
        }
    }

    queue<PII> q;
    vector<vector<int>> dis(310, vector<int>(310, -1));
    q.push({0, 0});
    dis[0][0] = 0;
    while(q.size()) {
        auto [x, y] = q.front();
        q.pop();
        if(g[x][y] == INT_MAX) {
            cout << dis[x][y];
            return;
        }
        for(int i = 1; i < 5; i ++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx < 0 || ny < 0) continue;
            if(dis[nx][ny] != -1) continue;
            if(g[nx][ny] != INT_MAX && dis[x][y] + 1 >= g[nx][ny]) continue;
            dis[nx][ny] = dis[x][y] + 1;
            q.push({nx, ny});
        }
    }
    cout << -1;
}

int main() {
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}