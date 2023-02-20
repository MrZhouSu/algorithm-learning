#include <iostream>
#include <string>
#include <unordered_map>
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
int main(void) {
  int t;
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  cin >> t;
  // cout.tie(0);
  string str1, str2;
  while (t--) {
    cin >> str1 >> str2;

    ll n1 = str1.size();

    ll n2 = str2.size();

    if (str1[n1 - 1] == str2[n2 - 1]) {
      if (n1 > n2) {
        if (str1[n1 - 1] == 'L')
          cout << ">" << endl;
        else if (str1[n1 - 1] == 'S')
          cout << "<" << endl;
        else
          cout << "=" << endl;
      } else if (n1 == n2) {
        cout << "=" << endl;
      } else {
        if (str1[n1 - 1] == 'L')
          cout << "<" << endl;
        else if (str1[n1 - 1] == 'S')
          cout << ">" << endl;
        else
          cout << "=" << endl;
      }
    } else {
      if (str1[n1 - 1] < str2[n2 - 1]) {
        cout << ">" << endl;
      } else {
        cout << "<" << endl;
      }
    }
  }

  return 0;
}
