#define ll long long
#define PII pair<int, int>

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
using namespace std;

int m, n;
char g[1010][1010];
queue<pair<int, int>> q;
int dis[1010][1010];

int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
char dir[4] = {'>', '^', '<', 'v'};

int main() {
    cin >> m >> n;
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> g[i][j];
            dis[i][j] = -1;
            if(g[i][j] == 'E') {
                dis[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while(q.size()) {
        auto t = q.front();
        q.pop();
        int tx = t.first, ty = t.second;
        for(int i = 0; i < 4; i ++) {
            int nx = tx + dx[i], ny = ty + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(dis[nx][ny] != -1) continue;
            if(g[nx][ny] != '.')continue;
            dis[nx][ny] = dis[tx][ty] + 1;
            g[nx][ny] = dir[i];
            q.push({nx, ny});
        }
    }
    
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            cout << g[i][j];
        }
        cout << '\n';
    }

    return 0;
}