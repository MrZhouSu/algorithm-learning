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

const int N = 1e5 + 10;
unordered_map<string, string> p;
string find(string& x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}
vector<string> vstr1, vstr2;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  bool flag = true;
  for (ll i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    vstr1.push_back(a);
    vstr2.push_back(b);
  }
  for (ll i = 0; i < n; i++) {
    p[vstr1[i]] = vstr1[i];
    p[vstr2[i]] = vstr2[i];
  }

  for (ll i = 0; i < n; i++) {
    string pa = find(vstr1[i]);
    string pb = find(vstr2[i]);
    if (pa == pb) {
      flag = false;
      break;
    } else {
      p[pa] = pb;
    }
  }
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return (0 ^ 0);
}
