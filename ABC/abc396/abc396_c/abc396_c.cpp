#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ll mod1 = 998244353;

int main() {
  ll n, m;
	vector<ll> b(n), w(m);
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < n; i++) cin >> w[i];

	sort(b.rbegin(), b.rend());
	sort(w.rbegin(), w.rend());

	vector<ll> s(n + 1), t(m + 1), max_t(m + 1);

	for(int i = 0; i < n; i++) {
		s[i + 1] = s[i] + b[i];
	}
	for(int i = 0; i < m; i++) {
		s[i + 1] = s[i] + w[i];
		max_t[i + 1] = max(max_t[i], t[i + 1]);
	}

	ll ans = 0;
	for(int i = 0; i < n + 1; i++) {
		ans = max(ans, s[i] + max_t[min(i, m)]);
	}
	cout << ans << endl;
	return 0;
}