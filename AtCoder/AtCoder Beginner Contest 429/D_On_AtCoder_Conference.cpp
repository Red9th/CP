#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

LL n, m, c;
unordered_map<LL, int> h;
vector<pair<LL, int>> a;
vector<int> sum;

void solve() {
    cin >> n >> m >> c;
    for(int i = 0; i < n; i ++) {
        LL x;
        cin >> x;
        h[x] ++;
    }
    for(auto [k, v] : h) {
        a.push_back({k, v});
    }
    sort(a.begin(), a.end());
    int len = a.size();

    sum = vector<int>(len + 1, 0);
    for(int i = 1; i <= len; i ++) {
        sum[i] = sum[i - 1] + a[i - 1].second;
    }

    // for(int i = 1; i <= len; i ++) {
    //     printf("k: %d, cnt: %d, sum: %d\n", a[i - 1].first, a[i - 1].second, sum[i]);
    // }

    if(len == 1) {
        cout << m * a[0].second;
        return;
    }

    LL ans = 0;
    for(int i = 1; i <= len; i ++) {
        // ? - sum[i - 1] >= c -> ? >= c + sum[i - 1]
        int cnt = 0;
        int j = lower_bound(sum.begin(), sum.end(), c + sum[i - 1]) - sum.begin();
        if(j < sum.size()) {
            cnt = sum[j] - sum[i - 1];
        } else {
            cnt = sum[len] - sum[i - 1];
            int k = lower_bound(sum.begin(), sum.end(), c - cnt) - sum.begin();
            cnt += sum[k];
        }
        // printf("cnt: %d\n", cnt);
        LL l = a[(i - 2 + len) % len].first;
        LL r = a[i - 1].first;
        // printf("l: %d, r: %d, len: %d\n", l, r, (r - l + m) % m);
        ans += ((r - l + m) % m) * cnt;
    }
    cout << ans << endl;
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