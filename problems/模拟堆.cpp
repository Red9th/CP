#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int h[100010], n = 0;

// 向下调整第 x 个元素
void down(int x) {
    int fa = x, l = 2 * x, r = 2 * x + 1;
    if(l <= n && h[l] < h[fa]) fa = l;
    if(r <= n && h[r] < h[fa]) fa = r;
    if(fa != x) {
        swap(h[fa], h[x]);
        down(fa);
    }
}

// 向上调整第 x 个元素
void up(int x) {
    int fa = x / 2;
    if(fa == 0) return;
    if(h[fa] > h[x]) {
        swap(h[fa], h[x]);
        up(fa);
    }
}

// 插入值为 x 的数
void insert(int x) {
    h[++ n] = x;
    up(n);
}

// 输出堆顶
int top() {
    return h[1];
}

// 删除堆顶
void pop() {
    h[1] = h[n];
    n --;
    down(1);
}

void solve() {
    int m;
    cin >> m;
    while(m --) {
        string op;
        int k, x;
        cin >> op;
        if(op == "I") {
            cin >> x;
            insert(x);
            // 用 vis 记录数是第几次插入的，如果被删除则归零?
        } else if(op == "PM") {
            cout << top() << endl;
        } else if(op == "DM") {
            pop();
        } else if(op == "D") {
            cin >> k;
        } else if(op == "C") {
            cin >> k >> x;

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