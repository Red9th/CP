#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n, f[150010];
vector<PII> a;

int find(int i) {
    int l = 0, r = i - 1;
    while(l < r) {
        int mid = (l + r + 1) / 2;
        if(a[mid].second < a[i].first) l = mid;
        else r = mid - 1;
    }
    return l;
}

void solve() {
    cin >> n;
    a.push_back({-1, -1});
    for(int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end(), [](PII& a, PII& b) {
        return a.second < b.second;
    });

    for(int i = 1; i <= n; i ++) {
        f[i] = f[i - 1];
        int l = find(i);
        if(a[l].second < a[i].first) {
            f[i] = max(f[i], f[l] + a[i].second - a[i].first + 1);
        }
    }
    cout << f[n];
}

int main() {
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}