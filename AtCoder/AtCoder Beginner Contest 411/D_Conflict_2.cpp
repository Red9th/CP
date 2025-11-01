#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

struct node {
    string s;
    int pre;
    int nxt;
    node() : s(""), pre(0), nxt(0) {}
    node(string s_, int pre_, int nxt_) : s(s_), pre(pre_), nxt(nxt_) {};
} str[400010];

int pc[400010];
int cnt = 1;

void solve() {
    int n, q;
    cin >> n >> q;

    for(int i = 0; i <= n; i ++) {
        str[cnt] = node("", 0, 0);
        pc[i] = cnt ++;
    }

    while(q --) {
        int t, p;
        string s;
        cin >> t >> p;
        if(t == 1) {
            pc[p] = pc[0];
        } else if(t == 2) {
            cin >> s;
            reverse(s.begin(), s.end());
            str[cnt] = node(s, pc[p], 0);
            str[pc[p]].nxt = cnt;
            pc[p] = cnt ++;
        } else {
            pc[0] = pc[p];
        }
    }

    int tail = pc[0];
    string ans;
    while(str[tail].pre != 0) {
        ans += str[tail].s;
        tail = str[tail].pre;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}

int main() {
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}