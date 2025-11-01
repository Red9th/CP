#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};

#define x first
#define y second
#define LL long long
#define PII pair<int, int>

int n, a[11][11];
bool vis[11][11];
vector<int> s, ans;
int mx;

void dfs(int u, int v, int cnt) {
    if(cnt == n) {
        vector<int> bk = s;
        sort(bk.begin(), bk.end(), greater<int>());
        if(bk[0] > mx) {
            mx = bk[0];
            ans = bk;
        }
        return;
    }
    for(int i = 0; i < 8; i ++) {
        int nx = (u + dx[i] + n) % n, ny = (v + dy[i] + n) % n;
        if(!vis[nx][ny]) {
            vis[nx][ny] = true;
            s.push_back(a[nx][ny]);
            dfs(nx, ny, cnt + 1);
            vis[nx][ny] = false;
            s.pop_back();
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            vis[i][j] = true;
            s.push_back(a[i][j]);
            dfs(i, j, 1);
            vis[i][j] = false;
            s.pop_back();
        }
    }
    for(auto i : ans) cout << i;
    return 0;
}