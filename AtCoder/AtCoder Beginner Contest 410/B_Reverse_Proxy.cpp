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

int n, q;
vector<PII> s;

void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        s.push_back({0, i});
    }
    for(int i = 0; i < q; i ++) {
        int x;
        cin >> x;
        if(x == 0) {
            sort(s.begin(), s.end(), [](PII a, PII b) -> bool {
                if(a.first == b.first) return a.second < b.second;
                else return a.first < b.first;
            });
            s[0].first ++;
            cout << s[0].second << ' ';
        } else {
            for(int i = 0; i < s.size(); i ++) {
                if(x == s[i].second) {
                    s[i].first ++;
                    cout << s[i].second << ' ';
                    break;
                }
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