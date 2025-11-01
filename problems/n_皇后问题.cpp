#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n, vis[10], path[10];
unordered_map<int, int> l, r;

void dfs(int x) {
    if(x == n) {
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                if(j == path[i]) cout << "Q";
                else cout << ".";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for(int i = 0; i < n; i ++) {
        if(!vis[i] && !l[x + i] && !r[x - i]) {
            path[x] = i;
            vis[i] = 1;
            l[x + i] = 1;
            r[x - i] = 1;
            dfs(x + 1);
            path[x] = 0;
            vis[i] = 0;
            l[x + i] = 0;
            r[x - i] = 0;
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