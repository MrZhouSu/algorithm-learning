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
ll n;
ll a[N];
ll cnt[N];
ll d[N];
// ll visit[N];

void solved() {
  cin >> n;
  ll maxid = 0;
  memset(cnt, 0, sizeof cnt);
  memset(d, 0, sizeof d);
  //   memset(visit, 0, sizeof visit);
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    d[cnt[a[i]]]++;
    d[cnt[a[i]] - 1]--;
  }
  //   visit[N - 1] = 0;
  //   for (ll i = N - 2; i >= 0; i--) {
  //     if (d[i]) {
  //       visit[i] = visit[i + 1] + d[i];
  //     } else {
  //       visit[i] = visit[i + 1];
  //     }
  //   }
  d[0] = -d[0];
  ll sum = 0;
  for (ll i = 1; i <= n; i++) {
    sum += d[i] * i;
    d[0] -= d[i];
    // if (visit[i + 1] == 0 || n - sum <= i) {
    //   cout << n << endl;
    // } else {
    cout << min(sum + d[0] * (i - 1), n) << endl;
    // }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;

  while (t--) solved();

  return (0 ^ 0);
}