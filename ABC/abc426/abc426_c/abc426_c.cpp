#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ll mod1 = 998244353;

int main() {
	struct pc{
		int i;
		int n;
	};
	vector<pc> pcs;
    ll n, q;
    cin >> n, q;
    vector<ll> x(q), y(q);
		int nothing_i;
    for(int i = 0; i < q; i++)
        cin >> x[i] >> y[i];
		for(int i = 0; i < q; i++) {
			int c;
			nothing_i = x[i];
			c = x[i];
			cout << c << endl;
		}
		return 0;
}