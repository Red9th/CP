#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n;
int vis[10], path[10];

void dfs(int x) {
    if(x == n) {
        for(int i = 0; i < n; i ++) {
            cout << path[i] << ' ';
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i ++) {
        if(!vis[i]) {
            vis[i] = 1;
            path[x] = i;
            dfs(x + 1);
            path[x] = 0;
            vis[i] = 0;
        }
    }
}

void solve() {
    cin >> n;
    dfs(0);
}

int main() {
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}