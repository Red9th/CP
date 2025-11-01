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

int q;
map<int, int> list;

int main() {
    cin >> q;
    list[1] = -1;
    while(q --) {
        int op, x, y;
        cin >> op;
        if(op == 1) {
            cin >> x >> y;
            list[y] = list[x];
            list[x] = y;
        } else if(op == 2) {
            cin >> x;
            if(list[x] == -1) {
                cout << "0\n";
            } else {
                cout << list[x] << '\n';
            }
        } else {
            cin >> x;
            int a = list[x];
            if(a == -1) continue;
            int b = list[a];
            list[x] = b;
        }
    }
    return 0;
}