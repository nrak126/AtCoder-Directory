#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ll mod1 = 998244353;

int main() {
  ll n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			sum += a[i] * a[j];
		}
	}
	cout << sum << endl;
	return 0;
}