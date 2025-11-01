#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string goal = "12345678x";

void solve() {
    string s;
    for(int i = 0; i < 9; i ++) {
        char x;
        cin >> x;
        s += x;
    }

    queue<string> q;
    unordered_map<string, int> dis;
    q.push(s);
    dis[s] = 0;
    while(q.size()) {
        auto u = q.front();
        q.pop();
        if(u == goal) {
            cout << dis[u];
            return;
        }
        int x, y;
        for(int i = 0; i < 9; i ++) {
            if(u[i] == 'x') {
                x = i / 3, y = i % 3;
            }
        }

        for(int i = 0; i < 4; i ++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            string v = u;
            swap(v[nx * 3 + ny], v[x * 3 + y]);
            if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
            if(dis.find(v) == dis.end()) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    cout << -1;
}

int main() {
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}