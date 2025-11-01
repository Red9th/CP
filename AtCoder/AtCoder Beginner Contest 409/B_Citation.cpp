#define LL long long
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

int n;
int a[110];

int main() {
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a, a + n);

    for(int x = n; x >= 0; x --) {
        int cnt = 0;
        for(int i = 0; i < n; i ++) {
            if(a[i] >= x) cnt ++;
        }
        if(cnt >= x) {
            cout << x << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}