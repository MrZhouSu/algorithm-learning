#include <iostream>
#include <queue>
#include <unordered_map>
#define ll long long
using namespace std;

const int N = 1e5 + 10;

char str[N];

unordered_map<char, char> m;

bool check(char ch, char str) {
  for (auto &i : m) {
    if (i.second == ch) return false;
  }
  if (m.size() == 25) {
    return true;
  }
  while (m.count(ch)) {
    if (m[ch] == str) return false;
    ch = m[ch];
  }
  return true;
}

int main(void) {
  ll t;
  scanf("%lld", &t);

  while (t--) {
    ll n;
    scanf("%lld", &n);
    scanf("%s", str);
    m.clear();
    for (int i = 0; i < n; i++) {
      if (!m.count(str[i])) {
        for (char ch = 'a'; ch <= 'z'; ch++) {
          if (ch != str[i] && check(ch, str[i])) {
            m[str[i]] = ch;
            break;
          }
        }
      }
      str[i] = m[str[i]];
    }

    printf("%s\n", str);
  }
  return 0;
}
