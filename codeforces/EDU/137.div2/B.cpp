#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define ll long long
using namespace std;

int a[110];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;

    for (int i = 1; i <= n / 2; i++) {
      cout << i << " " << n - i + 1 << " ";
    }
    if (n & 1) {
      cout << n / 2 + 1;
    }
    cout << endl;
  }
  return 0;
}
