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

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  string str;
  cin >> n >> str;
  bool flag = false;
  for (ll i = 0; i < n; i++) {
    if (str[i] == '"') {
      flag = !flag;
    }
    if (str[i] == ',' && !flag) {
      str[i] = '.';
    }
  }
  cout << str;
  return (0 ^ 0);
}
