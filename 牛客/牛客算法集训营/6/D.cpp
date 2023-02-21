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

const int N = 2e5 + 10;

ll U[N], D[N], UD[N], DU[N];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string str;
  cin >> str;

  ll n = str.size();

  ll sumu = 0;
  ll sumd = 0;
  ll sumud = 0;
  ll sumdu = 0;

  for (ll i = 0; i < n; i++) {
    U[i] = sumu;
    D[i] = sumd;
    UD[i] = sumud;
    if (str[i] == 'u') {
      sumu++;
    } else if (str[i] == 'd') {
      sumd++;
      sumud += sumu;
    }
  }
  ll ssu = 0;
  for (ll i = n - 1; i >= 0; i--) {
    DU[i] = sumdu;
    if (str[i] == 'd') {
      sumdu += ssu;
    } else if (str[i] == 'u') {
      ssu++;
    }
  }

  ll id = 0;
  ll maxid = 0;

  //   for (ll i = 0; i < n; i++) {
  //     cout << U[i] << " " << D[i] << " " << DU[i] << " " << UD[i] << endl;
  //   }

  for (ll i = 0; i < n; i++) {
    if (str[i] == 'd') {
      ll sum = U[i] * (sumu - U[i]);
      if (sum > maxid) {
        id = i;
        maxid = sum;
      }
    } else if (str[i] == 'u') {
      ll sum = UD[i] + DU[i];
      if (sum > maxid) {
        id = i;
        maxid = sum;
      }
    }
  }

  str[id] = 'a';

  cout << str << endl;
  return (0 ^ 0);
}