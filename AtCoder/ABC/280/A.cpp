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
  ll h, w;
  cin >> h >> w;
  string s;
  ll sum = 0;
  while (h--) {
    cin >> s;
    for (ll i = 0; i < s.size(); i++) {
      if (s[i] == '#') sum++;
    }
  }
  cout << sum << endl;
  return (0 ^ 0);
}
