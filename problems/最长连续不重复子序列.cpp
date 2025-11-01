#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n, a[100010];
set<int> s;

void solve() {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];

    int i = 0, j = 0;
    int ans = 0;
    while(i < n && j < n) {
        while(s.count(a[j])) {
            s.erase(a[i ++]);
        }
        s.insert(a[j ++]);
        ans = max(ans, j - i);
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