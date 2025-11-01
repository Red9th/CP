#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n, m, h[100010], cnt;

void up(int x) {
    int fa = x / 2;
    if(fa == 0) return;
    if(h[fa] > h[x]) {
        swap(h[fa], h[x]);
        up(fa);
    }
}

void down(int x) {
    int fa = x, l = 2 * x, r = 2 * x + 1;
    if(l <= cnt && h[l] < h[fa]) fa = l;
    if(r <= cnt && h[r] < h[fa]) fa = r;
    if(fa != x) {
        swap(h[fa], h[x]);
        down(fa);
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> h[i];
        cnt ++;
        up(i);
    }

    while(m --) {
        cout << h[1] << ' ';
        h[1] = h[cnt];
        cnt --;
        down(1);
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