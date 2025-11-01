#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n, h[100010];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> h[i];

    int pos = 0, neg = 0;
    for(int i = 1; i <= n; i ++) {
        int x = h[i] - h[i - 1];
        if(x > 0) pos += x;
        else neg -= x;
    }
    cout << min(pos, neg) + abs(pos - neg);
}

int main() {
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}