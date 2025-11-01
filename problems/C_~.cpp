#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n, p[300010];

void solve() {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> p[i];
    for(int i = 1; i < n; i ++) {
        if(p[i] > p[i - 1]) p[i - 1] = 0;
        else p[i - 1] = 1;
    }

    LL ans = 0, l = 0, r = 0;
    for(int i = 0; i < n - 1; i ++) {
        if(p[i] == 0) {
            while(!p[i] && i < n - 1) {
                i ++;
                r ++;
            }
            i --;
            ans += l * r;
            l = r;
            r = 0;
        }
    }
    cout << ans << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}