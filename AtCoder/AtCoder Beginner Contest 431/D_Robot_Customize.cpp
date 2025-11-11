#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;
using TUP = array<int, 3>;

int n;
vector<TUP> a;

void solve() {
    cin >> n;
    int ws = 0;
    for(int i = 0; i < n; i ++) {
        int w, h, b;
        cin >> w >> h >> b;
        a.push_back({w, h, b});
        ws += w;
    }

    vector<vector<LL>> f(n + 1, vector<LL>(ws + 1, -1));
    f[0][0] = a[0][2];
    f[0][a[0][0]] = a[0][1];
    for(int i = 1; i < n; i ++) {
        for(int j = 0; j <= ws; j ++) {
            auto [w, h, b] = a[i];
            f[i][j] = max(f[i][j], f[i - 1][j] + b);
            if(j >= w && f[i - 1][j - w] != -1) {
                f[i][j] = max(f[i][j], f[i - 1][j - w] + h);
            }
        }
    }

    LL ans = 0;
    for(int i = 0; i <= ws; i ++) {
        int j = ws - i;
        if(i <= j && f[n - 1][i] != -1) {
            ans = max(ans, f[n - 1][i]);
        }
    }
    cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
