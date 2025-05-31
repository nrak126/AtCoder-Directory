#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;
const ll mod1 = 998244353;

#include <ranges>

int main() {
    int n = 5;

    vector<int> points(n);
    for(auto &&p : points) {
        cin >> p;
    }

    vector<pair<int, string>> scores;
    for(int i = 0; i < (1 << n); i++) {
        int solved_point = 0;
        string name = "";
        for(int j = 0; j < 5; j++) {
            if(i & 1 << j) {
                solved_point += points[j];
                name += "ABCDE"[j];
            }
        }
        scores.emplace_back((solved_point, name));
    }

    ranges::
}