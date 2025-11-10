#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;
using TUP = array<int, 3>;

string s[11];
int n, m;
set<string> st;

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i ++) {
        cin >> s[i];
    }

    for(int i = 0; i <= n - m; i ++) {
        for(int j = 0; j <= n - m; j ++) {
            string sub;
            for(int k = 0; k < m; k ++) {
                sub += s[i + k].substr(j, m);
            }
            st.insert(sub);
        }
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