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

int n, s, t[110];

int main() {
    cin >> n >> s;
    bool ok = true;
    for(int i = 1; i <= n; i ++) {
        cin >> t[i];
        if(t[i] - t[i - 1] > s + 0.5) ok = false;
    }
    if(ok) cout << "Yes";
    else cout << "No";
    return 0;
}