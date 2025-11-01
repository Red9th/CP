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
string t, a;

int main() {
    cin >> n >> t >> a;
    bool ok = false;
    for(int i = 0; i < n; i ++) {
        if(t[i] == 'o' && a[i] == 'o') {
            ok = true;
            break;
        }
    }
    if(ok) cout << "Yes";
    else cout << "No";
    return 0;
}