#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

string p;
int l;

void solve() {
    cin >> p >> l;
    int sz = p.size();
    if(p.size() >= l) cout << "Yes";
    else cout << "No";
}

int main() {
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}