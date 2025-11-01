#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

unordered_map<LL, LL> h;

void solve() {
    LL n, m;
    cin >> n >> m;

    LL ans = m * (m - 1) / 2;
    for(int i = 0; i < m; i ++) {
        LL a, b;
        cin >> a >> b;
        ans -= h[(a + b) % n];
        h[(a + b) % n] ++;
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