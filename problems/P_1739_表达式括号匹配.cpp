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
using namespace std;

int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};

#define x first
#define y second
#define LL long long
#define PII pair<int, int>

string s;

int main() {
    cin >> s;
    stack<char> st;
    bool ok = true;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == '(') {
            st.push(s[i]);
        } else if(s[i] == ')') {
            if(st.size() > 0) {
                st.pop();
            } else {
                ok = false;
            }
        }
    }
    if(st.size() > 0 || !ok) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    return 0;
}