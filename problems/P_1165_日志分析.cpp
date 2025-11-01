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

const int N = 200010;
int n;
stack<int> s;
int f[N];

int main() {
    cin >> n;
    while(n --) {
        int op, wt;
        cin >> op;
        if(op == 0) {
            cin >> wt;
            s.push(wt);
            f[s.size()] = max(f[s.size() - 1], wt);
        } else if(op == 1) {
            if(s.size() > 0) {
                f[s.size()] = 0;
                s.pop();
            }
        } else {
            cout << f[s.size()] << '\n';
        }
    }
    return 0;
}