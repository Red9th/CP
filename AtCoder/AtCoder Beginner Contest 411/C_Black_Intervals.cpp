#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n, q, a[500010];

void solve() {
    cin >> n >> q;

    int cnt = 0;
    while(q --) {
        int t;
        cin >> t;
        a[t] = (a[t] + 1) % 2;
        int l = a[t - 1], r = a[t + 1], m = a[t];
        if(m == 0) {
            if(l == 0 && r == 0) cnt --;
            else if(l == 1 && r == 1) cnt ++;
        }
        if(m == 1) {
            if(l == 0 && r == 0) cnt ++;
            else if(l == 1 && r == 1) cnt --;
        }
        cout << cnt << endl;
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