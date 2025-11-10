#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;
using TUP = array<int, 3>;

int n;
vector<TUP> a;

void solve() {
    cin >> n;
    long long sum = 0;
    int ws = 0;
    for(int i = 0; i < n; i ++) {
        int w, h, b;
        cin >> w >> h >> b;
        a.push_back({w, h, b});
        ws += w;
    }
    sort(a.begin(), a.end());

    for(int i = 0; i <= ws; i ++) {
        int cnt = 0;
        for(int j = 0; j < n; j ++) {
            if(cnt >= j) {
                
                break;
            }
        }       
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
