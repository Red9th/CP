#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int m, n;
int g[310][310], f[310][310];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dfs(int x, int y, int pre) {
    if(x < 0 || x >= m || y < 0 || y >= n || g[x][y] >= pre) return 0;
    if(f[x][y]) return f[x][y];

    int res = 0;
    for(int i = 0; i < 4; i ++) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        res = max(res, dfs(nx, ny, g[x][y]));
    }
    return f[x][y] = res + 1;
}

void solve() {
    cin >> m >> n;
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> g[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            ans = max(ans, dfs(i, j, INT_MAX));
        }
    }
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