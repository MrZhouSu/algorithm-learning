#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

const int N = 2e5 + 10;

struct w {
  int val;
  int xuhao;
} a[N];

bool cmp1(w &c, w &b) { return c.val > b.val; }

bool cmp2(w &c, w &b) { return c.xuhao < b.xuhao; }

int main(void) {
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  int t;
  cin >> t;
  getchar();
  int p;
  char ch;
  while (t--) {
    int line = 0;
    int ans = 0;
    while ((ch = getchar()) && ch != '\n') {
      a[line].val = ch - 'a' + 1;
      a[line].xuhao = line + 1;
      ans += a[line].val;
      line++;
    }
    cin >> p;
    getchar();
    sort(a, a + line, cmp1);
    int lines = line;
    for (int i = 0; i < line; i++) {
      if (ans <= p) {
        lines = i;
        break;
      }
      ans -= a[i].val;
    }
    sort(a + lines, a + line, cmp2);
    for (int i = lines; i < line; i++) {
      cout << char(a[i].val + 'a' - 1);
    }
    cout << endl;
  }
  return 0;
}
