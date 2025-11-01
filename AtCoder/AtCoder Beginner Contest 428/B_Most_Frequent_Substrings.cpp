#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;
map<string, int> h;

void solve() {
    cin >> n >> k >> s;
    int ans = 0;
    for(int i = 0; i <= n - k; i ++) {
        string ss = s.substr(i, k);
        h[ss] ++;
        ans = max(ans, h[ss]);
    }
    cout << ans << endl;
    for(auto [str, cnt] : h) {
        if(cnt == ans) {
            cout << str << ' ';
        }
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}