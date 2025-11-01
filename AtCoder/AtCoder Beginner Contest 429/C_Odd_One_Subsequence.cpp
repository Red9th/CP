#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<LL, LL> h;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        h[a[i]] ++;
    }

    LL ans = 0;
    for(auto [k, cnt] : h) {
        if(cnt >= 2) {
            LL res = cnt * (cnt - 1);
            res /= 2;
            res *= (n - cnt);
            ans += res;
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