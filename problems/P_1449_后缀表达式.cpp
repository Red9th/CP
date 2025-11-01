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

string s;
stack<char> op;
stack<int> num;

int main() {
    cin >> s;
    string now_num = "";
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] >= '0' && s[i] <= '9') {
            now_num += s[i];
        } else if(s[i] == '.') {
            num.push(atoi(now_num.c_str()));
            now_num.clear();
        } else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            int a = num.top();
            num.pop();
            int b = num.top();
            num.pop();
            if(s[i] == '+') {
                num.push(b + a);
            } else if(s[i] == '-') {
                num.push(b - a);
            } else if(s[i] == '*') {
                num.push(b * a);
            } else if(s[i] == '/') {
                num.push(b / a);
            }
        } else if(s[i] == '@') {
            break;
        }
    }
    cout << num.top();
    return 0;
}