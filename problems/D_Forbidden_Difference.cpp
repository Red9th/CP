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
#include <climits>
#include <unordered_map>
using namespace std;

int n, d, a[200010];
int f[200010][2];

int main() {
    cin >> n >> d;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    f[1][0] = f[1][1] = 0;
    for(int i = 2; i <= n; i ++) {
        if(abs(a[i] - a[i - 1]) != d) {
            f[i][0] = f[i - 1][0] + 1;
        }
        
    }

    return 0;
}