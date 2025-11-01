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
string s;

int main() {
    int t;
    cin >> t;
    while(t --) {
        cin >> n >> s;
        for(int i = 0; i < n - 1; i ++) {
            if(s[i] > s[i + 1]) {
                int j = i;
                while(j < n && s[j] <= s[i]) j ++;
                s.insert(j, 1, s[i]);
                s.erase(i, 1);
                break;
            }
        }
        cout << s << endl;
    }
    return 0;
}