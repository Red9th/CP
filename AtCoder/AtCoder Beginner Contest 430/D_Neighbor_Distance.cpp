#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;
using TUP = array<int, 3>;

int n;
unordered_map<int, int> dis;
set<int> a;

void update(int x, int val) {
    if(dis[x] == 0) {
        dis[x] = val;
    } else {
        dis[x] = min(dis[x], val);
    }
}

void solve() {
    cin >> n;
    a.insert(0);
    LL sum = 0;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        auto r = a.upper_bound(x);
        auto l = prev(r);

        LL nsum = sum;

        nsum -= dis[*l];
        if(r != a.end()) nsum -= dis[*r];

        // cout << dis[a[l]] << endl;
        update(*l, x - *l);
        // cout << dis[a[l]] << endl;
        if(r == a.end()) {
            update(x, x - *l);
        } else {
            update(x, min(x - *l, *r - x));
            update(*r, *r - x);
        }

        nsum += dis[*l];
        if(r != a.end()) nsum += dis[*r];
        nsum += dis[x];

        if(i == 0) {
            sum += dis[*l] + dis[x];
        } else {
            sum = nsum;
        }

        // for(auto [k, v] : dis) {
        //     cout << k << ' ' << v << endl;
        // }
        // cout << endl;

        a.insert(x);

        cout << sum << endl;
        // cout << endl;
    }
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