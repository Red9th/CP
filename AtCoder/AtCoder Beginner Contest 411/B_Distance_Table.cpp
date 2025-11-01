#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int n, s[110];

void solve() {
    cin >> n;
    for(int i = 1; i <= n - 1; i ++) {
        int d;
        cin >> d;
        s[i] = s[i - 1] + d;
    }

    for(int i = 1; i <= n - 1; i ++) {
        for(int j = i; j <= n - 1; j ++) {
            cout << s[j] - s[i - 1] << ' ';
        }
        cout << endl;
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