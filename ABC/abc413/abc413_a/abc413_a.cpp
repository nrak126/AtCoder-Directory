#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ll mod1 = 998244353;

int main() {
  int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[n];
	int sum = reduce(begin(a), end(a));
	cout << sum << endl;
	if(m >= sum) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}