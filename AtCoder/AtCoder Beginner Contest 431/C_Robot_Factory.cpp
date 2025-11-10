#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;
using TUP = array<int, 3>;

int n, m, k;
vector<int> h, b;

void solve() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        h.push_back(x);
    }
    for(int i = 0; i < m; i ++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    sort(h.begin(), h.end());
    sort(b.begin(), b.end());

    int cnt = 0, pre = 0;
    for(int i = 0; i < n; i ++) {
        int x = h[i];
        int j = lower_bound(b.begin() + pre, b.end(), x) - b.begin();
        if(j == m) {
            break;
        } else {
            pre = j + 1;
            cnt ++;
        }
    }

    if(cnt >= k) cout << "Yes";
    else cout << "No";
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