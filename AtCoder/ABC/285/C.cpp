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
  string str;
  cin >> str;
  ll sum = 0;
  for (ll i = 0; i < str.size(); i++) {
    sum = sum * 26 + str[i] - 'A' + 1;
  }
  cout << sum << endl;

  return (0 ^ 0);
}
