#define LL long long
#define PII pair<int, int>

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
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int n, l, s[300010];
unordered_map<int, int> h;

int main() {
    cin >> n >> l;
    h[0] ++;
    for(int i = 2; i <= n; i ++) {
        int d;
        cin >> d;
        s[i] = (s[i - 1] + d) % l;
        h[s[i]] ++;
    }

    if(l % 3 != 0) {
        cout << 0;
        return 0;
    }

    LL ans = 0;
    for(int i = 0; i < l; i ++) {
        int a = h[i - l / 3];
        int b = h[i + l / 3];
        ans += 1LL * h[i] * a * b;
    }
    cout << ans;
    return 0;
}