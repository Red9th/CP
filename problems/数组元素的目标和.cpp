#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n, m, target, a[100010], b[100010];

void solve() {
    cin >> n >> m >> target;
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < m; i ++) cin >> b[i];

    int i = 0, j = m - 1;
    while(i < n && j >= 0) {
        int s = a[i] + b[j];
        if(s < target) i ++;
        else if(s > target) j --;
        else {
            printf("%d %d\n", i, j);
            break;
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