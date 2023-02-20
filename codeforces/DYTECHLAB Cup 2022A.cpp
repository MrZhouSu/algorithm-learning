#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long
namespace fast_IO {
ll read() {
  ll num = 0;
  char c;
  bool tag = false;
  while ((c = getchar()) != '-' && c != '+' && (c < '0' || c > '9') && ~c)
    ;
  if (!~c) return EOF;
  if (c == '-')
    tag = true;
  else if (c == '+')
    tag = false;
  else
    num = c ^ 48;
  while ((c = getchar()) >= '0' && c <= '9')
    num = (num << 1) + (num << 3) + (c ^ 48);
  if (tag) return -num;
  return num;
}
void write(ll x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 ^ 48);
}
}  // namespace fast_IO

ll t;

ll n, k;

const int N = 210;

char str[N];

int zimu[30];

int main(void) {
  t = fast_IO::read();

  while (t--) {
    n = fast_IO::read();
    k = fast_IO::read();

    int x = n / k;

    memset(zimu, 0, sizeof zimu);

    char ch;

    for (int i = 0; i < n; i++) {
      cin >> ch;
      zimu[ch - 'a']++;
    }
    string s;
    // for (int i = 0; i < 26; i++)
    // {
    //     cout << zimu[i] << endl;
    // }
    for (int i = 0; i < k; i++) {
      int p = 0;
      bool flag = true;
      int x1 = x;
      while (x1--) {
        if (zimu[p] != 0) {
          zimu[p]--;
        } else if (flag) {
          s += 'a' + p;
          flag = false;
        }
        p++;
      }
      if (flag) s += 'a' + p;
    }
    cout << s << endl;
  }
  return 0;
}
