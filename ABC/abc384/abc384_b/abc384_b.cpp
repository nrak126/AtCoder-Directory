#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ll mod1 = 998244353;

int main() {
    int n, r;
    cin >> n >> r;

    for(int i = 0; i < n; i++) {
        int d, a;
        cin >> d >> a;
        switch(d) {
        case 1:
            if(1600 <= r && r <= 2799) {
                r += a;
            }
            break;
        case 2:
            if(1200 <= r && r <= 2399) {
                r += a;
            }
            break;
        }
    }

    cout << r << endl;
}