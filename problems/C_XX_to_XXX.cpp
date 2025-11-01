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

int a[300], b[300];

int main() {
    string s, t;
    cin >> s >> t;
    char now = s[0];
    int j = 0;
    for(int i = 0; i < s.size();) {
        now = s[i];
        int ls = 0, lt = 0;
        while(now == s[i]) i ++, ls ++;
        while(now == t[j]) j ++, lt ++;
        if(ls == lt) continue;
        else if(ls > lt) {
            cout << "No" << '\n';
            return 0;
        } else {
            if(ls == 1) {
                cout << "No" << '\n';
                return 0;
            }
        }
    }
    if(j >= t.size()) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
    return 0;
}