#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;
using TUP = array<int, 3>;

string s;
int n;
vector<PII> g[51000];
int dis[1000][51000];

void solve() {
    cin >> s;
    n = s.size();
    for(int i = 0; i < n - 1; i ++) {
        int x = s[i] - 'a', y = s[i + 1] - 'a';
        int vd = n + x * 26 + y;
        g[i].push_back({vd, 1});
        g[vd].push_back({i, 0});

        if(i < n - 2) {
            g[i].push_back({i + 1, 1});
            g[i + 1].push_back({i, 1});
        }
    }

    for(int i = 0; i < 26; i ++) {
        for(int j = 0; j < 26; j ++) {
            int vd = n + i * 26 + j;
            deque<int> q;
            q.push_back(vd);
            memset(dis[vd - n], 0x3f, sizeof(dis[vd - n]));
            dis[vd - n][vd] = 0;
            while(q.size()) {
                auto u = q.front();
                q.pop_front();
                for(auto [v, w] : g[u]) {
                    if(dis[vd - n][v] > dis[vd - n][u] + w) {
                        dis[vd - n][v] = dis[vd - n][u] + w;
                        if(w == 0) q.push_front(v);
                        else q.push_back(v);
                    }
                }
            }
        }
    }

    int m;
    cin >> m;
    while(m --) {
        int l, r;
        cin >> l >> r;
        l --, r --;
        int ans = abs(r - l);
        for(int i = 0; i < 26; i ++) {
            for(int j = 0; j < 26; j ++) {
                int vd = i * 26 + j;
                ans = min(ans, dis[vd][l] + dis[vd][r] + 1);
            }
        }
        cout << ans << endl;
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