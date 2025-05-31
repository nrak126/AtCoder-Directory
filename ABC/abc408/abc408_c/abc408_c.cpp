#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ll mod1 = 998244353;

int main() {
  ll n, m;
	cin >> n >> m;
	vector<ll> l(m), r(m), wall(n, 0);
	for(ll i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
		l[i]--;
		r[i]--;
	};

	ll min_l = 0;
	ll max_r = LLONG_MAX;
	for(ll i = 0; i < m; i++){
		wall[l[i]]++;
		if(r[i] + 1 > n) continue;
		wall[r[i] + 1]--;
	};
	for(ll i = 1; i < n; i++){
		wall[i] += wall[i - 1];
	};
	ll min_val = *min_element(begin(wall), end(wall));
	cout << min_val << endl;
}