#define ll long long
#define PII pair<int, int>

#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <cmath>
#include <climits>
#include <unordered_map>
using namespace std;

ll n, m, c[15];
ll ans = 1e18;
unordered_map<ll, vector<ll>> h;
ll rec[15] = {0};

void dfs(ll x, ll mon) {
    if(mon > ans) return;
    if(x == n) {
        int cnt[110] = {0};
        for(int i = 0; i < n; i ++) {
            for(auto j : h[i]) {
                cnt[j] += rec[i];
            }
        }
        for(int i = 0; i < m; i ++) {
            if(cnt[i] < 2) {
                return;
            }
        }
        ans = min(ans, mon);
        return;
    }
    rec[x] = 0;
    dfs(x + 1, mon + c[x] * rec[x]);
    rec[x] = 1;
    dfs(x + 1, mon + c[x] * rec[x]);
    rec[x] = 2;
    dfs(x + 1, mon + c[x] * rec[x]);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i ++) cin >> c[i];
    for(int i = 0; i < m; i ++) {
        int k, a;
        cin >> k;
        for(int j = 0; j < k; j ++) {
            cin >> a;
            h[a - 1].push_back(i);
        }
    }
    dfs(0, 0);
    cout << ans;
    return 0;
}