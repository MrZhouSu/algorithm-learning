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

const int N = 110;

ll V[N];
ll W[N];

bool st[N];

ll dp[N], dpp[N];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  ll maxid = 0;

  for (ll i = 0; i < n; i++) {
    cin >> V[i] >> W[i];
    maxid = max(maxid, W[i]);
  }

  for (ll i = 0; i < n; i++) {
    for (ll j = m; j >= V[i]; j--) {
      dp[j] = max(dp[j], dp[j - V[i]] + W[i]);
    }
  }

  ll valmax = dp[m];

  for (ll i = 0; i < n; i++) {
    memset(dp, 0, sizeof dp);
    memset(dpp, 0, sizeof dpp);
    for (ll j = 0; j < n; j++) {
      if (j == i) {
        continue;
      } else {
        for (ll k = m; k >= V[j]; k--) {
          dpp[k] = max(dpp[k], dpp[k - V[j]] + W[j]);
        }
        for (ll k = m; k >= V[j]; k--) {
          dp[k] = max(dp[k], dp[k - V[j]] + W[j]);
        }
      }
    }
    for (ll k = m; k >= V[i]; k--) {
      dp[k] = dp[k - V[i]] + W[i];
    }
    if (dpp[m] < valmax) {
      cout << 0 << endl;
    } else {
      cout << valmax - dp[m] + 1 << endl;
    }
  }

  return (0 ^ 0);
}
