#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ll mod1 = 998244353;

int f_func(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    int sum = 1;
    for(int i = 0; i < n - 1; i++) {
        sum += f_func(sum);
    }

    cout << sum << endl;
    return 0;
}
