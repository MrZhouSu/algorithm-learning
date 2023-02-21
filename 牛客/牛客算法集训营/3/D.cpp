#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>  //iota
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define ll long long
using namespace std;

ll sum = 0;

void divide(ll x) {
  for (ll i = 2; i <= x / i; i++)
    while (x % i == 0) {
      x /= i;
      sum++;
    }
  if (x > 1) sum++;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  //   cout << "kou" << endl;
  //   cout << sum << endl;
  if (n & 1) {
    cout << "yukari" << endl;
  } else {
    cout << "kou" << endl;
  }
  return (0 ^ 0);
}