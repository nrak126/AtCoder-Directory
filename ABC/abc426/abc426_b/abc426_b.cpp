#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ll mod1 = 998244353;

int main() {
    string s;
    cin >> s;
    int i = 1;
    sort(s.rbegin(), s.rend());
    if(s[0] == s[1])
        cout << s.back() << endl;
    else
        cout << s[0] << endl;
    return 0;
}