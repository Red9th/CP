#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int m, s, t;
int f[300010];

void solve() {
    cin >> m >> s >> t;
    for(int i = 1; i <= t; i ++) {
        if(f[i - 1] + 17 >= s) {
            cout << "Yes" << "\n" << i;
            return;
        }
        if(m >= 10) {
            f[i] = f[i - 1] + 60;
            m -= 10;
        } else if(m + 4 >= 10 && i + 1 <= t) {
            f[i] = f[i - 1];
            m += 4;
        } else {
            f[i] = f[i - 1] + 17;
        }
        if(f[t] >= s) {
            cout << "Yes" << '\n' << i;
            return;
        }
    }
    cout << "No" << '\n' << f[t];
}

int main() {
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}