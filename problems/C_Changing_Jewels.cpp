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

LL r[11], b[11];

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    b[1] = 1;
    for(int i = 2; i <= 10; i ++) {
        b[i] = r[i - 1] + y * b[i - 1];
        r[i] = r[i - 1] + x * b[i];
    }
    cout << r[n];
    return 0;
}