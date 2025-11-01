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
using namespace std;

int h, w, n;
set<int> row[200010], col[200010];

int main() {
    cin >> h >> w >> n;
    for(int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        row[x].insert(y);
        col[y].insert(x);
    }

    int q;
    cin >> q;
    while(q --) {
        int t, x;
        cin >> t >> x;
        if(t == 1) {
            cout << row[x].size() << endl;
            for(auto i : row[x]) {
                if(col[i].count(x)) {
                    col[i].erase(x);
                }
            }
            row[x].clear();
        } else {
            cout << col[x].size() << endl;
            for(auto i : col[x]) {
                if(row[i].count(x)) {
                    row[i].erase(x);
                }
            }
            col[x].clear();
        }
    }
    return 0;
}