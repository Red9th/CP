#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

string s;
string goal = "atcoder";

void solve() {
    cin >> s;

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
        for(int i = 1; i < 7; i ++) {
            string v = u;
            swap(v[i - 1], v[i]);
            if(dis.find(v) == dis.end()) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
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