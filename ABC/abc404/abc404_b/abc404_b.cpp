#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ll mod1 = 998244353;

int main() {
  int n;
	cin >> n;
	vector<vector<char> > s(n, vector<char>(n)), t(n, vector<char>(n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> s[i][j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> t[i][j];

	vector<int> move_cnt(4, 0);

	for(int i = 0; i < 4; i++) {
		move_cnt[i] += i;
		for(int y = 0; y < n; y++) {
			for(int x = 0; x < n; x++) {
				int sx = x, sy = y, tx = x, ty = y;
				// for(int j = 0; j < i; j++) {
				// 	int temp = sx;
				// 	sx = sy;
				// 	sy = n - temp - 1;
				// }
				if(i == 0) sx = x, sy = y;
				if(i == 1) sx = n - 1 - y, sy = x;
				if(i == 2) sx = n - 1 - x, sy = n - 1 - y;
				if(i == 3) sx = y, sy = n - 1 - x;
				if(s[sx][sy] != t[tx][ty]) move_cnt[i]++;
			}
		}
	}
	int min_cnt = move_cnt[0];
	for(int i = 0; i < 4; i++) {
		if(min_cnt > move_cnt[i]) min_cnt = move_cnt[i];
	}

	cout << min_cnt << endl;
	return 0;
}