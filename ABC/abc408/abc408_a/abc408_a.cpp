#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ll mod1 = 998244353;

int main() {
  int n, s;
	cin >> n >> s;
	vector<int> t(n);
	for(int i = 0; i < n; i++) cin >> t[i];

	string out = "Yes";
	int prev = 0;
	for(int i = 0; i < n; i++) {
		if(s < t[i] - prev) out = "No";
		prev = t[i];
	}

	cout << out << endl;
	return 0;
}