#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n, m, p[100010];
long long s[100010];

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        cin >> p[i];
        if(i > 0) {
            int l = min(p[i - 1], p[i]), r = max(p[i - 1], p[i]) - 1;
            s[l] ++;
            s[r + 1] --;
        }
    }

    for(int i = 1; i < n; i ++) {
        s[i] += s[i - 1];
    }

    long long ans = 0;
    for(int i = 1; i < n; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        long long cnt = s[i];
        ans += min(1LL * x * cnt, z + y * cnt);
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