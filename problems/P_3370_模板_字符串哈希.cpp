#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PLL = pair<LL, LL>;

const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;

PLL operator+ (PLL a, PLL b) {
    int c1 = a.first + b.first, c2 = a.second + b.second;
    if(c1 >= mod1) c1 -= mod1;
    if(c2 >= mod2) c2 -= mod2;
    return {c1, c2};
}

PLL operator- (PLL a, PLL b) {
    int c1 = a.first - b.first, c2 = a.second - b.second;
    if(c1 < 0) c1 += mod1;
    if(c2 < 0) c2 += mod2;
    return {c1, c2};
}

PLL operator* (PLL a, PLL b) {
    int c1 = a.first * b.first % mod1;
    int c2 = a.second * b.second % mod2;
    return {c1, c2};
}

PLL pw[1510];
PLL base = {13331, 23333};

PLL cal_hash(string& s) {
    PLL res = {0, 0};
    for(int i = 0; i < s.size(); i ++) {
        PLL p = {s[i], s[i]};
        res = res * base + p;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    pw[0] = {1, 1};
    for(int i = 1; i <= 1500; i ++) {
        pw[i] = pw[i - 1] * base;
    }

    set<PLL> st;
    for(int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        st.insert(cal_hash(s));
    }
    cout << st.size();
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