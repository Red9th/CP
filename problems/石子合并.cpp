#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n;
int a[310];
int f[310][310];
int sum[310];

int dfs(int i, int j) {
    if(i > j) return 0;
    if(i == j) return f[i][j] = 0;
    if(f[i][j]) return f[i][j];
    if(i + 1 == j) return f[i][j] = a[i] + a[j];
    int res = INT_MAX;
    for(int k = i; k < j; k ++) {
        res = min(res, dfs(i, k) + dfs(k + 1, j) + sum[j + 1] - sum[i]);
    }
    return f[i][j] = res;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];
    
    for(int i = 1; i <= n; i ++) {
        sum[i] = sum[i - 1] + a[i - 1];
    }
    
    cout << dfs(0, n - 1);
    // f[i][j]: 表示合并 nums[i:j] 的最小代价
    // f[i][k] + f[k + 1][j] + sum[i -> k] + sum[k + 1 -> j]
}

int main() {
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}