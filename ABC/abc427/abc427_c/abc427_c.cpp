#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ll mod1 = 998244353;

using Graph = vector<vector<int>>;

bool dfs(int c, int x, int X, Graph g[]) {
  X[c] = x;
  for (auto& d : g[c]) {
    if (X[d] == -1) {
      dfs(d, 1 - x);
    } else if (X[d] == X[c]) {
      return false;
    }
  }
}

int main() {
    int n, m;
    cin >> n >> m;

    Graph G(n);
		int X[n];
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        // 頂点 A から頂点 B への辺を張る
        G[a].push_back(b);

        // 無向グラフの場合は次も実施
        G[b].push_back(a);
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j <= i; j++) {

				}
    }
}