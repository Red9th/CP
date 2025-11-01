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

int n, m, s[1000010];

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r;
        s[l] ++;
        s[r + 1] --;
    }

    int mn = INT_MAX;
    for(int i = 1; i <= n; i ++) {
        s[i] += s[i - 1];
        mn = min(mn, s[i]);
    }
    cout << mn;
    return 0;
}