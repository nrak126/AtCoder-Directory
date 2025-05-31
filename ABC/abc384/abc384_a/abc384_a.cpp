#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ll mod1 = 998244353;

int main() {
    int n;
    string s;
    char c1, c2;
    cin >> n >> c1 >> c2;
    cin >> s;

    for(int i = 0; i < n; i++) {
        if(s[i] != c1) {
            s[i] = c2;
        }
    }

    cout << s << endl;
}
