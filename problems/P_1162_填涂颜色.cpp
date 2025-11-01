#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n, g[35][35], vis[35][35];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int x, int y) {
    vis[x][y] = 1;
    for(int i = 0; i < 4; i ++) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(vis[nx][ny] || g[nx][ny] == 1) continue;
        dfs(nx, ny);
    }
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> g[i][j];
        }
    }

    for(int i = 0; i < n; i ++) {
        if(g[0][i] == 0 && !vis[0][i]) dfs(0, i);
        if(g[n - 1][i] == 0 && !vis[n - 1][i]) dfs(n - 1, i);
        if(g[i][0] == 0 && !vis[i][0]) dfs(i, 0);
        if(g[i][n - 1] == 0 && !vis[i][n - 1]) dfs(i, n - 1);
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(!vis[i][j] && g[i][j] == 0) {
                g[i][j] = 2;
            }
        }
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cout << g[i][j] << ' ';
        }
        cout << endl;
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