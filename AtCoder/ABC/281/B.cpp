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
  if (str.size() != 8) {
    cout << "No" << endl;
    return 0;
  } else if (str[0] > 'Z' || str[0] < 'A') {
    cout << "No" << endl;
    return 0;
  } else if (str[str.size() - 1] > 'Z' || str[str.size() - 1] < 'A') {
    cout << "No" << endl;
    return 0;
  }
  for (ll i = 1; i < str.size() - 1; i++) {
    if (str[i] > '9' || str[i] < '0') {
      cout << "No" << endl;
      return 0;
    }
  }
  if (str[1] == '0') {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return (0 ^ 0);
}
