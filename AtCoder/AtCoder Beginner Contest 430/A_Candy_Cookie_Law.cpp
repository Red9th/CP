#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;
using TUP = array<int, 3>;

int a, b, c, d;

void solve() {
    cin >> a >> b >> c >> d;
    if(c < a) cout << "No";
    else {
        if(d < b) cout << "Yes";
        else cout << "No";
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