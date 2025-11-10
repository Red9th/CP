#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;
using TUP = array<int, 3>;

int n, a, b;
string s;
int sum[2][300010];

void solve() {
    cin >> n >> a >> b >> s;
    LL ans = 0;
    for(int i = 1; i <= n; i ++) {
        int x = s[i - 1] - 'a';
        sum[0][i] = sum[0][i - 1];
        sum[1][i] = sum[1][i - 1];
        sum[x][i] ++;

        int r = upper_bound(sum[0], sum[0] + i, sum[0][i] - a) - sum[0] - 1;
        int l = upper_bound(sum[1], sum[1] + i, sum[1][i] - b) - sum[1];
        if(l <= r) {
            ans += r - l + 1;
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