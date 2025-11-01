#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

LL sum(LL x) {
    LL l = 0, r = 2e9;
    while(l < r) {
        LL m = (l + r + 1) / 2;
        if(m * m <= x) l = m;
        else r = m - 1;
    }
    return l;
}

void solve() {
    LL c, d;
    cin >> c >> d;

    LL ans = 0;
    for(LL t = 1; t <= c + d; t *= 10) {
        LL l = max(1LL, t - c);
        LL r = min(d, t * 10 - 1 - c);
        if(l > r) continue;
        ans += sum(c * t * 10 + c + r) - sum(c * t * 10 + c + l - 1);
    }
    cout << ans << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}