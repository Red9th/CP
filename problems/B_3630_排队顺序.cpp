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

const int N = 10000000;
int n;
int list[N];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        list[i] = x;
    }
    int h;
    cin >> h;
    while(h != 0) {
        cout << h << " ";
        h = list[h];
    }
    return 0;
}