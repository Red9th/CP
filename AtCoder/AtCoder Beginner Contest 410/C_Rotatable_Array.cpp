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

LL n, q, a[1000010];

void solve() {
    cin >> n >> q;
    for(int i = 0; i < n; i ++) a[i] = i + 1;

    LL bios = 0;
    while(q --) {
        LL t, p, x, k;
        cin >> t;
        if(t == 1) {
            cin >> p >> x;
            a[(p - 1 - bios + n) % n] = x;
        } else if(t == 2) {
            cin >> p;
            cout << a[(p - 1 - bios + n) % n] << '\n';
        } else {
            cin >> k;
            k %= n;
            bios = (bios + n - k) % n;
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