#define ll long long
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
using namespace std;

int n, t;
int pre[200010] = {0};

int main() {
    cin >> t;
    while(t --) {
        string s;
        cin >> n >> s;
        for(int i = 1; i <= n; i ++) {
            pre[i] = pre[i - 1] + (s[i - 1] - '0');
        }

        int mn = INT_MAX, ans = min(pre[n], n - pre[n]);
        for(int i = 1; i <= n; i ++) {
            mn = min(mn, 2 * pre[i - 1] - i);
            int res = pre[n] - 2 * pre[i] + i + 1 + mn;
            ans = min(ans, res);
        }
        cout << ans << endl;
    }
    return 0;
}