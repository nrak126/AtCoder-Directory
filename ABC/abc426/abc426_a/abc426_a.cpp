#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ll mod1 = 998244353;

int main() {
    string x, y;
    cin >> x >> y;
    vector<string> v = {"Ocelot", "Serval", "Lynx"};
    int ix = 0, iy = 0;
    for(int i = 0; i < 3; i++) {
        if(v[i] == x)
            ix = i;
        if(v[i] == y)
            iy = i;
    }
    if(ix >= iy)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}