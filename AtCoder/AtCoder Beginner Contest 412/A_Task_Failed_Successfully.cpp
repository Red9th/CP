#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        if(b > a) ans ++;
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