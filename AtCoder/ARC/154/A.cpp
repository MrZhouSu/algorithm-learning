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
ll n;
const int N = 2e5 + 10;
ll A[N], B[N];
ll flag;
const int MOD = 998244353;

ll quyu(ll C[]) {
  ll yushu = 0;
  for (ll i = 0; i < n; i++) {
    yushu *= 10;
    yushu = (yushu + C[i]) % MOD;
  }
  return yushu;
}

void Compare() {
  for (ll i = 0; i < n; i++) {
    if (A[i] > B[i]) {
      flag = 1;
      return;
    } else if (A[i] < B[i]) {
      flag = -1;
      return;
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n;
  string str;
  cin >> str;
  for (ll i = 0; i < n; i++) {
    A[i] = str[i] - '0';
  }
  cin >> str;
  for (ll i = 0; i < n; i++) {
    B[i] = str[i] - '0';
  }
  Compare();
  if (flag == 1) {
    for (ll i = 0; i < n; i++) {
      if (A[i] < B[i]) {
        swap(A[i], B[i]);
      }
    }
  } else if (flag == -1) {
    for (ll i = 0; i < n; i++) {
      if (A[i] > B[i]) {
        swap(A[i], B[i]);
      }
    }
  }
  ll a = quyu(A);
  ll b = quyu(B);
  cout << a * b % MOD << endl;
  return (0 ^ 0);
}
