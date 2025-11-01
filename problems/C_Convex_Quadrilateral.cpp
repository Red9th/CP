#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

#define x first
#define y second
#define LL long long
#define PII pair<int, int>

int x[4], y[4];

bool check(int a, int b, int c) {
    int res = (x[b] - x[a]) * (y[c] - y[a]) - (y[b] - y[a]) * (x[c] - x[a]);
    if(res <= 0) return false;
    return true;
}

int main() {
    for(int i = 0; i < 4; i ++) {
        cin >> x[i] >> y[i];
    }
    int a = 0, b = 1, c = 2;
    for(int i = 0; i < 4; i ++) {
        if(!check(a, b, c)) {
            cout << "No";
            return 0;
        }
        a = (a + 1) % 4;
        b = (b + 1) % 4;
        c = (c + 1) % 4;
    }
    cout << "Yes";
    return 0;
}