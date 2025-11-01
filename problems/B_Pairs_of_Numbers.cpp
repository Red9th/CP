#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;
using TUP = array<int, 3>;

int f(int a, int b) {
    if(a == 0) return INT_MAX;
    if(a == 1) return b - 1;
    if(a > b) return f(b, a);
    int ans = f(a, b % a);
    if(ans == INT_MAX) return INT_MAX;
    return b / a + ans;
}

void solve() {
    int n;
    cin >> n;
    int ans = INT_MAX;
    for(int i = 1; i <= n; i ++) {
        ans = min(ans, f(i, n));
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