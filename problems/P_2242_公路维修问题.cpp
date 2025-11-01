#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};

#define x first
#define y second
#define LL long long
#define PII pair<int, int>

const int N = 15010;
int n, m;
int a[N], vis[N];
vector<PII> b;

bool cmp(PII a, PII b) {
    return a.first > b.first;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        b.push_back({a[i] - a[i - 1], i});
    }
    sort(b.begin(), b.end(), cmp);
    for(int i = 0; i < m - 1; i ++) {
        vis[b[i].second] = 1;
    }
    int ans = 0, l = 1, r = 1;
    for(int i = 1; i <= n; i ++) {
        if(vis[i]) {
            r = i - 1;
            ans += a[r] - a[l] + 1;
            l = i;
        }
    }
    ans += a[n] - a[l] + 1;
    cout << ans;
    return 0;
}