#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

void solve() {
    LL n;
    cin >> n;
    LL ans = (LL)sqrtl(n) / 2 + (LL)sqrtl(n / 2);
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