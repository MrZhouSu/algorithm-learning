#include <iostream>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
ll a[N];
int main(void) {
  ll t;

  cin >> t;

  while (t--) {
    ll n;
    cin >> n;

    if (n % 2 == 0) {
      for (ll i = n; i >= 1; i--) {
        cout << i << " \n"[i == 1];
      }
    }
    // 7 6 5 3 4 2 1
    // 9 8 7 6 4 5 3 2 1
    else {
      if (n == 3) {
        puts("-1");
      }
      // 5 4 1 2 3
      else if (n == 5) {
        puts("5 4 1 2 3");
      } else {
        for (ll i = n; i >= 1; i--) {
          if (i == n / 2 + 1) {
            cout << n / 2 << " " << n / 2 + 1 << " ";
            i--;
            continue;
          }
          cout << i << " \n"[i == 1];
        }
      }
    }
  }
  return 0;
}
