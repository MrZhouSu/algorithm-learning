#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define ll long long
using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int q;
    cin >> q;
    bool flag = true;
    bool aflag = true;
    ll sizea = 1, sizeb = 1;
    while (q--) {
      int a, b;
      string c;
      cin >> a >> b >> c;
      if (!flag) {
        cout << "YES" << endl;
        continue;
      }
      int n = c.size();
      if (a == 1) {
        sizea += b * n;
        for (int i = 0; i < n; i++) {
          if (c[i] != 'a') {
            aflag = false;
            break;
          }
        }
        if (aflag) {
          if (sizea < sizeb) {
            cout << "YES" << endl;
          } else {
            cout << "NO" << endl;
          }
        } else {
          cout << "NO" << endl;
        }
      } else {
        sizeb += b * n;
        for (int i = 0; i < n; i++) {
          if (c[i] != 'a') {
            flag = false;
            cout << "YES" << endl;
            break;
          }
        }
        if (flag) {
          if (aflag) {
            if (sizea < sizeb) {
              cout << "YES" << endl;
            } else {
              cout << "NO" << endl;
            }
          } else {
            cout << "NO" << endl;
          }
        }
      }
    }
  }
  return 0;
}
