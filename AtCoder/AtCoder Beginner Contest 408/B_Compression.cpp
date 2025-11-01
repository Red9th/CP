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

int a[110], n;

int main() {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];
    sort(a, a + n);
    int p = unique(a, a + n) - a;

    cout << p << '\n';
    for(int i = 0; i < p; i ++) {
        cout << a[i] << ' ';
    }
    return 0;
}