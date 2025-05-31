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
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll x = 0;
  ll flag = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] != x) {
      x = a[i];
      flag = 1;
    }else{
      flag++;
    }

    if(flag == 3) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}