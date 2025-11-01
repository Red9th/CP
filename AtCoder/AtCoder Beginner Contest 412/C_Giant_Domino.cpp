#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s[200010];
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> s[i];

    if (s[0] * 2 >= s[n - 1]) {
        cout << 2 << endl;
        return;
    }

    vector<int> a;
    for(int i = 0; i < n; i ++) {
        if(s[i] < s[0] || s[i] > s[n - 1]) continue;
        a.push_back(s[i]);
    }
    n = a.size();
    sort(a.begin() + 1, a.begin() + n - 1);

    int pre = a[0], ans = 1;
    for(int i = 1; i < n; i ++) {
        if(a[i] > 2 * pre) {
            cout << -1 << endl;
            return;
        }
        int p = upper_bound(a.begin(), a.end(), pre * 2) - a.begin();
        if(p > 0 && p <= n) {
            pre = a[p - 1];
            i = p - 1;
            ans ++;
        } else {
            cout << -1 << endl;
            return;
        }
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