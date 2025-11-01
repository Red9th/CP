#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int m, n;
char g[210][210];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve() {
    cin >> m >> n;
    int sx, sy, ex, ey;
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> g[i][j];
            if(g[i][j] == 'S') sx = i, sy = j;
            if(g[i][j] == 'E') ex = i, ey = j;
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dis(m, vector<int>(n, -1));
    q.push({sx, sy});
    dis[sx][sy] = 0;
    while(q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i < 4; i ++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(g[nx][ny] == '#' || dis[nx][ny] != -1) continue;
            dis[nx][ny] = dis[x][y] + 1;
            q.push({nx, ny});
        }
    }
    if(dis[ex][ey] == -1) cout << "oop!\n";
    else cout << dis[ex][ey] << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}