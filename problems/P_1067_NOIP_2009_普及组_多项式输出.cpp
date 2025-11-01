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

int main() {
    int n, a[110];
    cin >> n;
    vector<PII> b;
    for(int i = n; i >= 0; i --) {
        cin >> a[i];
        if(a[i] == 0) continue;
        b.push_back({a[i], i});
    }
    for(int i = 0; i < b.size(); i ++) {
        int l = b[i].first, r = b[i].second;
        if(i != 0) {
            if (l > 0) printf("+");
            else printf("-");
        } else {
            if (l < 0) printf("-");
        }

        if(abs(l) != 1) printf("%d", abs(l));

        if(r == 1) {
            printf("x");
        } else {
            if (r != 0) printf("x^%d", r);
        }

        if(abs(l) == 1 && r == 0) printf("1");
    }
    return 0;
}