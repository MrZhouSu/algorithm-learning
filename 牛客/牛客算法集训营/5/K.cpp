#include <algorithm>
#include <bitset>
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

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;

  ll sum = 0;
  while (n / 2 + 1 != n) {
    n = n / 2 + 1;
    sum++;
  }

  cout << sum << endl;

  return (0 ^ 0);
}