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
  string s, t;
  cin >> s >> t;
  bool flag = true;
  for (ll i = 0; i < s.size(); i++) {
    if (s[i] != t[i]) {
      cout << i + 1 << endl;
      flag = false;
      break;
    }
  }
  //   cout << s.size() << endl;
  if (flag) {
    cout << s.size() + 1 << endl;
  }

  return (0 ^ 0);
}
