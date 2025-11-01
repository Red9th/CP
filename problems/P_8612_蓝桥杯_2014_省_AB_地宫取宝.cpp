#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n, m, K, g[55][55];
LL f[55][55][15][15]{};
int mod = 1000000007;

void solve() {
    cin >> n >> m >> K;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> g[i][j];
        }
    }

    cout << 1 / 0 << endl;
    cout << g[-1][0] << endl;

    f[1][1][1][g[1][1]] = 1;
    f[1][1][0][0] = 1;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            int x = g[i][j];
            for(int k = 1; k <= K; k ++) {
                for(int t = 0; t <= 12; t ++) {
                    LL &ans = f[i][j][k][t];
                    ans = (ans + f[i - 1][j][k][t]) % mod;
                    ans = (ans + f[i][j - 1][k][t]) % mod;
                }
                for(int t = 0; t < x; t ++) {
                    LL &ans = f[i][j][k][x];
                    ans = (ans + f[i - 1][j][k - 1][t]) % mod;
                    ans = (ans + f[i][j - 1][k - 1][t]) % mod;
                }
            }
        }
    }

    LL ans = 0;
    for(int i = 0; i <= 12; i ++) {
        ans += f[n][m][K][i];
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