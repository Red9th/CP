#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        if(i <= m) {
            cout << "OK\n";
        } else {
            cout << "Too Many Requests\n";
        }
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