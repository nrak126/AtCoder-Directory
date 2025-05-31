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

  stack<ll> s;
	for(int i = 0; i < 100; i++) {
		s.push(0);
	}

	int c, x;
	for(int i = 0; i < n; i++) {
		cin >> c;
		if(c == 1) {
			cin >> x;
			s.push(x);
		}else {
			cout << s.top() << endl;
			s.pop();
		}
	}
	return 0;
}