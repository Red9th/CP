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

int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};

#define x first
#define y second
#define LL long long
#define PII pair<int, int>

int m;
string n;
vector<PII> f;

int main() {
    cin >> m >> n;
    int t = n.size() - 1;
    for(int i = 0; i < n.size(); i ++) {
        if(n[i] != '0') {
            f.push_back({n[i] - '0', t});
        }
        t --;
    }
    for(int i = 0; i < f.size(); i ++) {
        cout << f[i].first << "*" << m << "^" << f[i].second;
        if(i < f.size() - 1) cout << "+";
    }
    return 0;
}