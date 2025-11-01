#define LL long long
#define PII pair<int, int>

#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <tuple>
#include <iterator>
#include <string>
#include <string.h>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <sstream>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int n, k, a[110];

void solve() {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];
    cin >> k;

    int ans = 0;
    for(int i = 0; i < n; i ++) {
        if(k <= a[i]) ans ++;
    }
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