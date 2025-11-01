#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n, m, a[100010], b[100010];

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < m; i ++) cin >> b[i];

    int i = 0, j = 0;
    while(i < n && j < m) {
        if(a[i] == b[j]) {
            i ++, j ++;
        } else {
            j ++;
        }
    }
    if(i == n) {
        cout << "Yes";
    } else {
        cout << "No";
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