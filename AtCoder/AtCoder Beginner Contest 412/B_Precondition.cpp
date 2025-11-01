#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    set<char> st;
    cin >> s >> t;
    for(auto c : t) {
        st.insert(c);
    }
    for(int i = 1; i < s.size(); i ++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            if(st.count(s[i - 1]) == 0) {
                cout << "No";
                return;
            }
        }
    }
    cout << "Yes";
}

int main() {
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}