#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int s, a, b, x;
    cin >> s >> a >> b >> x;
    int len = (x / (a + b) * s * a);
    if(x % (a + b) >= a) len += s * a;
    else len += s * (x % (a + b));
    cout << len;
}

int main() {
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}