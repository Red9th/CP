#define LL long long
#define PII pair<int, int>

#include <bits/stdc++.h>
using namespace std;

int q;
stack<int> st;
stack<char> good;

void solve() {
    cin >> q;
    while(q --) {
        int op;
        char c;
        cin >> op;
        if(op == 1) {
            cin >> c;
            bool ok = false;
            if(c == '(') {
                good.push(c);
            } else {
                if(!good.empty() && good.top() == '(') {
                    good.pop();
                    ok = true;
                }
                else good.push(c);
            }
            st.push(ok);
        } else {
            if(st.top()) {
                good.push('(');
            } else {
                good.pop();
            }
            st.pop();
        }
        if(good.size() == 0) cout << "Yes\n";
        else cout << "No\n";
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