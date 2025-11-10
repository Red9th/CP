#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<LL, LL>;
using TUP = array<int, 3>;

const LL mod1 = 1e9 + 7;
const LL mod2 = 1e9 + 9;
const int N = 2e6 + 10;

PII operator + (PII a, PII b) {
    LL c1 = a.first + b.first, c2 = a.second + b.second;
    if(c1 >= mod1) c1 -= mod1;
    if(c2 >= mod2) c2 -= mod2;
    return {c1, c2};
}

PII operator - (PII a, PII b) {
    LL c1 = a.first - b.first, c2 = a.second - b.second;
    if(c1 < 0) c1 += mod1;
    if(c2 < 0) c2 += mod2;
    return {c1, c2};
}

PII operator * (PII a, PII b) {
    LL c1 = a.first * b.first % mod1, c2 = a.second * b.second % mod2;
    return {c1, c2};
}

PII pw[N], sp[N], sf[N];

PII get(PII *h, LL l, LL r, int g = 0) {
    if(g == 0) return (h[r] - h[l - 1] * pw[r - l + 1]);
    else return (h[r] - h[l + 1] * pw[l - r + 1]);
}

void solve() {
    string a, b;
    cin >> a >> b;
    int len = a.size();
    a = " " + a + a;
    b = " " + b;
    int n = a.size() - 1;
    int m = b.size() - 1;

    PII base = {13331, 23333};
    pw[0] = {1, 1};

    for(int i = 1; i <= n; i ++) {
        pw[i] = pw[i - 1] * base;
    }
    for(int i = 1; i <= n; i ++) {
        PII p = {a[i], a[i]};
        sp[i] = sp[i - 1] * base + p;
    }
    for(int i = 1; i <= m; i ++) {
        PII p = {b[i], b[i]};
        sf[i] = sf[i - 1] * base + p;
    }

    for(int i = 1; i <= len; i ++) {
        if(get(sp, i, i + len - 1) == sf[m]) {
            cout << i - 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}