#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, a[110], sum = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 1; i <= n; i ++) {
        if(sum - a[i] == m) {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
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