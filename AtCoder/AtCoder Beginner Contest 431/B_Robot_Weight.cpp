#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;
using TUP = array<int, 3>;

int x, n, w[110];
int q;
unordered_map<int, int> h;

void solve() {
    cin >> x >> n;
    for(int i = 1; i <= n; i ++) cin >> w[i];
    cin >> q;
    int sum = x;
    while(q --) {
        int p;
        cin >> p;
        if(h[p] == 0) {
            h[p] ++;
            sum += w[p];
        } else {
            h[p] = 0;
            sum -= w[p];
        }
        cout << sum << endl;
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