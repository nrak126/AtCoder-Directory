#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ll mod1 = 998244353;

int main() {
  string s;
	cin >> s;
	vector<int> count_alphabet(26, 0);

	for(auto &c : s) {
		count_alphabet[c - 'a']++;
	}
	for(int i = 0; i < count_alphabet.size(); i++) {
		if(count_alphabet[i] == 0) {
			cout << (char) (i + 'a') << endl;
			break;
		};
	}
	return 0;
}