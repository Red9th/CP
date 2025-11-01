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

#define ll long long

ll g[25][25], vis[25][25];
ll n, m;
ll mx = 0;

void dfs(int x, int y, ll ans) {
    if(x >= n) {
        mx = max(mx, ans);
        return;
    }
    if(y >= m) {
        x ++;
        y = 0;
    }

    ll cur = ans;
    if(!vis[x][y]) cur ^= g[x][y];
    dfs(x, y + 1, cur);

    if(!vis[x][y] && !vis[x][y + 1] && y + 1 < m) {
        vis[x][y] = vis[x][y + 1] = 1;
        dfs(x, y + 1, ans);
        vis[x][y] = vis[x][y + 1] = 0;
    }

    if(!vis[x][y] && !vis[x + 1][y] && x + 1 < n) {
        vis[x][y] = vis[x + 1][y] = 1;
        dfs(x, y + 1, ans);
        vis[x][y] = vis[x + 1][y] = 0;
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }

    dfs(0, 0, 0);
    cout << mx;
    return 0;
}